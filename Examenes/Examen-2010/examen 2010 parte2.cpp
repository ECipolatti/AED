#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
#include "util.h"
#include "util_tree.h"
#include "tree.h"
#include "btree.h"


using namespace aed;


//	a) [list2tree (20pt)] Recordemos que serializar una estructura de datos consiste en convertir esa
//	estructura en una secuencia de bytes, tal que de esa forma pueda almacenarse en disco o tansmitirse
//	por red para despues ser reconstruida. Hemos visto que para serializar un arbol podemos usar la
//	notacion LISP o bien la combinacion de listados en orden previo y posterior del arbol. Otra
//	posibilidad consiste en generar una lista donde por cada nodo n listamos, en orden previo, el valor
//	contenido en el mismo y su cantidad de hijos del nodo. Por ejemplo, si el arbol es
//	T=(6 4 8 (5 4 4) 7 9) entonces la lista generada seria L=(6 5 4 0 8 0 5 2 4 0 4 0 7 0 9 0).
//	Consigna: Escribir una funcion void list2tree(tree<int> &T,list<int> &L); que dado una lista
//	L reconstruye el arbol ordenado orientado (AOO) T de acuerdo a la serializacion descripta
//	previamente.
//	Ayuda: Escribir una funcion auxiliar recursiva tree<int>::iterator list2tree(tree<int>
//	&T,tree<int>::iterator n, list<int> &L,list<int>::iterator &p); tal que contruye en el nodo
//	n el sub arbol que comienza en la lista en la posicion p. El nodo n es inicialmente no dereferenciable
//	(lambda). Para ello
//	Extrae de la lista el valor *n almacenado en el nodo y la cantidad de hijos nchild.
//	Inserta en n el valor.
//	Va aplicando recursivamente list2tree() sobre los hijos, hasta completar nchild.
//	list2tree retorna el iterator refrescado al nodo n.

tree<int>::iterator list2tree(tree<int>	&T,tree<int>::iterator n, list<int> &L,list<int>::iterator p){
	while (!L.empty()){
		p=L.begin();							//FALLA
		T.insert(n++,*p);
		tree<int>::iterator r=n.lchild();
		while(*p!=0){							//FALLA
			T.insert(n++,*p);
			L.erase(p);
		}
		list2tree(T,r,L,p);						//FALLA
	}
}

void list2tree(tree<int> &T,list<int> &L){
	if(T.empty())return;
	list<int>::iterator l=L.begin();
	list2tree(T,T.begin(),L,l);
}


//	b) [cumsum (20pt)] Consigna: Escribir una funcion void cumsum(btree<int> &T); (por suma
//		acumulada) que dado un arbol binario (AB) T modifica el valor de los nodos interiores, de manera
//		que resulta ser la suma de los valores de sus hijos mas el valor que habia en el nodo antes de llamar a
//		cumsum(). Los valores de las hojas no son modificados, y los valores de los nodos interiores resultan ser
//		la suma de todos los valores del sub arbol del nodo antes de llamar a cumsum.
//		Ejemplo: Si T=(1 5 (2 3 7 (11 4 2))) entonces despues de llamar cumsum(T) debe quedar
//		T=(35 5 (29 3 7 (17 4 2))).


void cumsum(btree<int> &T, btree<int>::iterator n){
	btree<int>::iterator l=n.left();
	if(l!=T.end()){
		cumsum(T,l);
		*n+=*l;
	}
	btree<int>::iterator r=n.right();
	if(r!=T.end()){
		cumsum(T,r);
		*n+=*r;
	}
}

void cumsum(btree<int> &T){
	if(T.begin()==T.end()) return;
	btree<int>::iterator n=T.begin();
	cumsum(T,n);
}



int main(int argc, char *argv[]) {
	map<int, list<int> > M;
	list<int> l1, l2, l3, l4;
	btree<int> T;
	
	
	l1.push_back(2);
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(4);
	l1.push_back(3);
	l1.push_back(6);
	l1.push_back(7);
	l1.push_back(8);
	l1.push_back(1);
	M[1]=l1;
	
	
	l2.push_back(1);
	l2.push_back(3);
	l2.push_back(4);
	l2.push_back(7);
	M[3]=l2;
	
	
	l3.push_back(3);
	l3.push_back(6);
	l3.push_back(9);
	M[5]=l3;
	
	l4.push_back(5);
	l4.push_back(3);
	l4.push_back(4);
	l4.push_back(9);
	M[6]=l4;

	
	
return 0;
}

