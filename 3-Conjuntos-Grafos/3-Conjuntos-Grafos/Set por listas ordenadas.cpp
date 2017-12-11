#include <iostream>
using namespace std;

//! ****************IMPLEMENTACION POR LISTAS ORDENADAS****************
template<class T>
typedef pair<iterator,bool> pair_t
	
pair<iterator,bool> insert (T x){
	iterator p = lower_bound(x);
	if( p == end() or *p != x ){
		p = L.insert(p,x);
		return pair_t(p,true);
	}
	else
		return pair_t(end(),false);
}

void erase (iterator p){
	L.erase(p);
}

int erase (T x){
	iterator p = lower_bound(x);
	if( p != end() and *p==x ){
		L.erase(p);
		return 1;
	}
	else
		return 0;
}

void set_union(set<T> &A, set<T> &B, set<T> &C){
	C.clear();
	list<T> :: iterator pa = A.L.begin(), pb=B.L.begin(), pc=C.L.begin();
	
	while( pa != A.L.end() and pb != B.L.end()){
		if( *pa < *pb ){
			pc = C.L.insert(pc, *pa); pa++;
		}
		else if(*pa>*pb){
			pc = C.L.insert( pc , *pb); pb++;
		}
		else{
			pc = C.L.insert(pc, *pa); pa++; pb++;
		}
		pc++;
	}
	while( pa != A.L.end()){
		pc = C.L.insert(pc, *pa);
		pa++; pc++;
	}
	while( pb != B.L.end()){
		pc = C.L.insert( pc, *pb);
		pb++; pc++;
	}
}

void set_intersection(set<T> &A, set<T> &B, set<T> &C){
	C.clear();
	list<T> :: iterator pa = A.L.begin(), pb=B.L.begin(), pc=C.L.begin();
	
	while( pa != A.L.end() and pb != B.L.end()){
		if( *pa < *pb ){
			pa++;
		}
		else if(*pa>*pb){
			pb++;
		}
		else{
			pc = C.L.insert(pc, *pa); pa++; pb++; // Insertar pa o pb en este caso seria lo mismo!
		}
		pc++;
	}
}

void set_difference( set<T> &A, set<T> &B, set<T> &C ){
	C.clear();
	list<T> :: iterator pa = A.L.begin(), pb=B.L.begin(), pc=C.L.begin();
	while( pa != A.L.end() && pb != B.L.end() ){
		
		if(*pa < *pb){
			C.L.insert(pc,*pa); pa++;
		}
		
		else if (*pa>*pb) pb++;
		
		else
			pa++; pb++;
	}
	while( pa != A.L.end()){
		pc = C.L.insert(pc, *pa) pa++; pc++;
	}
}

int main(int argc, char *argv[]) {
	
	return 0;
}

