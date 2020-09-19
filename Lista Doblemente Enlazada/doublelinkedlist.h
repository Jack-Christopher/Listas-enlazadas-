
template <class L>
class DoubleLinkedList
{
	int size;
	Node<L> *head;
		
	public:
		DoubleLinkedList();
		DoubleLinkedList(const DoubleLinkedList &copia);

		void insertar(const L valor, int pos);
		void remover(const int pos);
		int buscar(const L valor);
		void generarNumeros();
		void print();
				
		~DoubleLinkedList();
};

// CONSTRUCTORES ----------------------------------------------------------------------------

//Constructor por defecto
template <class L>
DoubleLinkedList<L>::DoubleLinkedList()
{
	head = nullptr;
	size = 0;
}

//Constructor copia
template <class L>
DoubleLinkedList<L>::DoubleLinkedList(const DoubleLinkedList &copia)
{
	size = copia.size;
	head  = copia.head; 
}


//PRINT ----------------------------------------------------------------------------------------
template <class L>
void DoubleLinkedList<L>::print()
{
	//Se itera sobre todos los elementos y se imprimen sus datos miembro
	Node<L> *puntero = head;
	int k = 0;
	while(puntero)
    {
    	std::cout<< "Posicion "<< k<< ": "<< puntero->getElem()<< std::endl;
        puntero = puntero->getNext();
        k++;
    }
}

// INSERT -----------------------------------------------------------------------------------------
template <class L>
void DoubleLinkedList<L>::insertar(const L valor, int pos)
{
	if (pos < 0)
	{
		std::cout<< "Ingrese una posicion valida"<< std::endl;
		int new_position;
		std::cin>> new_position;
		insertar( valor, new_position);

	}
	else
	{	

		Node<L> *new_node = new Node<L>(valor);
	
		if(pos==0)
    	{
			if (size == 0) 
			{
				head = new_node;
				size++;
				return;
			}
			else
			{
	        	new_node->setNext(head);
				head->setPrev(new_node);
        		head = new_node;
        		return;
			}
    	}
		
    	pos--;
	
	    Node<L> *puntero = head;
	    while(puntero->getNext() != nullptr && --pos)
	    {
        	puntero = puntero->getNext();
    	}
	
	    if(puntero->getNext() == nullptr)
		{
			puntero->setNext( new_node);
			new_node->setPrev(puntero);
		}
		else
		{
			new_node->setPrev(puntero);
			new_node->setNext(puntero->getNext());
	    	puntero->setNext(new_node);
			new_node->getNext()->setPrev(new_node);
		}
		size++;
	}
}


// REMOVE --------------------------------------------------------------------------------------
template <class L>
void DoubleLinkedList<L>::remover(const int pos)
{
	int posicion = pos;
	
	if(posicion == 0 )
    {
        Node<L> *temp = head;
        head = head->getNext();
		head->getPrev()->setNext(nullptr);
		head->setPrev(nullptr);
        delete temp;
    }
	else
	{
    	Node<L> *puntero = head;
    	while(puntero->getNext()!=nullptr && --posicion)
	       	puntero = puntero->getNext();

	    if(puntero->getNext()==nullptr && posicion > 0)  return;

	    Node<L> *temp = puntero->getNext();
    	puntero->setNext(temp->getNext());
		temp->getNext()->setPrev(puntero);
		temp->setNext(nullptr);
		temp->setPrev(nullptr);
		delete temp;
	}
	size--;
}

// SEARCH --------------------------------------------------------------------------------
template <class L>
int DoubleLinkedList<L>::buscar(const L valor)
{
	Node<L> * temp = head;
	int contador = 0;
	while(temp != nullptr)
	{
		if (temp->getElem() == valor)
		{
			return contador;
		}
		temp = temp->getNext();
		contador++;
	}
	return -1;
}

// GENERATE ------------------------------------------------------------------------------
template <class L>
void DoubleLinkedList<L>::generarNumeros()
{
	int cantidad;
	std::cout<< "Ingresa el numero de elementos que va a tener de la lista: ";
	std::cin>> cantidad;
	srand(time(NULL));
	L num;
	
	for (int k = 0; k < cantidad; k++ )
	{
		num = rand();
		insertar(num, size);
	}
}

//Destructor -----------------------------------------------------------------------------
template <class L>
DoubleLinkedList<L>::~DoubleLinkedList()
{
	Node<L> *puntero = head;
	Node<L> *siguiente2 = nullptr;
	
	//Se libera la memoria asignada con new
	while(puntero != nullptr)
    {
        siguiente2 = puntero->getNext();
        delete puntero;
        puntero = siguiente2;
    }
}