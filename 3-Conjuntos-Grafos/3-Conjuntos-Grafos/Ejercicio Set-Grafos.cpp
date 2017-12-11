#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <map>
#include "btree.h"
#include "tree.h"
#include "Open Hash Table.h"
#include "Binary Search Tree.h"
//#include "btree.h"
using namespace std;
using namespace aed;
//!Parcial 2009****************************************************************
//Ejercicio 1)-a!!
btree<int> :: iterator find(btree<int> &T, int x ){
	btree<int> :: iterator t = T.begin();
	while(true){
		if( t == T.end() ) return t;
		else if( x < *t ) t = t.left();
		else if ( x > *t ) t = t.right();
		else return t;
	}
}
//Ejercicio 1)-b
template<class T>
//int serase(T x){
//	set <int> :: iterator s = lower_bound(x);
//	if ( s != S.end() and *s == x){
//		S.erase(s);
//		return 1;
//	}
//	else
//		return 0;
//}
//Ejercicio 1)-c
bool openhashtable_insert(vector<list<T> >& table,
	unsigned int (*hashfunc)(T), T x){
		int h = hashfunc(x);
		int b = h % table.size();
		if (table[b].find(x) == table[b].end()){
			table[b].insert(x);
			return true;
		}
		else 
			return false;
}
//Ejercicio 2)-a
bool tree_nodeset(tree<int> &T,tree<int> :: iterator t, set<int> &nodeset, vector<int> &V){
	tree<int> :: iterator c = t.lchild();
	
	while( c != T.end() ){
		for (int i = 0; i<V.size(); i++){
			if( *c == V[i]){
				nodeset.clear();
				return false;
			}
			nodeset.insert(V[i]);
		}
		V.push_back(*c);
		tree_nodeset(T,c++,nodeset,V);
	}
	nodeset.insert(V[V.size()-1]);
	return true;
}
bool tree_nodeset(tree<int> &T,set<int> &nodeset){
	if( T.begin() == T.end() ) return true;
	nodeset.clear();
	vector<int> V;
	V.push_back(*T.begin());
	return tree_nodeset(T, T.begin(), nodeset,V);
}
//Ejercicio 2)-b
void graph_vrtxset(map<int, set<int> > &G, set<int> &vrtxset){
	map<int, set<int> > :: iterator g = G.begin();
	while (g != G.end()){
		vrtxset.insert(g->first);
		g++;
	}
}
//!Parcial 2008****************************************************************
//Ejercicio 1)-a!!
pair <btree<int>::iterator,bool> abb_insert(btree<int> &T,int x){
	btree<int> :: iterator n = bst_find( T, x );
	pair<btree<int> :: iterator, bool> p;
	if(n != T.end()){
		p.first = n;
		p.second = false;
	}
	else{
		n = T.insert(n,x);
		p.first = n;
		p.second = true;
	}
	return p;
}
//Ejercicio -b!!
bool oht_erase1(vector<list<int> > &H,unsigned int (*h)(const int&),const int &x){
	
	list<int> :: iterator position;
	unsigned int bucket;
	bool found = oht_find( H, h, x,bucket,position);
	
	if(!found) return false;
	
	H[bucket].erase(position);
	return true;
}
//Ejercicio -c!!
void vbset_difference(vector<bool> &A,vector<bool> &B,vector<bool> &C){
	C = A;
	for(int i = 0 ; i < B.size() ; i++){
		if ( C[i] == B[i] ){
			C[i] = false;
		}
	}
	
	
}
//Ejercicio 2)-a!!
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
//Ejercicio 2)-b!!

using namespace std;
//!Parcial 2006****************************************************************
//Ejercicio 2)-a!!
bool es_simetrica (map<int,set<int> > &G){
	map<int,set<int> > :: iterator p = G.begin();
	
	while ( p != G.end() ){
		set<int> :: iterator s = p->second.begin();
		while ( s != p->second.end() ){
			map<int,set<int> >:: iterator aux = G.find(*s);
			if ( aux == G.end() )
				return false;
			if ( aux->second.find(p->first) == aux->second.end())
				return false;
			s++;
		}
		p++;
	}
	return true;
}
//Ejercicio 2)-b
void de_arista_a_adyacencia (list<pair<int,int> > &L, map<int,set<int> > &F){
	list<pair<int,int> > :: iterator l = L.begin();
	while ( l != L.end() ){
		F[l->first].insert(l->second);
		F[l->second].insert(l->first);
		l++;
	}
}
//Ejercicio 2)-c
int cuenta_aristas(map<int,set<int> > &G){
	map<int,set<int> > :: iterator g = G.begin();
	int aristas=0;
	while( g != G.end()){
		set<int> :: iterator s = g->second.begin();
		while( s != g->second.end()){
			aristas++;
			s++;
		}
		g++;
	}
	return (aristas/2);
}
//!Parcial 2005****************************************************************
//Ejercicio 2)-a!!
void diff_sym(list<set<int> > &L,set<int>&S){
	list<set<int> > :: iterator l = L.begin();
	set<int> :: iterator ls = l->begin();
	
	if(L.empty()) return;
	
	while( ls != L.begin()->end()){
		S.insert(*ls);
		ls++;
	}
	
	l++;
	while ( l != L.end()){
		ls = l->begin();
		while( ls != l->end() ){
			set<int> :: iterator aux = S.find(*ls);
			if( aux != S.end() )
				S.erase(aux);
			else
				S.insert(*ls);
			ls++;
		}
		l++;		
	}
	
	
}
//Ejercico 2)-b
bool incluido(set<int> &A, set<int> &B){
	set<int> :: iterator a = A.begin();
	while( a != A.end() ){
		if( B.find(*a) == B.end()){
			return false;
		}
		else
			a++;
	}
	return true;
}
//Ejercicio de carpeta!!
bool flat (vector<set<int> > &sw, int n){
	for( int i = 0; i<n-1; i++){
		for( int j = i+1; j < n; j++){
			int r;
			for(r=0; r < sw.size(); r++){
				if( sw[r].find(i) != sw[r].end() && sw[r].find(j) != sw[r].end())
					break;
				if ( r == sw.size()){
					cout << " Par " << i;
					return false;
				}
			}
		}
	}
	return true;
}

