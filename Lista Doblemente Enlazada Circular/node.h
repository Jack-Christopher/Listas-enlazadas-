
template <class N>
class Node
{
	N elem;
	Node *prev;
	Node *next;
		
	public:
		Node(); 
		Node(N elem);
		N getElem() const;
		void setElem(const N elemento);
		Node *getNext() const;
		Node *getPrev() const;
		void setNext(Node *n);
		void setPrev(Node *n);
		
};

template <class N>
Node<N>::Node()
{
	elem = nullptr;
	prev = nullptr;
	next = nullptr;
}


template <class N>
Node<N>::Node(N elemento)
{
	elem = elemento;
	prev = nullptr;
	next = nullptr;
}

template <class N>
N Node<N>::getElem() const
{
	return elem;
}

template <class N>
void Node<N>::setElem(const N elemento) 
{
	elem = elemento;
}

template <class N>
Node<N>* Node<N>::getNext() const
{
	return next;
}

template <class N>
Node<N>* Node<N>::getPrev() const
{
	return prev;
}

template <class N>
void Node<N>::setNext(Node *n)
{
	next = n;
}

template <class N>
void Node<N>::setPrev(Node *n)
{
	prev = n;
}