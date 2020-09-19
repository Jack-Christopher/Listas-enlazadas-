
template <class L>
class LinkedList
{
	int size;
	Node<L> *head;
		
	public:
		LinkedList();
		LinkedList(const LinkedList &copia);

		void insertar(const L valor, int pos);
		void remover(const int pos);
		int buscar(const L valor);
		void generarNumeros();
		void print();
				
		~LinkedList();
};

// CONSTRUCTORES ----------------------------------------------------------------------------

//Constructor por defecto
template <class L>
LinkedList<L>::LinkedList()
{
	head = nullptr;
	size = 0;
}

//Constructor copia
template <class L>
LinkedList<L>::LinkedList(const LinkedList &copia)
{
	size = copia.size;
	head  = copia.head;
}


//PRINT ----------------------------------------------------------------------------------------
template <class L>
void LinkedList<L>::print()
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
void LinkedList<L>::insertar(const L valor, int pos)
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
		}
		else
		{
			new_node->setNext(puntero->getNext());
	    	puntero->setNext(new_node);
		}
		size++;
	}
}


// REMOVE --------------------------------------------------------------------------------------
template <class L>
void LinkedList<L>::remover(const int pos)
{
	int posicion = pos;
	
	if(posicion == 0 )
    {
        Node<L> *temp = head;
        head = head->getNext();
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
		delete temp;
	}
	size--;
}

// SEARCH --------------------------------------------------------------------------------
template <class L>
int LinkedList<L>::buscar(const L valor)
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
void LinkedList<L>::generarNumeros()
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
LinkedList<L>::~LinkedList()
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