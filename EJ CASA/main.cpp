#include <iostream>
//#include "AED.h"
#include <climits>
#include <cstdlib>
#include <list>
#include "util.h"
#include <string>
#include <stack>
#include <map>
#include "Evaluar.hpp"
using namespace std;
//using namespace aed;

//	1. Escribir una funciÛn void sort(list<int> &L), que ordena los elementos de L de menor a
//	mayor. Para ello emplear el siguiente algoritmo simple, utilizando una lista auxiliar L2:
//	tomar el menor elemento de L, eliminarlo de L e insertarlo al final de L2 hasta que L este
//	vacÌa. Luego insertar los elementos de L2 en L.
void sort(list<int> &l){
	list<int> l2;
	list<int>::iterator min=l.begin();
	list<int>::iterator n=l.begin();
	while(l.begin()==l.end()){
		list<int>::iterator min=l.begin();
		while(n!=l.end()){
			if (*n<*min) min=n;
			n++;
		}
		l2.insert(l2.end(),*min);
		l.erase(min);
		n=l.begin();
	}
	n=l2.begin();
	while(n!=l2.end()){
		l.insert(l.end(),*n);
		n++;
	}
}


//mostrar lista de enteros

void print_list(list<int> &l){
	list<int>::iterator p=l.begin();
	while(p!=l.end()){
		cout<<*p<<"   ";
		p++;
	}
}


//	2. Escribir una funciÛn void selection_sort(list<int> &L), que ordena los elementos de L de
//	menor a mayor. Esta funciÛn debe ser IN PLACE. Para ello debe tomarse el menor
//	elemento de L e intercambiarlo (swap) con el primer elemento de la lista. Luego
//	intercambiar el menor elemento de la lista restante, con el segundo elemento, y asÌ
//	sucesivamente.

void selection_sort(list<int> &l){
	list<int>::iterator p=l.begin(),
		n=l.begin(),
		min=l.begin();
	while(n!=l.end()){
		while(p!=l.end()){
			if(*p<*min)min=p; 
			p++;
		}
		swap(*min,*n);
		n++;
		p=n;
		min=n;
	}
}


//	3. Escribir una funciÛn void concat_lists(list<list<int> > &LL, list<int> &L), que concatena
//	las n listas de LL en L.

void concat_lists(list<list<int> > &LL, list<int> &L){
	list<list<int> >::iterator n = LL.begin();
	list<int>::iterator p = n->begin();
	while(n!=LL.end()){
		while(p!=n->end()){
			L.insert(L.end(),*p);
			p++;
		}
		n++;
		p=n->begin();
	}
}


//	4. Escribir una funciÛn void invert(list<int> &L), que invierte el orden de la lista L. Este
//	algoritmo debe implementarse IN PLACE y debe ser O(n).

void invert(list<int> &l){
	list<int>::iterator n=l.begin(),p=l.end();
	int S=(l.size()/2);
	int f=0;
	p--;
	while(f<=S){ 
		swap(*n,*p);
		n++;
		p--;
		f++;
	}
}


//	5. Escribir una funciÛn void junta(list<int> &L, int c) que, dada una lista L, agrupa de a c
//	elementos, dejando su suma IN PLACE. Por ejemplo, si se le pasa como argumento la lista
//	L=(1,3,2,4,5,2,2,3,5,7,4,3,2,2), despuÈs de aplicar el algoritmo junta(L,3) debe quedar
//	L(6,11,10,14,4). El algoritmo debe tener un tiempo de ejecuciÛn O(n).

void junta(list<int> &l, int c){
	list<int>::iterator n=l.begin();
	int suma;
	while(n!=l.end()){
		suma=0;
		for(int i=0; i<c; i++){
			suma+=*n;
			n=l.erase(n);
			if(n==l.end())break;
		}
		n=l.insert(n,suma);
		n++;
	}
}


//	6. Dada una lista de enteros L y dos listas SEQ y REEMP (posiblemente de distintas
//	longitudes), escribir una funciÛn void reemplaza(list<int> &L, list<int> &SEQ, list<int>
//	&REEMP), que busca todas las secuencias de SEQ en L y las reemplaza por REEMP. Por
//	ejemplo, si L=(1,2,3,4,5,1,2,3,4,5,1,2,3,4,5), SEQ=(4,5,1) y REEMP=(9,7,3), entonces
//	despuÈs de llamar a reemplaza(L,SEQ,REEMP), debe quedar
//	L=(1,2,3,9,7,3,2,3,9,7,3,2,3,4,5). Para implementar este algoritmo primero buscar desde el
//	principio la secuencia SEQ, al encontrarla, reemplazar por REEMP, luego seguir buscando
//	a partir del siguiente elemento al ˙ltimo de REEMP.

