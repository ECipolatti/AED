#include "tree.h"
#include <iostream>
#include "util.h"
#include "util_tree.h"

using namespace aed;


//	1. Escribir una función int maxtree(tree<int> &T) que retorna el máximo de las etiquetas de
//	un árbol.

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
//	while(p!=t.end())^{
		maxtree(t,p,max);
//		p++;
//	}
	return max;
}


//	2. Escribir una función int suma(tree<int> &T) que calcula la suma de las etiquetas de un
//	árbol.

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
//3. Escribir una función int altura(tree<int> &T) que retorne la altura de un árbol.
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
	return altura(t,p); //agregué return
}
//	4. Escribir una función int cuantospares(tree<int> &T) que retorna la cantidad de nodos con
//	etiquetas pares que tiene un árbol.
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
int prof_par(tree<int> &t, tree<int>::iterator n, int &acum){
	if((*n%2)==0) acum+=1;
	tree<int>::iterator c=n.lchild();
	while(c!=t.end()){
		prof_par(t,c,acum);
		c++;
	}
	acum+=1;
	
	return acum;
}
int prof_par(tree<int> &t){
	tree<int>::iterator n=t.begin();
	int acum=0;
	prof_par(t, n, acum);
	return acum;
}

//6- Escribir una función int cuentacaminos(tree<int> &T, int l) que, dado un árbol ordenado
//	orientado A, cuenta cuantos caminos de longitud l tiene el árbol.
//int cuentacaminos(tree<int> &t, int l){
//	int cuenta=0;
//	tree<int>::iterator p=t.begin();
//	while(p!=t.end()){
//		int longitud=0;
//		while(longitud<l){
//
//			tree<int>::iterator n=p.lchild();
////		int longitud=0;
////		while(n!=t.end()){
////			if(longitud<l)longitud+=1;
////			n++;
////		}
////		if(longitud==l)
////			cuenta+=1;
//		}
//		p++;
//	}
//	return cuenta;
//}


//7. Escribir una función void prevorden(tree<int> &T, list<int> &L) que, retorna en L, la lista
//de los nodos en orden previo.
void prevorden(tree<int> &T, tree<int> :: iterator t, list<int> &L){
	tree<int> :: iterator c;
	if( t != T.end()){
		c = t.lchild();
		while ( c != T.end()){
			L.insert(L.end(), *c);
			prevorden( T,c++,L);
		}
	}
	else return;
}
void prevorden ( tree<int> &T, list<int> &L){
	tree<int> :: iterator t= T.begin();
	L.insert(L.end(), *t);
	return prevorden( T, t, L);
}



//8. Escribir una función void postorden(tree<int> &T, list<int> &L) que, retorna en L, la lista
//de los nodos en orden posterior.

void postorden(tree<int> &T, tree<int>::iterator t, list<int> &L){
	tree<int>:: iterator c;
	if(t!=T.end()){
		c=t.lchild();
		while(c!=T.end()){
			postorden(T,c++,L);
		}
		L.insert(L.end(),*t);
	}
}
void postorden(tree<int> &T, list<int> &L){
	tree<int>::iterator t=T.begin();
	return postorden(T, t, L);
}


//9. Escribir una función void path_of_largest(tree<int> &AT,list<int> &L); que, dado un
//árbol ordenado orientado A, retorna en L el camino que se obtiene recorriendo el árbol
//hacia abajo, siempre por el hijo más grande. Por ejemplo, si A=(3 (4 6 (7 8 9)) (5 2 4 6))
//entonces path_of_largest debe retornar L=(3 5 6). Si para un nodo el valor más grande de
//los hijos está repetido, entonces el camino puede seguir por cualquiera de ellos. Por
//ejemplo si A=(3 (4 5 6) 4 2) entonces path_of_largest() puede retornar L=(3 4 6) o L=(3 4).

//	11. Escribir una función void cumsum(btree<int> &T); (por suma acumulada) que dado un
//		árbol binario (AB) T modifica el valor de los nodos interiores, de manera que resulta ser la
//		suma de los valores de sus hijos más el valor que había en el nodo antes de llamar a
//		cumsum(). Los valores de las hojas no son modificados, y los valores de los nodos
//		interiores resultan ser la suma de todos los valores del sub árbol del nodo antes de llamar
//		a cumsum. Ejemplo: Si T=(1 5 (2 3 7 (11 4 2))) entonces después de llamar cumsum(T)
//		debe quedar T=(35 5 (29 3 7 (17 4 2))).

