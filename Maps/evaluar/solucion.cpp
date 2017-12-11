#include <iostream>
#include <list>
#include "Evaluar.hpp"

using namespace std;

void acum_hasta(list<int> &L, int n)
{
	int acum = 0;
	list<int>::iterator it = L.begin();
	while (it != L.end())
	{
		acum += *it;
		it = L.erase(it);
		if (acum >= n)
		{
			L.insert(it, acum);
			acum = 0;
		}
	}
	if (acum > 0)
		L.push_back(acum);
}

list< list<int> > colas(list<int> &L)
{
	list< list<int> > R;
	if (L.empty()) return R;
	list<int>::iterator it = L.begin();
	while (it != L.end())
	{
		R.push_back(list<int>(it, L.end()));
		++ it;
	}

	return R;
}

bool checkmap(map<int, list<bool> > &M) {
	map<int, list<bool> >::iterator p = M.begin();
	while (p!=M.end()) {
		if (p->first%2==0) {
			list<bool> &L = p->second;
			list<bool>::iterator q = L.begin();
			while (q!=L.end()) 
				if (!*q++) return false;
		}
		p++;
	}
	return true;
}

void printmap(map<int, list<int> >& M) {
	cout << "M = {";
	map<int, list<int> >::iterator p = M.begin();
	while (p!=M.end()) {
		cout << p->first << "->[";
		list<int> &L = p->second;
		list<int>::iterator q = L.begin();
		while (q!=L.end()) {
			cout << *q;
			q++;
			if (q!=L.end()) cout << ", ";
		}
		cout << "]";
		p++;
		if (p!=M.end()) cout << ", ";
	}
	cout << "}";
}


int main()
{
	aed::Evaluar ev;
	ev.evaluar1(acum_hasta);
	ev.evaluar2(colas);
	ev.evaluar3(checkmap);
	ev.evaluar4(printmap);

	return 0;
}
