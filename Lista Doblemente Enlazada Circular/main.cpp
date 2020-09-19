
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime> 
#include "node.h"
#include "doublecircularlinkedlist.h"

int main()
{
	//Se declara un objeto de clase LinkedList
	DoubleCircularLinkedList<int> l1;
		
	//Se insertan los elementos en l1
	l1.insertar(106,0);
	l1.insertar(105,0);
	l1.insertar(104,0);
	l1.insertar(1000,0);
	l1.insertar(100,0);

	std::cout<< "La lista de elementos es: "<<std::endl;
	//l1.print();
	l1.insertarAleatoriamente();
	l1.print();
	l1.removerAleatoriamente();
	l1.print();

	l1.buscarAleatoriamente();

	/*
	long double t0, t1;
	t0=clock();
	
	for (int k = 0; k < 100; k++)
	{
		l1.insertar(39,0);
	}
	

	t1 = clock();
  
	long double time = ( (t1-t0)*1000000000000000/CLOCKS_PER_SEC);
	std::cout << "Tiempo de ejecucion: " << time << std::endl;*/

	return 0;
}