void reemplaza (list<int> &L, list<int> &SEQ, list<int> &REEMP){
	list<int> :: iterator l = L.begin();
	if( L.begin() == L.end() ) return;
	while (l != L.end() ){
		list<int> :: iterator s = SEQ.begin();
		list<int> :: iterator r = REEMP.end();
		list<int> :: iterator aux = l;
		int cant = 0;
		if(*l == *s){
			while (s != SEQ.end()){
				if( *s == *aux)	cant++;
				aux++;
				s++;
			}
		}
		if( cant == SEQ.size()){
			l = L.erase ( l , aux );
			while ( r != REEMP.begin()){
				l = L.insert( l, *--r);
			}
		}
		l++;
	}
}


//	7. Problema de Josephus. Un grupo de soldados se haya rodeado por una fuerza enemiga.
//	No hay esperanzas de victoria si no llegan refuerzos y existe solamente un caballo
//	disponible para el escape. Los soldados se ponen de acuerdo en un pacto para determinar
//	cu·l de ellos debe escapar y solicitar ayuda. Forman un cÌrculo y se escoge un n˙mero n al
//	azar. Igualmente se escoge el nombre de un soldado. Comenzando por el soldado cuyo
//	nombre se ha seleccionado, comienzan a contar en la direcciÛn del reloj alrededor del
//	cÌrculo. Cuando la cuenta alcanza el valor n, este soldado es retirado del cÌrculo y la
//	cuenta comienza de nuevo, con el soldado siguiente. El proceso contin˙a de tal manera
//	que cada vez que se llega al valor de n se retira un soldado. El ˙ltimo soldado que queda
//	es el que debe tomar el caballo y escapar. Entonces, dados un n˙mero n y una lista de
//	nombres, que es el ordenamiento en el sentido de las agujas del reloj de los soldados en el
//	cÌrculo (comenzando por aquÈl a partir del cual se inicia la cuenta), escribir un
//	procedimiento que obtenga los nombres de los soldados en el orden que han de ser
//	eliminados y el nombre del soldado que escapa.
void problema7(list<string> &l, int n){
	list<string>::iterator p=l.begin();
	list<string> nombres;
	int cont=0;
	while(!l.empty()){
		for(int i=0; i<n; i++){
			if(p==l.end())
				p=l.begin();
			p++;
		}
		p--;
		nombres.push_back(*p);
		p=l.erase(p);
	}
	printl(nombres);
	p=nombres.end();
	p--;
	cout<<endl<<endl<<endl<<"El soldado que escapa es: "<<*p;
}



//	8. Escribir una funciÛn void sort(list<int> &L), que ordena los elementos de L de mayor a
//	menor. Para ello emplear el siguiente algoritmo simple, utilizando una pila auxiliar P: ir
//	tomando el menor elemento de L, eliminarlo de L e insertarlo en P hasta que L este vacÌa.
//	Luego insertar los elementos de P en L.

void sortp(list<int> &l){
	stack<int> pila;
	while(!l.empty()){
		list<int>::iterator p=l.begin();
		list<int>::iterator min=l.begin();
		while(p!=l.end()){
			if(*p<*min) min=p;
			p++;
		}
		pila.push(*min);
		l.erase(min);
	}
	while(!pila.empty()){
		l.insert(l.end(),pila.top());
		pila.pop();
	}
}


//	9. Escribir una funciÛn void sort(list<int> &L), que ordena los elementos de L de menor a
//	mayor. Para ello utilizar el siguiente algoritmo simple, utilizando una cola auxiliar C: ir
//	tomando el menor elemento de L, eliminarlo de L e insertarlo en C hasta que L este vacÌa.
//	Luego insertar los elementos de C en L.

void sortc(list<int> &l){
	queue<int> cola;
	while(!l.empty()){
		list<int>::iterator p=l.begin();
		list<int>::iterator max=l.begin();
		while(p!=l.end()){
			if(*p<*max) max=p;
			p++;
		}
		cola.push(*max);
		l.erase(max);
	}
	while(!cola.empty()){
		l.insert(l.end(),cola.front());
		cola.pop();
	}
}