//Forma sin optimizar memoria!!
void union_mia ( set<int> &A, set<int> &B, set<int> &C ){
	set<int> :: iterator a = A.begin(), b = B.begin();
	while ( a != A.end()){
		C.insert(*a);
		a++;
	}
	while(b != B.end()){
		C.insert(*b);
		b++;
	}
	
}
//Forma optimizada!!
void union_optima(  set<int> &A, set<int> &B, set<int> &C ){
	set<int> *x,*y;
	if( A.size() > B.size()){ // Veo cual es el mas grande y lo guardo en x para insertarlo primero y ahorrar memoria ya que el insert implica un find
		x=&A;
		y=&B;
	}
	else{
		x=&B;
		y=&A;
	}
	C = *x;
	set<int> :: iterator p = y->begin();
	while( p != y->end()){
		C.insert( *p++);
	}
}
//Forma sin optimizar memoria!!
void interseccion(  set<int> &A, set<int> &B, set<int> &C ){
	set<int> :: iterator a = A.begin();
	while( a != A.end() ){
		if( B.find(*a) != B.end()){
			C.insert(*a);
		}
	}
}

void interseccion_optima ( set<int> &A, set<int> &B, set<int> &C ){
	set<int> *X,*Y;
	if( A.size() > B.size()){ // La idea es hacer el find sobre el conjunto mas chico X
		X = &B; Y = &A;
	}
	else{
		X = &A; Y = &B;
	}
	set<int> :: iterator p = X->begin();
	while ( p != X->end()){
		if( Y->find(*p) != Y->end()){
			C.insert(*p);
		}
	}
}
int main(int argc, char *argv[]) {
	vector<bool> A,B,C;
	A.push_back(true);
	A.push_back(true);
	A.push_back(false);
	A.push_back(false);
	A.push_back(true);
	
	B.push_back(true);
	B.push_back(true);
	B.push_back(false);
	B.push_back(false);
	B.push_back(false);
	
//	vbset_difference(A,B,C);
//	for(int i = 0 ; i < C.size() ; i++){
//		cout << C[i] << ",";
//	}
	cout << endl << endl;
/*	set<int> S,T;*/
/*	list<set<int> > :: iterator l = L.begin();*/
	//Set A = {1,2,5};
//	S.insert(1);
//	S.insert(2);
//	S.insert(5);
//	L.insert(L.begin(), S);
//	S.clear();
	//Set B = {2,3,6};
//	l++;
//	T.insert(1);
//	T.insert(2);
//	T.insert(3);
//	L.insert(l, S);
//	S.clear();
	//Set C ={4,6,9}
//	l++;
//	S.insert(4);
//	S.insert(6);
//	S.insert(9);
//	L.insert(l, S);
//	S.clear();
	
//	diff_sym(L,S);
//	cout << incluido(S,T);
//	cout << endl << endl;
	list<pair<int,int> > L;
	list<pair<int,int> > :: iterator l= L.begin();
	pair<int,int> p;
	p.first = 0;
	p.second = 2;
	L.push_back(p);
	p.first = 0;
	p.second = 1;
	L.push_back(p);
	p.first = 1;
	p.second = 2;
	L.push_back(p);
	p.first = 1;
	p.second = 0;
	L.push_back(p);
//	L.begin()->first = 0;
//	L.begin()->second = 2;
//	l++;
//	l->first = 0;
//	l->second = 3;
//	l++;
//	l->first = 1;
//	l->second = 2;
	map<int, set<int> > M;
	map<int, set<int> > :: iterator m = M.begin();
	M[1].insert(2);
	M[2].insert(3);
	M[2].insert(5);
	M[3].insert(2);
	M[4].insert(5);
	M[5].insert(4);
	M[6].insert(8);
	
	set<int> SS;
	
	tree<int> T;
	T.insert(T.begin(),1);
	tree<int> :: iterator t =T.begin().lchild();
	t = T.insert(t,2);
	t++;
	T.insert(t,3);
	
	/*tree_nodeset(T,SS) << endl;*/
	/*de_arista_a_adyacencia(L,M);*/
	/*connected_to(M,5,SS);*/
	
	
	m = M.begin();
	cout << "TAMAÑO " << M.size();
	cout << endl << "***MAP***" << endl;
	while( m != M.end() ){
		set<int> :: iterator s = m->second.begin();
		cout<< m->first << "->{";
		while ( s != m->second.end()){
			cout << *s << ",";
			s++;
		}
		cout << "}"<<endl;
		m++;
	}
	graph_vrtxset(M,SS);
	cout<< endl << "***SET***" << endl;
	cout << "{";
	set<int> :: iterator ss = SS.begin();
	while( ss != SS.end()){
		cout << *ss << ",";
		ss++;
	}
	cout << "}" << endl;
	
	cout << "TAMAÑO :" << SS.size();
	return 0;
}

