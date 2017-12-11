#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <map>
#include "btree.h"
#include <climits>

using namespace std;
using namespace aed;

bool bst_check(btree<int> &T, btree<int> :: iterator n, int &min, int &max){
	min = INT_MAX; max = INT_MIN;
	if( n == T.end()) return true;
	//Busco el menor a la izquierda!
	btree<int> :: iterator l = n.left();
	int minl,maxl;
	if( ! bst_check(T,l,minl,maxl) || maxl >= *n ) return false;
	//Busco el menor a la derecha!
	btree<int> :: iterator r=n.right();
	int minr,maxr;
	if(!bst_check(T,r,minr,maxr) || minr < *n) return false;
	
	min = (l == T.end())? *n : minl;
	max = (r == T.end())? *n : maxr;
	return true;
}

bool bst_check(btree<int> &T){
	int min,max;
	return bst_check(T,T.begin(),min,max);
}

btree<int> :: iterator bst_min(btree<int> &T, btree<int> :: iterator n){
	if( n == T.end()) return n;
	while(true){
		btree<int> :: iterator r=n.right();
		if(r == T.end()) break;
		n=r;
	}
	return n;
}

btree<int> ::iterator bst_find(btree<int> &T, int x){
	btree<int> :: iterator n = T.begin();
	while(true){
		if( n == T.end()) return n;
		else if (x < *n) n = n.left();
		else if (x > *n) n = n.right();
		else return n;
	}
}

pair <btree<int> :: iterator, bool> bst_insert(btree<int> &T, int x){
	btree<int> :: iterator n = bst_find(T, x);
	pair <btree<int> :: iterator, bool> p ;
	
	if( n != T.end() ){
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

void bst_erase(btree<int> &T, btree<int> :: iterator n){
	btree<int> :: iterator l = n.left(), r = n.right();
	if( l == T.end() && r == T.end()){
		T.erase(n);
	}
	else if(r == T.end()){
		btree<int> tmp;
		tmp.splice(tmp.begin(),l);
		n = T.erase(n);
		T.splice(n,tmp.begin());
	}
	else if( l == T.end()){
		btree<int> tmp;
		tmp.splice(tmp.begin(),r);
		n = T.erase(n);
		T.splice(n,tmp.begin());
	}
	else{
		btree<int> :: iterator m = bst_min(T,r);
		int x = *m;
		bst_erase(T,m);
		*n = x;
	}
}

bool bst_erase(btree<int> T, int x){
	btree<int> :: iterator n = bst_find(T,x);
	if( n != T.end()){
		bst_erase (T,n);
		return true;
	}
	else return false;
}

int main() {
	
	return 0;
}