//	10. Escribir una funciÛn que reciba como par·metro una cadena de texto y determine si Èsta
//	es un palÌndromo, ignorando los espacios entre palabras. Un palÌndromo es una secuencia
//	de caracteres que se lee igual hacia adelante que hacia atr·s, por ejemplo: alli si maria
//	avisa y asi va a ir a mi silla. Recordar que un string puede indexarse como un vector. Con
//	el fin de utilizar la estructura <list>, primero deben pasarse los elementos del string a una
//	lista y solo utilizar Èsta en el algoritmo.

bool palindromo(string s){
	list<char> L;
	int cont=0;
	
	while( cont != s.size() ){
		if(s[cont] != ' ')
			L.insert( L.end(), s[cont] );
		cont++;
	}
	list<char> :: iterator p= L.begin();
	list<char> :: iterator q= L.end();
	q--;
	while( p != L.end() and q != L.begin()){
		if (*p != *q) return false;
		p++;q--;
	}
	return true;
}

//	11. Dos correspondencias M1 y M2 son inversas una de la otra si tienen el mismo n˙mero de
//	asignaciones y para cada par de asignacion xÅ® y en M1 existe el par yÅ®x en M2.
//	Escribir una funcion bool areinverse(map<int,int> &M1, map<int,int> &M2); que
//	determina si las correspondencias M1 y M2 son inversas.

bool areinverse(map<int,int> &M1, map<int,int> &M2){
	if (M1.size()!=M2.size()) return false;
	map<int,int>::iterator m1=M1.begin(), m2=M2.begin();
	while(m1!=M1.end()){
		if(M2.find(m1->second)==M2.end()) return false;
		if(M2.find(m1->second)!=M2.end()){
			m2=M2.find(m1->second);
			if(m1->first!=m2->second)return false;
		}
		m1++;
	}
	return true;
}


//	12. Escribir una funcion void map2list(map<int,int> &M, list<int> &Keys, list<int> &Vals);
//	que dado un map M retorna las listas de claves y valores. Ejemplo: si M = { 1Å®2 ,
//	3Å®5 , 8Å®20 }, entonces debe retornar Keys = (1,3,8) y Vals = (2,5,20).
	
void map2list(map<int,int> &M, list<int> &keys, list<int> &vals){
	map<int,int>::iterator m=M.begin();
	while(m!=M.end()){
		keys.insert(keys.end(),m->first);
		vals.insert(vals.end(),m->second);
		m++;
	}
}


//	13. Escribir una funcion void list2map(map<int,int> &M, list<int> &Keys, list<int> &Vals);
//	que dadas las listas de claves (k1,k2,k3, ...) y valores (v1,v2,v3, ...) retorna el map M con
//	las asignaciones correspondientes { k1Å®v1 , k2Å®v2 , k3Å®v3 , ...}. Nota: si hay
//	claves repetidas, solo debe quedar la asignacion correspondiente a la ultima clave en la
//	lista. Si hay menos valores que claves utilizar cero como valor. Si hay mas valores que
//	claves, ignorarlos.

void list2map(map<int,int> &M, list<int> &Keys, list<int> &Vals){
	list<int>::iterator k=Keys.begin(), v=Vals.begin();
	while(k!=Keys.end()){
		if(v==Vals.end())
			M[*k]=0;
		else{
			M[*k]=*v;
			v++;
		}
		k++;
	}
}


//	14. Dadas dos correspondencias A y B, que asocian enteros con listas ORDENADAS de
//	enteros, escribir una funciÛn void merge_map(map<int, list<int> > &A, map<int,
//	list<int> < &B, map<int, list<int> > &C) que devuelve en C una correspondencia que
//	asigna el al elemento x la fusiÛn ORDENADA de las dos listas A[x] y B [x]. Si x no es clave
//	de A, entonces C[x] debe ser B[x] y viceversa. Sugerencia: implementar y utilizar una
//	funciÛn merge(list<int> &L1, list<int> &L2, list<int> &L); que devuelve en L la fusiÛn
//	ordenada de L1 y L2.

