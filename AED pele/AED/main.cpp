#include "tree.h"
#include <iostream>
#include "util.h"
#include "util_tree.h"

using namespace aed;
//MAXTREE busca el maximo valor en un arbol
int maxtree(tree<int> &t, tree<int>::iterator n, int &max){
	tree<int>::iterator c = n.lchild();
	while(c!=t.end()){
		if(*c>max) max=*c;
		maxtree(t,c++,max);
	}
	return max;
}
int maxtree(tree<int> &t){
	tree<int>::iterator p = t.begin();
	int max=*p;
	if (p==t.end()) return -1;
	else 
		maxtree(t,p,max);
	return max;
}


//Sumar lso valores de un arbol
void suma(tree<int> &t, tree<int>::iterator n, int &sum){
	sum +=*n;
	tree<int>::iterator c = n.lchild();
	while (c!=t.end()){
		suma(t,c,sum);
		c++;
	}
}
int suma(tree<int> &t){
	int sum=0;
	tree<int>::iterator p=t.begin();
	suma(t,p,sum);
	return sum;
}
//mustra la altura del arbol
int altura(tree<int> &t, tree<int>::iterator n){
	int alt=0;
	tree<int>::iterator c=n.lchild();
	while(c!=t.end()){
		int aux = altura (t,c++);
		if (alt<aux) alt=aux;
	}
	return ++alt;
}
int altura(tree<int> &t){
	tree<int>::iterator p=t.begin();
	if(p==t.end()) return 0;
	altura(t,p);
}
//Cuanta cuantos pares hay en el arbol
void cuantospares(tree<int> &t, tree<int>::iterator n, int &acum){
	tree<int>::iterator c=n.lchild();
	while (c!=t.end()){
		if ((*c%2)==0) acum+=1;
		cuantospares(t,c,acum);
		c++;
	}
}

int cuantospares(tree<int> &t){
	int acum;
	tree<int>::iterator p=t.begin();
	if ((*p%2)==0)acum=1;
	else acum=0;
	cuantospares(t,p,acum);
	return acum;
}

//5- Escribir una función int prof_par(tree<int> &T) que retorna la profundidad máxima de un nodo con etiqueta par.
//int prof_par(tree<int> &t, tree<int>::iterator n){
//	
//}
//int prof_par(tree<int> &t){
//	
//}

//6- Escribir una función int cuentacaminos(tree<int> &T, int l) que, dado un árbol ordenado
//	orientado A, cuenta cuantos caminos de longitud l tiene el árbol.
int cuantacaminos(tree<int> &t, int l){
	
}


//7 - recorrer el arbol en preorden
//void prevorden(tree<int> &t, list <int> &l){
//	tree<int>::iterator p=t.begin();
//	if(p==t.end()) return;
//	while (p!=t.end()){
//		l.insert(l.end(),*p)
//		p=t.lchild();
//	}
//}
int main(){
	
	
	tree<int> t;
	list<int> l;
	tree<int>::iterator n,q;
	lisp2tree("(2 (6 8(2 3) 4(5 6(7 5))))",t);
	print_tree(t);
	cout<<endl<<endl<<altura(t)<<endl;
	
	
	//print_tree(t);
	
}