void cumsum(btree<int> &T, btree<int>::iterator p){
	if(p==T.end()) return;
	btree<int>::iterator i=p.left();
	btree<int>::iterator d=p.right();
	cumsum(T,p.right());
	cumsum(T,p.left());
	if(i!=T.end()) *p+=*i;
	if(d!=T.end()) *p+=*d;
}

void cumsum(btree<int> &T){
	cumsum(T,T.begin());
}

//	12. Dado un árbol binario, escribir una función bool es_completo(btree<int> &T); retorna true
//		si el árbol es completo, es decir, todos sus nodos interiores tienen los dos hijos.

bool es_completo(btree<int> &T, btree<int>::iterator p){
//	if(p==T.end())return true;
	btree<int>::iterator l=p.left();
	btree<int>::iterator r=p.right();
	if(l==T.end() xor r==T.end()) return false;
	es_completo(T,l);
	es_completo(T,r);
	return true;
}

bool es_completo(btree<int> &T){
	if(T.begin()==T.end()) return true;
	return es_completo(T,T.begin());
}

//	13. Dado un árbol binario, escribir una función double completitud(tbree<int> &T); retorna la
//		relación entre el número de nodos interiores completo y el número total de nodos
//		interiores. Para un árbol completo debe retornar 1.



//	14.	Escribir una función bool is_full(btree<int> &T) que retorna si una árbol es o no “lleno”.
//		Recordemos que un árbol es lleno, si todos sus niveles están completos. Se puede definir
//		en forma recursiva de la siguiente manera:
//		• El árbol vacío es lleno.
//		• El árbol no vacío es lleno, si sus dos hijos son llenos y tiene la misma altura.
//		Sugerencia: Escribir una función auxiliar bool is_full(btree<int> &T,btree<int>::iterator
//		n, int &height); que retorna por height la altura del árbol.

bool is_full(btree<int> &T, btree<int>::iterator p, int &height){
	/*if(p==T.end())return false;*/
	
	btree<int>::iterator l=p.left();
	btree<int>::iterator r=p.right();
	if(l==T.end() xor r==T.end()) return false;
	height++;
	is_full(T,l,height);
	is_full(T,r,height);
	height--;
	return true;
}

bool is_full(btree<int> &T){
	if(T.begin()==T.end()) return true;
	int height=0;
	return is_full(T,T.begin(), height);
}

//	15.Dado un AB T encontrar, la profundidad máxima de los nodos que satisfacen un cierto
//	predicado (profundidad condicionada). Por ejemplo, si T=(6 (7 9 (3 1)) 2), entonces
//	depth_if(T,even) debe retornar 1, ya que el nodo par a mayor profundidad es 2, mientras
//	que depth_if(T,odd) debe retornar 3, ya que el nodo impar a máxima profundidad es 1.
//	Consigna: Escribir una función int depth_if(btree<int> &T,bool (*pred)(int)); que realiza la
//	tarea indicada.
//	Ayuda: La función recursiva auxiliar debe retornar la máxima profundidad de un nodo que
//	satisface el predicado o -1 si el arbol está vacío o ningún nodo satisface el predicado.
//	Entonces, dadas las profundidades condicionadas dl, dr de los hijos la profundidad se
//	puede expresar en forma recursiva como
//	-1 ; si n es lamda
//	max(dr , dl)+1 ; si max(dr , dl)>0
//	0 ; si n satisface el predicado
//	-1 ; si n no satisface el predicado

bool es_par(int a){
	return (!(a%2));
}

int depth_if (btree<int> &T, btree<int>::iterator p, bool (*pred)(int)){
	if(T.begin()==T.end()) return -1;
}

int depth_if(btree<int> &T, bool (*pred)(int)){
	return depth_if(T,T.begin(), pred);
}

int main(){
	
	/*btree<int> T;
	btree<int> :: iterator p = T.begin();
	
	p = T.insert(p,1);
	p = p.left();
	p = T.insert(p,5);
	p = T.begin().right(); //! 1
	p = T.insert(p,2); //! 5 2
	p = p.left(); //! 4 7
	p = T.insert(p,4);
	p = T.insert(T.begin().right().right(),7);
	T.lisp_print(T.begin());
	cout<<endl<<endl;
	cout<<es_par(5);
	*/
	
//	cout<<is_full(T);
//	cumsum(T);
//	T.lisp_print(T.begin());
	tree<int> t;
	lisp2tree("(1 (2 3 (4 5))(6 7 (8 9 10)))", t);
	t.print_prev();
	
	cout<<endl;
	t.print_post();
	cout<<endl;
	print_tree(t);
	
	


	return 0;
}

