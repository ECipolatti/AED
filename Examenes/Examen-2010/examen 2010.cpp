#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>
#include "util.h"


#include <stack>
using namespace std;


void muestapila(stack<int> &S){
	int num;
	cout<<"PILA: ";
	while(!S.empty()){
		num=S.top();
		S.pop();
		cout<<num<< "   ";
	}
	cout<<endl;
}

void muestralista(list<int> &L){
	int num;
	cout<<"LISTA: ";
	list<int>::iterator p=L.begin();
	while(p!=L.end()){
		cout<<*p<<"   ";
		p++;
	}
	cout<<endl;
}

//a) [cutoff-map (15pt)] Consigna: Implemente una funcion
//void cutoff_map(map<int, list<int> > &M,int p,int q); que elimina todas las claves que NO
//	estan en el rango [p,q). En las asignaciones que quedan tambien debe eliminar los elementos de la
//	lista que no estan en el rango. Si la lista queda vacia entonces la asignacion debe ser eliminada. Por
//	ejemplo: Si M={1->(2,3,4), 5->(6,7,8), 8->(4,5), 3->(1,3,7)}, entonces cutoff_map(M,1,6)
//	debe dejar M={1->(2,3,4), 3->(1,3)}. Notar que la clave 5 ha sido eliminada si bien esta dentro del
//	rango porque su lista quedaria vacia.
//	Restricciones: El programa no debe usar contenedores auxiliares.

void cutoff_map(map<int, list <int> > &M, int p, int q){
	map<int , list <int> >::iterator s = M.begin();
	while(s!=M.end()){
		list<int> &aux = s->second;
		list<int>::iterator l=aux.begin();
		if((s->first) <p or (s->first)>q) M.erase(s);
		else{
			while(l!=aux.end()){
				if(*l<p or *l>q) l=aux.erase(l);
				else l++;
				if(aux.empty())	M.erase(s);
			}
		}
		s++;
	}
}

//b) [compacta (20pt)] Consigna: Escribir una funcion void compacta(list<int> &L,stack<int> &S);
//que va tomando un elemento entero n de S y, si es positivo, saca n elementos de L y los reemplaza por
//	su suma. Esto ocurre con todos los elementos de S hasta que se acaben, o bien se acaben los elementos
//	de L.
//	Por ejemplo: Si L=(1,3,2,1,4,5,3,2,4,1) y S=(3,2,-1,0,2,5,2,-3) entonces L debe quedar
//	asi L=(6,5,8,7), y S=(2,-3) (es decir, sobran elementos de S).
//	Otro ejemplo: Si L=(1,3,2,1,4,5,3,2,4,1,3,2,1,4,7) y S=(3,2,-1,0,2,5) entonces L debe quedar
//	asi L=(6,5,8,12,1,4,7), y S=() (es decir, sobran elementos de L).
//	Restricciones: El programa no debe usar contenedores auxiliares.

void compacta(list<int> &L, stack<int> &S){
	if(S.empty())return;
	list<int>::iterator l=L.begin();
	while(l!=L.end() and !S.empty()){
		
		int s=S.top();
		S.pop();
		if(s>0){
			int suma=0;
			for(int i=0; i<s; i++){
				if(l!=L.end()){
					suma+=*l;
					l=L.erase(l);
					
				}				
			}
			l=L.insert(l,suma);
			l++;
		}
	}
}




//	c) [concat-map (15pt)] Consigna: Escribir una funcion
//	void concat_map(map<int,list<int> >& M, list<int>& L); tal que reemplaza los elementos de L
//	por su imagen en M. Si un elemento de L no es clave de M entonces se asume que su imagen es la lista
//	vacia.
//	Por ejemplo: Si
//	M={5->(3,2,5),2->(4,1),7->(2,1,1)} y L=(1,5,7,2,3), entonces debe quedar
//	L=(3,2,5,2,1,1,4,1).
//	Restricciones: El programa no debe usar contenedores auxiliares.
void concat_map(map<int, list <int> > &M, list <int> &L){
	list<int>::iterator l = L.begin();
	map<int, list<int> >::iterator m;
	while(l!=L.end()){
		m = M.find(*l);
		l = L.erase(l);
		if(m != M.end()){
			
			list<int> &aux = m->second;
			list<int>::iterator laux = aux.begin();
			while(laux != aux.end()){
				L.insert(l,*laux);
				
				laux++;
			}
		}
	}
}


//---------------------------------------------------------------------------------------------------
//PARA GRAFOS RECURSIVOS
//---------------------------------------------------------------------------------------------------
void connected_to(map<int, set<int> > &G, int x, set<int> &W){
	if (W.find(x) != W.end() )
		return;
	map<int, set<int> >::iterator p =  G.find(x);
	if ( p != G.end() ){
		set<int>::iterator q = p->second.begin();
		while(q != p->second.end() ){
			W.insert(p->first);
			connected_to(G,*q, W);
			q++;
		}
	}
}
//---------------------------------------------------------------------------------------------------


int main(int argc, char *argv[]) {
	map<int, list<int> > M;
	list<int> l1, l2, l3, l4;
	stack<int> S;
	S.push(2);
	S.push(-2);
	S.push(3);
	S.push(2);
	S.push(-1);
	S.push(0);
	S.push(3);
	
	
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
	
	muestralista(l3);
	concat_map(M, l3);
	muestralista(l3);
	
	
//	compacta(l1, S);
//	cout<<endl<<endl;
//	muestapila(S);
//	muestralista(l1);
	
	return 0;
}

