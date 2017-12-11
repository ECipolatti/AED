#ifndef EVALUAR_HPP
#define EVALUAR_HPP
#include <string>
#include <map>
#include <list>
#include <sstream>
using namespace std;

namespace aed {
class Evaluar
{
	void printmap(map<int, list<bool> >& M) {
		cout << "M = {";
		map<int, list<bool> >::iterator p = M.begin();
		while (p!=M.end()) {
			cout << p->first << "->[";
			list<bool> &L = p->second;
			list<bool>::iterator q = L.begin();
			while (q!=L.end()) {
				cout << (*q ? "true" : "false");
				q++;
				if (q!=L.end()) cout << ", ";
			}
			cout << "]";
			p++;
			if (p!=M.end()) cout << ", ";
		}
		cout << "}" << endl;
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

	void s2l(string s, list<int> &L)
	{
		istringstream is(s);
		int n;
		while (is >> n)
			L.push_back(n);
	}

	void prl(list<int> &L)
	{
		if (L.empty()) return;
		list<int>::iterator il = L.begin();
		for (; &*il != &*L.rbegin(); il ++)
			cout << *il << " ";
		cout << *il;
	}

	void s2m(string s, map<int, list<bool> > &M)
	{
		M.clear();
		istringstream is(s);

		int k, n, v;
		while (is >> k >> n)
		{
			list<bool> L;

			for (int i = 0 ; i < n ; i ++)
			{
				is >> v;
				L.push_back(v);
			}
			M[k] = L;
		}
	}

	void s2m(string s, map<int, list<int> > &M)
	{
		M.clear();
		istringstream is(s);

		int k, n, v;
		while (is >> k >> n)
		{
			list<int> L;

			for (int i = 0 ; i < n ; i ++)
			{
				is >> v;
				L.push_back(v);
			}
			M[k] = L;
		}
	}

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

	public:

	void evaluar1(void (*F) (list<int>&, int))
	{
		cout << "Evaluando ejercicio 1" << endl;
		verificar1(F, "8 3 8 5 11 6 0 10 3 7 0 1 1 7 9 3 11 7 7 8", "8 11 16 16 10 9 9 14 14 8", 8);
		verificar1(F, "10 12 4 7 1 10 7 6 6 6 11 6 9 4 11 13 10 11 0 5", "10 12 11 11 7 12 17 15 15 13 10 11 5", 7);
		verificar1(F, "11 1 7 12 8 8 7 5 0 7 5 10 4 1 10 13 12 9 4 10", "31 28 26 36 23", 25);
		verificar1(F, "0 0 1 2 11 12 0 6 0 0 4 3 1 3 1 2 11 0 14 11", "26 20 25 11", 19);
		verificar1(F, "7 4 13 12 12 0 10 1 10 6 11 10 14 4 12 10 8 4 9 1", "36 33 27 30 31 1", 25);
		verificar1(F, "12 13 4 5 1 12 7 4 13 6 0 12 2 5 9 0 6 11 1 8", "25 29 23 28 26", 23);
		verificar1(F, "10 5 3 9 1 8 4 2 4 13 3 1 3 14 7 4 12 6 8 2", "10 5 3 9 1 8 4 2 4 13 3 1 3 14 7 4 12 6 8 2", 1);
		verificar1(F, "13 0 14 7 13 1 7 11 4 1 4 14 13 14 8 14 14 5 1 4", "27 20 23 32 22 28 10", 20);
		verificar1(F, "10 11 12 14 3 11 3 0 3 4 9 8 11 8 0 1 1 0 12 6", "10 11 12 14 3 11 3 3 4 9 8 11 8 14 6", 3);
		verificar1(F, "1 8 12 14 8 13 5 14 3 14 10 13 2 8 12 5 11 8 12 14", "9 12 14 8 13 5 14 17 10 13 10 12 5 11 8 12 14", 4);
		verificar1(F, "4 6 14 7 7 0 9 8 0 13 6 8 7 4 7 7 2 4 6 5", "31 37 32 24", 29);
		verificar1(F, "10 2 10 13 2 0 3 13 0 1 5 11 14 4 3 6 4 4 7 11", "22 15 16 17 14 17 22", 14);
		verificar1(F, "3 13 4 10 2 3 2 11 8 0 8 3 2 4 8 11 11 12 10 11", "16 4 10 5 13 8 8 5 4 8 11 11 12 10 11", 4);
		cout << "Fin de evaluar ejercicio 1" << endl << endl;
	}

	void verificar1(void (*F) (list<int>&, int), string s1, string s2, int n)
	{
		static int c = 1;
		cout << "Caso nº " << c ++ << ": ";
		list<int> L1, L2;
		s2l(s1, L1);
		s2l(s2, L2);
		F(L1, n);
		if (L1 != L2)
		{
			cout << "MAL" << endl;
			cout << "Para la lista: " << endl;
			cout << s1 << endl;
			cout << "con n = " << n << endl;
			cout << "La lista correcta es: " << endl;
			prl(L2); cout << endl;
			cout << "Su lista fue: " << endl;
			prl(L1); cout << endl;
			
		}
		else
			cout << "BIEN" << endl;
		cout << "------" << endl;
	}

	void evaluar2(list< list<int> > (*F) (list<int>&))
	{
		cout << "Evaluando ejercicio 2" << endl;
		list< list<int> > LL1, LL2;
		list<int> L, L2;
		L.clear(); s2l("9 1 7 7 7 8", L); L2 = L; LL1 = F(L); LL2 = colas(L2); verificar2(L, LL1, LL2);
		L.clear(); s2l("1 6 9  10 11 0 5", L); L2 = L; LL1 = F(L); LL2 = colas(L2); verificar2(L, LL1, LL2);
		L.clear(); s2l("10 4 112 9 4 10", L); L2 = L; LL1 = F(L); LL2 = colas(L2); verificar2(L, LL1, LL2);
		L.clear(); s2l("0 1 3 0 14 11", L); L2 = L; LL1 = F(L); LL2 = colas(L2); verificar2(L, LL1, LL2);
		L.clear(); s2l("711 102 10 8 4 9 1", L); L2 = L; LL1 = F(L); LL2 = colas(L2); verificar2(L, LL1, LL2);
		L.clear(); s2l("1 12 26 11 1 8", L); L2 = L; LL1 = F(L); LL2 = colas(L2); verificar2(L, LL1, LL2);
		L.clear(); s2l("1 3 14 6 8 2", L); L2 = L; LL1 = F(L); LL2 = colas(L2); verificar2(L, LL1, LL2);
		L.clear(); s2l("1 14 114 14 5 1 4", L); L2 = L; LL1 = F(L); LL2 = colas(L2); verificar2(L, LL1, LL2);
		L.clear(); s2l("19 8 1 1 0 12 6", L); L2 = L; LL1 = F(L); LL2 = colas(L2); verificar2(L, LL1, LL2);
		L.clear(); s2l("110 13 5 11 8 12 14", L); L2 = L; LL1 = F(L); LL2 = colas(L2); verificar2(L, LL1, LL2);
		L.clear(); s2l("4 7 4  6 5", L); L2 = L; LL1 = F(L); LL2 = colas(L2); verificar2(L, LL1, LL2);
		L.clear(); s2l("1 11 1 4 4 7 11", L); L2 = L; LL1 = F(L); LL2 = colas(L2); verificar2(L, LL1, LL2);
		L.clear(); s2l("33 2 41 12 10 11", L); L2 = L; LL1 = F(L); LL2 = colas(L2); verificar2(L, LL1, LL2);
		cout << "Fin de evaluar ejercicio 2" << endl << endl;
	}

	void verificar2(list<int> &L, list< list<int> > &LL1, list< list<int> > &LL2) 
	{
		static int c = 1;
		cout << "Caso nº " << c ++ << ": ";
		if (LL1 == LL2)
			cout << "BIEN" << endl;
		else
		{
			cout << "NO" << endl;
			cout << "Para la lista: ["; prl(L); cout << "]" << endl;
			cout << "Su respuesta fue: " << endl;
			cout << "[";
			for (list< list<int> >::iterator it = LL1.begin(); it != LL1.end(); it ++)
			{
				cout << "[";
				prl(*it);
				cout << "]";
				if (&*it != &*LL1.rbegin())
					cout << ", ";
			}
			cout << "]";
			cout << endl;

			cout << "La respuesta correcta es:" << endl;
			cout << "[";
			for (list< list<int> >::iterator it = LL2.begin(); it != LL2.end(); it ++)
			{
				cout << "[";
				prl(*it);
				cout << "]";
				if (&*it != &*LL2.rbegin())
					cout << ", ";
			}
			cout << "]";
			cout << endl;
			cout << endl;
		}
		cout << "------" << endl;
	}


	void verificar3(bool (*F) (map<int, list<bool> >&), string s, bool r)
	{
		static int c = 1;
		cout << "Caso nº " << c ++ << ": ";
		map<int, list<bool> > M;
		s2m(s, M);
		bool ret = F(M);
		if (ret == r)
			cout << "BIEN" << endl;
		else
		{
			cout << "==============" << endl;
			cout << "MAL" << endl;
			cout << "Para el map:" << endl;
			printmap(M);
			cout << "Tu salida fue: " << endl;
			cout << (ret ? "true" : "false") << endl;
			cout << "y deberia ser: " << endl;
			cout << (r ? "true" : "false") << endl;
			cout << "==============" << endl;
		}
		cout << "------" << endl;
	}

	void evaluar3(bool (*F) (map<int, list<bool> >&))
	{
		/*
		   M = {2 -> [true, true], 4 ->[]}
		   returns true

		   M = {1 -> [false]}
		   returns true

		   M = {2 -> [true, true, true], 3 -> [true, false]}
		   returns true

		   M = {}
		   returns true

		   M = {6 -> [false, true], 4 -> [true, true]}
		   returns false
		 */

		cout << "Evaluando ejercicio 3" << endl;
		verificar3(F, "2 2 1 1 4 0", true);
		verificar3(F, "1 1 0", true);
		verificar3(F, "2 3 1 1 1 3 2 1 0", true);
		verificar3(F, "", true);
		verificar3(F, "6 2 0 1 4 2 1 1", false);
		verificar3(F, "0 1 1 1 1 1 2 1 1 3 1 1 4 1 1 5 1 1 6 1 1", true);
		verificar3(F, "0 1 1 1 3 1 0 0 2 3 0 1 0 3 3 0 1 1 4 4 1 1 0 1 5 0 6 1 0 7 4 0 0 0 0", false);
		verificar3(F, "0 1 1 1 4 1 0 1 1 2 2 1 0 3 3 1 1 0 4 4 0 0 1 1 5 0 6 4 1 0 0 1 7 4 0 0 0 0 8 0", false);
		verificar3(F, "0 4 1 1 0 1 1 1 1", false);
		verificar3(F, "0 3 1 0 0 1 4 1 1 0 1 2 3 0 1 0 3 2 1 1 4 1 0", false);
		verificar3(F, "0 1 1 1 4 1 1 1 0 2 4 0 1 1 1 3 2 0 1 4 4 0 1 1 0 5 3 0 1 0 6 2 0 0 7 1 1", false);
		verificar3(F, "0 0 1 4 0 0 0 1 2 4 1 1 0 1 3 1 0", false);
		verificar3(F, "0 2 0 0 1 3 0 1 0", false);
		verificar3(F, "0 0 1 4 0 1 0 0 2 3 1 1 1 3 3 1 0 0 4 2 0 0 5 1 0 6 4 1 1 0 0", false);
		verificar3(F, "0 1 1 1 0 2 4 0 1 0 0 3 4 1 0 0 0 4 4 1 0 1 1 5 2 1 0 6 2 1 0 7 4 1 1 1 1 8 0", false);
		verificar3(F, "0 4 1 1 1 1 1 3 1 1 1 2 2 0 1 3 4 0 1 0 1 4 1 1 5 1 0 6 1 0", false);
		verificar3(F, "0 0 1 0 2 0 3 0 4 0 5 0 6 0 7 0 8 0 9 0 10 0 11 0 12 0 13 0 14 0 15 0", true);
		cout << "Fin de evaluar ejercicio 3" << endl << endl;
	}

	void verificar4(void (*F) (map<int, list<int> >&), string s, string r)
	{
		static int c = 1;
		cout << "Caso nº " << c ++ << ": ";
		map<int, list<int> > M;
		s2m(s, M);
		stringstream os;
		streambuf *sb = cout.rdbuf(os.rdbuf());
		F(M);
		cout.rdbuf(sb);
		if (os.str() == r)
			cout << "BIEN" << endl;
		else
		{
			cout << "==============" << endl;
			cout << "MAL" << endl;
			cout << "Tu salida fue: " << endl;
			cout << os.str() << endl;
			cout << "y deberia ser: " << endl;
			cout << r << endl;
			cout << "==============" << endl;
		}
		cout << "------" << endl;
	}

	void evaluar4(void (*F) (map<int, list<int> >&))
	{
		cout << "Evaluando ejercicio 4" << endl;
		verificar4(F, "0 1 7 1 1 49", "M = {0->[7], 1->[49]}");
		verificar4(F, "0 2 47 21 1 3 49 12 43 2 4 32 4 37 27 3 2 8 2 4 0 5 4 14 0 20 8 6 3 6 48 17", "M = {0->[47, 21], 1->[49, 12, 43], 2->[32, 4, 37, 27], 3->[8, 2], 4->[], 5->[14, 0, 20, 8], 6->[6, 48, 17]}");
		verificar4(F, "0 1 24 1 2 9 12 2 0", "M = {0->[24], 1->[9, 12], 2->[]}");
		verificar4(F, "0 3 38 6 46", "M = {0->[38, 6, 46]}");
		verificar4(F, "0 0 1 2 36 44 2 0 3 1 3 4 0 5 1 44", "M = {0->[], 1->[36, 44], 2->[], 3->[3], 4->[], 5->[44]}");
		verificar4(F, "0 1 14 1 3 5 21 28 2 2 39 39 3 4 19 48 10 20", "M = {0->[14], 1->[5, 21, 28], 2->[39, 39], 3->[19, 48, 10, 20]}");
		verificar4(F, "0 4 8 11 40 41", "M = {0->[8, 11, 40, 41]}");
		verificar4(F, "0 1 27 1 1 25 2 4 15 33 9 10", "M = {0->[27], 1->[25], 2->[15, 33, 9, 10]}");
		verificar4(F, "0 2 25 36", "M = {0->[25, 36]}");
		verificar4(F, "0 4 15 7 35 4 1 0 2 0 3 0 4 1 25 5 0", "M = {0->[15, 7, 35, 4], 1->[], 2->[], 3->[], 4->[25], 5->[]}");
		verificar4(F, "0 3 20 1 25 1 3 21 3 1", "M = {0->[20, 1, 25], 1->[21, 3, 1]}");
		verificar4(F, "0 4 16 30 2 27 1 3 32 2 23 2 1 48 3 3 25 34 43 4 3 40 46 46 5 1 5 6 0 7 0 8 2 8 25", "M = {0->[16, 30, 2, 27], 1->[32, 2, 23], 2->[48], 3->[25, 34, 43], 4->[40, 46, 46], 5->[5], 6->[], 7->[], 8->[8, 25]}");
		verificar4(F, "0 2 28 15 1 2 22 32", "M = {0->[28, 15], 1->[22, 32]}");
		verificar4(F, "0 2 9 43", "M = {0->[9, 43]}");
		verificar4(F, "0 1 16", "M = {0->[16]}");
		verificar4(F, "0 1 5 1 4 45 49 30 35 2 4 26 1 1 33 3 0", "M = {0->[5], 1->[45, 49, 30, 35], 2->[26, 1, 1, 33], 3->[]}");
		verificar4(F, "0 4 27 42 21 6 1 0 2 4 28 40 3 3 3 0 4 4 11 12 13 36", "M = {0->[27, 42, 21, 6], 1->[], 2->[28, 40, 3, 3], 3->[], 4->[11, 12, 13, 36]}");
		verificar4(F, "0 1 35 1 1 18 2 1 5 3 1 43", "M = {0->[35], 1->[18], 2->[5], 3->[43]}");
		verificar4(F, "0 1 27", "M = {0->[27]}");
		verificar4(F, "0 4 19 35 36 40", "M = {0->[19, 35, 36, 40]}");
		verificar4(F, "", "M = {}");
		cout << "Fin de evaluar ejercicio 4" << endl << endl;
	}

};

}

#endif