void mergel(list<int> &L1, list<int> &L2, list<int> &L){
	list<int>::iterator l1=L1.begin(), l2=L2.begin();
	while(l1!=L1.end() && l2!=L2.end()){
		if(*l1<*l2){
			L.insert(L.end(),*l1);
			l1++;
			continue;
		}
		if(*l1==*l2){
			L.insert(L.end(),*l1);
			L.insert(L.end(),*l2);
			l1++;
			l2++;
			continue;
		}
		else{
			L.insert(L.end(),*l2);
			l2++;
			continue;
		}
	}
	while(l2!=L2.end()){
		L.insert(L.end(),*l2);
		l2++;
	}
	while(l1!=L1.end()){
		L.insert(L.end(),*l1);
		l1++;
	}
}

void merge_map(map<int, list<int> > &A, map<int, list<int> > &B, map<int, list<int> > &C){
	map<int, list<int> >::iterator a=A.begin(), b=B.begin();
	while(a!=A.end()){
		if(B.find(a->first)!=B.end()){
			b=B.find(a->first);
			list<int> aux;
			mergel(a->second, b->second,aux);
			C[a->first]=aux;
		}
		else
			C[a->first]=a->second;
		a++;
	}
	b=B.begin();
	while(b!=B.end()){
		if(A.find(b->first)==A.end()){
			C[b->first]=b->second;
		}
		b++;
	}
}

//Imprime un mapa
void print_map (map<int, list<int> > &M){
	map<int, list<int> > :: iterator m = M.begin();
	cout << "M = {";
	while (m != M.end() ){
		list<int> :: iterator l = m->second.begin();
		cout << m->first << "->[";
		while (l != m->second.end() ){
			cout << *l ;
			l++;
			if ( l != m->second.end() ){
				cout << ", ";
			}
		}
		m++;
		cout << "]";
		if ( m != M.end() ) {
			cout << ", " ;
		}
	}
	cout << "}";
}


//	15. Implemente una funcion void cutoffmap(map<int, list<int> > &M, int p, int q); que
//	elimina todas las claves que NO estan en el rango [p,q). En las asignaciones que quedan
//	tambien debe eliminar los elementos de la lista que no estan en el rango. Si la lista queda
//	vacia entonces la asignacion debe ser eliminada. Por ejemplo: si M = { 1Å®(2,3 ,4) ,
//	5Å®(6,7,8) , 8Å®(4,5) , 3Å®(1,3,7) }, entonces cutoffmap(M,1,6) debe dejar M = {
//	1Å®(2,3 ,4) , 3Å®(1,3) }. Notar que la clave 5 ha sido eliminada si bien esta dentro del
//	rango porque su lista quedaria vacia. Restricciones: el programa no debe usar
//	contenedores auxiliares.

void cutofflist(list<int> &L, int p, int q){
	list<int>::iterator l=L.begin();
	while(l!=L.end()){
		if(*l<=p || *l>q)
			l=L.erase(l);
		else
			l++;
	}
}

void cutoffmap(map<int, list<int> > &M, int p, int q){
	map<int, list<int> >::iterator m=M.begin(),tmp;
	while(m!=M.end()){
		if(m->first<=p || m->first>q){
			tmp=m;
			m++;
			M.erase(tmp);
		}
		else 
			m++;
	}
	m=M.begin();
	while(m!=M.end()){
		cutofflist(m->second,p,q);
		if(m->second.empty()){
			tmp=m;
			m++;
			M.erase(tmp);
		}
		else
			m++;
	}
}



int main(){
	int v1 [] = {1,2,6,-1};
	list <int> l1 ; 
	insertl (l1,v1,-1);
	int v2 [] = {3,4,5,-1};
	list <int> l2 ; 
	insertl (l2,v2,-1);
	int v3 [] = {2,4,5,-1};
	list <int> l3 ; 
	insertl (l3,v3,-1);
	int v4 [] = {3,5,4,-1};
	list <int> l4 ; 
	insertl (l4,v4,-1);
	int v5 [] = {5,7,8,-1};
	list <int> l5 ; 
	insertl (l5,v5,-1);
	
	
	map<int,list<int> > M1,M2,M3;
	M1[2]=l1;
	M1[1]=l2;
	M1[3]=l3;
	M1[5]=l5;
	
	M2[4]=l4;
	M2[2]=l5;

//	merge_map(M1,M2,M3);
	cutoffmap(M1,1,4);
	print_map(M1);

	// Evaluar ev;
	// ev.evaluar1(acum_hasta);
	// ev.evaluar2(Colas);
	// ev.evaluar3(mostrar_map);
	// ev.evaluar4(print_map)
	
}
