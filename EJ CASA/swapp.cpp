#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
template<typename T>
void swapp( T &a, T &b){
	T aux = a;
	a = b;
	b = aux;
}


int main(int argc, char *argv[]) {
	list<int> L1; 
	list<int> L2;
	list<int> :: iterator p = L1.begin();
	list<int> :: iterator q = L2.begin();
	
	//!L1{1 2 3}
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	//!L2{4 5 6}
	L2.push_back(4);
	L2.push_back(5);
	L2.push_back(6);
	
	//!LISTAS ORIGINALES
	p = L1.begin();
	q = L2.begin();
	cout<<"L1: ";
	while( p != L1.end())
		cout<< *p++<< " ";
	cout<<endl<<"L2: ";
	while( q != L2.end())
		cout<< *q++<< " ";
	cout<<endl<<endl;
	
	//!INTERCAMBIO LAS LISTAS
	swapp(L1,L2);
	p = L1.begin();
	q = L2.begin();
	cout<<"L1: ";
	while( p != L1.end())
		cout<< *p++<< " ";
	cout<<endl<<"L2: ";
	while( q != L2.end())
		cout<< *q++<< " ";
	cout<<endl<<endl;
	
	//!INTERCAMBIO VALORES ENTRE LAS LISTAS
	p = ++L1.begin();
	q = --L2.end();
	swapp(*p,*q);
	p = L1.begin();
	q = L2.begin();
	cout<<"L1: ";
	while( p != L1.end())
		cout<< *p++<< " ";
	cout<<endl<<"L2: ";
	while( q != L2.end())
		cout<< *q++<< " ";
	cout<<endl<<endl;
	
	//!INTERCAMBIO LOS ITERATORS
	p = L1.begin(); 
	q = L1.begin(); q++;
	cout<< "p: "<<*p<<endl;
	cout<< "q: "<<*q<<endl;
	swapp(p,q);
	cout<< "p: "<<*p<<endl;
	cout<< "q: "<<*q;
	
	cout<<endl<<endl;
	
	//!INTERCAMBIO DOS ENTEROS CUALQUIERA
	int aa = 3,
		bb = 4;
	swapp(aa, bb);
	cout<<endl<<  "a: "<<aa;
	cout<<endl<<"b: "<<bb;
	return 0;
}

