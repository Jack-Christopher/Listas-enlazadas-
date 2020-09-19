
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "node.h"
#include "doublelinkedlist.h"

using namespace std;

int main()
{
	//Se declara un objeto de clase LinkedList
	DoubleLinkedList<int> l1;
		
	//Se insertan los elementos en l1
	/* 
	l1.insertar(23,0);
	l1.insertar(65,0);
	l1.insertar(34,0);
	l1.insertar(64,0);
	l1.insertar(34,0);
	l1.insertar(87,0);
	l1.insertar(54,0);
	l1.insertar(48,20);
	*/


	l1.generarNumeros();

	cout<< "La lista de elementos es: "<<endl;
	l1.print();
	
	//Se elimina los elementos de los indices 4 y 2 
	l1.remover(3);
	l1.remover(1);
	l1.remover(20);
	cout<<"\nLos elementos de las posiciones 3 y 1 han sido eliminados "<<endl;
	cout<< "La nueva lista de elementos es: "<<endl;
	l1.print();	

	cout<< "El valor 34 esta en la posicion: " << l1.buscar(34)<< endl;
	cout<< "El valor 100 esta en la posicion: "<< l1.buscar(100)<< endl;
	
	
	return 0;
}