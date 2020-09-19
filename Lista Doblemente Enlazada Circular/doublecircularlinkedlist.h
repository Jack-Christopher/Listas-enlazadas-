
template <class L>
class DoubleCircularLinkedList
{
	int size;
	Node<L> *head;
		
	public:
		DoubleCircularLinkedList();
		DoubleCircularLinkedList(const DoubleCircularLinkedList &copia);

		void insertar(const L valor, int pos);
		void remover(const int pos);
		int buscar(const L valor);
		void generarNumeros();
		void insertarAleatoriamente();
		void removerAleatoriamente();
		void buscarAleatoriamente();
		
		void print();
				
		~DoubleCircularLinkedList();
};

// CONSTRUCTORES ----------------------------------------------------------------------------

//Constructor por defecto
template <class L>
DoubleCircularLinkedList<L>::DoubleCircularLinkedList()
{
	head = nullptr;
	size = 0;
}

//Constructor copia
template <class L>
DoubleCircularLinkedList<L>::DoubleCircularLinkedList(const DoubleCircularLinkedList &copia)
{
	size = copia.size;
	head  = copia.head; 
}


//PRINT ----------------------------------------------------------------------------------------
template <class L>
void DoubleCircularLinkedList<L>::print()
{
	//Se itera sobre todos los elementos y se imprimen sus datos miembro
	Node<L> *puntero = head;
	int k = 0;
	do
	{
		std::cout<< "Posicion "<< k<< ": "<< puntero->getElem()<< std::endl;
        puntero = puntero->getNext();
        k++;
	} 
	while ( puntero != head );	
}

// INSERT -----------------------------------------------------------------------------------------
template <class L>
void DoubleCircularLinkedList<L>::insertar(const L valor, int pos)
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
				head->setPrev(head);
				head->setNext(head);
				size++;
				return;
			}
			else
			{
				Node<L> *temp = head->getPrev();
				temp->setNext(new_node);
	        	new_node->setNext(head);
				new_node->setPrev(temp);
				head->setPrev(new_node);
        		head = new_node;
				size++;
        		return;
			}
    	}

    	pos--;
	
	    Node<L> *puntero = head;
		do
		{
			puntero = puntero->getNext();
		}
		while ( puntero != head && pos--);	
    	
		if(puntero->getNext() == head)
		{
			head->setPrev(new_node);
	        new_node->setPrev(puntero);
			new_node->setNext(head);
			puntero->setNext(new_node);
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
void DoubleCircularLinkedList<L>::remover(const int pos)
{
	int posicion = pos;
	
	if(posicion == 0 )
    {
		if (size == 0) { return; }

        Node<L> *temp = head;
        head = head->getNext();
		temp->getPrev()->setNext(head);
		head->setPrev(temp->getPrev());
        delete temp;
    }
	else
	{
		posicion--;
    	Node<L> *puntero = head;

		while ( puntero->getNext() != head && posicion--);	
		{
			puntero = puntero->getNext();
		}

	    if(puntero->getNext()== head && posicion > 0)  return;

	    Node<L> *temp = puntero->getNext();
    	puntero->setNext(temp->getNext());
		temp->getNext()->setPrev(puntero);
		delete temp;
	}
	size--;
}

// SEARCH --------------------------------------------------------------------------------
template <class L>
int DoubleCircularLinkedList<L>::buscar(const L valor)
{
	Node<L> * temp = head;
	int contador = 0;
	do
	{
		if (temp->getElem() == valor)
		{
			return contador;
		}
		temp = temp->getNext();
		contador++;
		
	} while (temp != head);
	
	return -1;
}

// GENERATE ------------------------------------------------------------------------------
template <class L>
void DoubleCircularLinkedList<L>::generarNumeros()
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

//INSERT RANDOM  ---------------------------------------------------------------------------------

template <class L>
void DoubleCircularLinkedList<L>::insertarAleatoriamente()
{
	srand(time(NULL));
	L num;
	int pos;
	
	for (int k = 0; k < 10; k++ )
	{
		num = rand();
		pos = rand()%size ;
		insertar(num, pos);
	}
}


// REMOVE RANDOM   ---------------------------------------------------------------------------------

template <class L>
void DoubleCircularLinkedList<L>::removerAleatoriamente()
{
	srand(time(NULL));
	int pos;
	
	for (int k = 0; k < 10; k++ )
	{
		pos = rand()%size ;
		remover( pos);
	}

}



// SEARCH RANDOM   ---------------------------------------------------------------------------------

template <class L>
void DoubleCircularLinkedList<L>::buscarAleatoriamente()
{
	srand(time(NULL));
	L numero;

	for (int k = 0; k < 100; k++)
	{
		numero= rand();
		std::cout<< buscar(numero) <<std::endl;
	}
}





//Destructor -----------------------------------------------------------------------------
template <class L>
DoubleCircularLinkedList<L>::~DoubleCircularLinkedList()
{
	Node<L> *puntero = head;

	Node<L> *siguiente = nullptr;
	
	//Se libera la memoria asignada con new
	do
	{
		siguiente = puntero->getNext();
        delete puntero;
        puntero = siguiente;
		size--;
		
	} while (size);

}