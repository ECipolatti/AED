#ifndef EVALUAR_ARBOL_HPP
#define EVALUAR_ARBOL_HPP

#include <iostream>
#include <stack>
#include <queue>
#include "tree.h"
#include "util_tree.h"
#include <string>
#include <list>
#include <sstream>

namespace aed
{
using namespace std;
class EvaluarArbol
{
	int readnum(string &s, unsigned int &n)
	{
		int k = 0;
		bool negativo = false;
		if (s[n] == '-')
		{
			negativo = true;
			n ++;
		}

		while (s[n] >= '0' && s[n] <= '9')
		{
			k *= 10;
			k += s[n] - '0';
			++ n;
		}

		if (negativo) k *= -1;

		return k;
	}

	void s2t(string s, tree<int> &T, unsigned int &i, tree<int>::iterator it)
	{
		while (i < s.size())
		{
			while (s[i] == ' ') ++ i;

			if (s[i] == '(')
			{
				++ i;
				while (s[i] == ' ') ++ i;
				it = T.insert(it, readnum(s, i));
				s2t(s, T, i, it.lchild());
				++ it;
			}
			else if (s[i] == ')')
			{
				++ i;
				return;
			}
			else
			{
				it = T.insert(it, readnum(s, i));
				++ it;
			}
		}
	}

	void s2t(string s, tree<int> &T)
	{
		unsigned int i = 0;
		s2t(s, T, i, T.begin());
	}
public:

	// Ejercicio 1
	/*
	Escribir una función 'bool tree_equal(tree<int> &T1, tree<int> &T2)' que devuelve
	true si T1 y T2 son iguales. Que sean iguales significa que tengan la misma forma 
	y los mismos valores en cada nodo.

	Ejemplos:
	T1 = (1 2 (3 4 5))
	T2 = (1 2 (3 4 5))
	Son iguales

	T1 = (1 (3 4 5) 2)
	T2 = (1 2 (3 4 5))
	No son iguales
	*/
	void verificar1(string s1, string s2, bool r, bool (*F) (tree<int>&, tree<int>&))
	{
		tree<int> T1, T2;
		s2t(s1, T1);
		s2t(s2, T2);
		bool b = F(T1, T2);
		if (b == r)
		{
			cout << "Bien" << endl;
		}
		else
		{
			cout << endl;
			cout << "Mal" << endl;
			cout << "T1 = " << s1 << endl;
			cout << "T2 = " << s2 << endl;
			cout << "Respuesta correcta: " << (r ? "true" : "false") << endl;
			cout << endl << endl;
		}
	}

	void evaluar1(bool (*F) (tree<int>&, tree<int>&))
	{
		cout << "Evaluando ejercicio 1" << endl;
		verificar1("1", "1", true, F);
		verificar1("1", "2", false, F);
		verificar1("2", "1", false, F);
		verificar1("(1 2)", "(1 2)", true, F);
		verificar1("(1 2)", "(2 1)", false, F);
		verificar1("(1 (2 3 4))", "(1 (2 3 4))", true, F);
		verificar1("(1 (2 4))", "(1 (2 4))", true, F);
		verificar1("(1 (4 4))", "(1 (4 4))", true, F);
		verificar1("(1 (4 (4 3 2 1)))", "(1 (4 (4 3 2 1)))", true, F);
		verificar1("(1 (2 (3 (4 (5 6)))))", "(1 (2 (3 (4 (5 6)))))", true, F);
		verificar1("(1 (1 1 1) 5 (2 (3 (4 (5 6)))))", "(1 (1 1 1) 5 (2 (3 (4 (5 6)))))", true, F);
		verificar1("(1 (1 2 1) 5 (2 (3 (4 (5 6)))))", "(1 (1 1 1) 5 (2 (3 (4 (5 6)))))", false, F);
		verificar1("(1 (1 1 1) 5 (2 (3 (4 (5 6)))))", "(1 (1 1 1) 5 (2 (3 (6 (5 6)))))", false, F);
		verificar1("(1 (1 1 1) 5 (2 (3 (4 (5 9)))))", "(1 (1 1 1) 5 (2 (3 (4 (5 6)))))", false, F);
		verificar1("", "", true, F);
		verificar1("1", "", false, F);
		verificar1("", "1", false, F);
		cout << "Se termino de evaluar el ejercicio 1" << endl << endl;
	}

	// Ejercicio 2
	/*

	Escribir una funcion 'bool erasing_equal(tree<int> &T1, tree<int> &T2)' que devuelva 
	true si es posible obtener T1 aplicando erases sobre T2. Tener en cuenta que 
	al borrar un nodo, se borra todo el subárbol.
	   
	Ejemplos:
	T1 = (1 3 (4 5 6))
	T2 = (1 (2 11 12) 3 (4 5 (6 9 10) 7))
	Devuelve true.
	Si de T2 borramos el los subárboles (2 11 12), 7, 9, 10, obtenemos T1.

	T1 = (1 3 4)
	T2 = (1 (2 11 12) 3 (4 5 (6 9 10) 7))
	Devuelve true.
	De T2 se borra (2 11 12), 5, (6 9 10) y 7.

	T1 = (1 4 3)
	T2 = (1 (2 11 12) 3 (4 5 (6 9 10) 7))
	Devuelve false.
	En T1 el nodo con valor 3 está a la derecha del 4, es imposible lograr 
	esto borrando elementos de T2.

	*/
	void evaluar2(bool (*F) (tree<int>&, tree<int>&))
	{
		cout << "Evaluando ejercicio 2" << endl;
		verificar1("(1 3 (4 5 6))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 3 (4 7 6))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", false, F);
		verificar1("(1 3 (4 5 7))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 3 (4 5))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 3 (4 5 6 7))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 3 (4 5 (6 9) 7))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 3 (4 5 (6 10) 7))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 3 (4 5 (6 9 10) 7))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 3 (4 (6 9 10) 7))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 3 (4 5 (6 9 10)))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 3 (4 (6 9 10)))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 3)", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 (2 11 12))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 (2 12 11))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", false, F);
		verificar1("(3 3 (4 5 (6 9 10) 7))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", false, F);
		verificar1("(1 (3 5 (6 9 10) 7))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", false, F);
		verificar1("(1 3 (4 (5 2) 6))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", false, F);
		verificar1("(1 (4 (6 9)))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 (4 (6 10)))", "(1 (2 11 12) 3 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 4 (4 5 6))", "(1 (2 11 12) 4 (4 5 (6 9 10) 7))", true, F);
		verificar1("(1 4)", "(1 (2 11 12) (4 5 (6 9 10) 7) 4)", true, F);
		verificar1("(1 4 4)", "(1 (2 11 12) (4 5 (6 9 10) 7) 4)", true, F);
		verificar1("(1 (4 6) 4)", "(1 (2 11 12) (4 5 (6 9 10) 7) 4)", true, F);
		verificar1("1", "(1 (2 11 12) (4 5 (6 9 10) 7) 4)", true, F);
		verificar1("", "(1 (2 11 12) (4 5 (6 9 10) 7) 4)", true, F);
		verificar1("", "", true, F);
		verificar1("", "(42 24)", true, F);
		verificar1("(1 (2 (3 (4 5))))", "", false, F);
		cout << "Se termino de evaluar el ejercicio 2" << endl << endl;
	}

	// Ejercicio 3
	/*
	Escribir una función 'void colapsar_nodo(tree<int>& T, int n)' donde se debe 
	eliminar el nodo que tiene de valor n, pero no todo el subarbol. Sino, subir de nivel sus hijos.
	El arbol no tiene valores repetidos, y n no representa a la raiz.

	Ejemplos:
	T = (1 (2 3 4))
	n = 2
	T debe quedar: (1 3 4)
	Los hijos de 2 se suben de nivel y el 2 se borra.

	T = (1 (2 (3 4) 5))
	n = 2
	T debe quedar: (1 (3 4) 5)
	Los subarboles hijos de 2 suben de nivel, y el 2 se borra.
	*/
	bool te(tree<int> &T1, tree<int> &T2, tree<int>::iterator it1, tree<int>::iterator it2)
	{
		if (it1 == T1.end() && it2 == T2.end())
			return true;

		if ((it1 == T1.end()) xor (it2 == T2.end()))
			return false;

		if (*it1 != *it2)
			return false;

		return (te(T1, T2, it1.lchild(), it2.lchild()) &&
			te(T1, T2, ++ it1, ++ it2));
	}

	bool te(tree<int> &T1, tree<int> &T2)
	{
		return te(T1, T2, T1.begin(), T2.begin());
	}

	void verificar3(string s1, string s2, int n, void (*F) (tree<int>&, int))
	{
		tree<int> T1, T2;
		s2t(s1, T1);
		s2t(s2, T2);
		F(T1, n);

		bool b = te(T1, T2);
		
		if (b)
		{
			cout << "Bien" << endl;
		}
		else
		{
			cout << endl;
			cout << "Mal" << endl;
			cout << "T = " << s1 << endl;
			cout << "nodo = " << n << endl;
			cout << "Respuesta correcta: " << s2 << endl;
			cout << "Tu respuesta fue:   ";
			T1.lisp_print();
			cout << endl;
			cout << endl << endl;
		}
	}

	void evaluar3(void (*F) (tree<int>&, int))
	{
		cout << "Evaluando ejercicio 3" << endl;
		verificar3("(1 (2 5 6) (3 7) (4 (8 10 11) 9))", "(1 (2 5 6) (3 7) (8 10 11) 9)", 4, F);
		verificar3("(1 (2 5 6) (3 7) (4 (8 10 11) 9))", "(1 5 6 (3 7) (4 (8 10 11) 9))", 2, F);
		verificar3("(1 (2 5 6) (3 7) (4 (8 10 11) 9))", "(1 (2 5 6) (3 7) (4 10 11 9))", 8, F);
		verificar3("(1 (2 5 6) (3 7) (4 (8 10 11) 9))", "(1 (2 5 6) (3 7) (4 (8 10 11) 9))", 42, F);
		verificar3("(1 (2 5 6) (3 7) (4 (8 10 11) 9))", "(1 (2 5 6) 3 (4 (8 10 11) 9))", 7, F);
		verificar3("(1 (2 5 6) (3 7) (4 (8 10 11) 9))", "(1 (2 5 6) (3 7) (4 (8 10) 9))", 11, F);
		verificar3("(1 (2 (3 (4 (5 6)))))", "(1 (2 (3 (4 (5 6)))))", 42, F);
		verificar3("(1 (2 (3 (4 (5 6)))))", "(1 (3 (4 (5 6))))", 2, F);
		verificar3("(1 (2 (3 (4 (5 6)))))", "(1 (2 (4 (5 6))))", 3, F);
		verificar3("(1 (2 (3 (4 (5 6) 7) 8) 9) 10)", "(1 (2 (4 (5 6) 7) 8 9) 10)", 3, F);
		cout << "Se termino de evaluar el ejercicio 3" << endl << endl;
	}
	// Ejercicio 4
	/*
	Escribir una funcion 'void unir_suma (tree<int> &T1, tree<int> &T2)', donde T2 es un arbol vacio.
	Todos los nodos de T1 que tienen un solo hijo deben unirse con su hijo y en dicho nodo debe quedar 
	como valor la suma de su valor mas la de su hijo. El arbol resultante se debe guardar en T2.
	Notar que el arbol resultante no tendrá ningún nodo con sólamente un hijo.

	Ejemplos:
	T1 = (1 1)
	T2 debe quedar = 1 (un solo nodo raiz = 1)

	T1 = (1 (4 6) 2)
	T2 debe quedar = (1 10 2), notar que el nodo 4 tiene un solo
	hijo, el 6, entonces se unen y queda la suma, 10 = 4 + 6

	T1 = (1 2 (1 (1 1)))
	T2 debe quedar = (1 2 3)
	Ahora hay dos nodos que tienen un solo hijo, se 
	deben unir todos, entonces 3 = 1 + 1 + 1

	T1 = (1 (2 (2 (3 1 5))) (4 6 (7 8)))
	T2 debe quedar = (1 (7 1 5) (4 6 15))
	*/
	void verificar4(string s1, string s2, void (*F) (tree<int>&, tree<int>&))
	{
		tree<int> T1, T2, T3;
		s2t(s1, T1);
		s2t(s2, T2);
		F(T1, T3);

		bool b = te(T2, T3);
		
		if (b)
		{
			cout << "Bien" << endl;
		}
		else
		{
			cout << endl;
			cout << "Mal" << endl;
			cout << "T1 = " << s1 << endl;
			cout << "Respuesta correcta T2 = " << s2 << endl;
			cout << "Tu respuesta fue T2   = ";
			T3.lisp_print();
			cout << endl;
			cout << endl << endl;
		}
	}

	void evaluar4(void (*F) (tree<int>&, tree<int>&))
	{
		cout << "Evaluando ejercicio 4" << endl;
		verificar4("(1 (2 (2 (3 1 5))) (4 6 (7 8)))", "(1 (7 1 5) (4 6 15))", F);
		verificar4("(1 (2 (3 (3 1 5))) (4 6 (7 8)))", "(1 (8 1 5) (4 6 15))", F);
		verificar4("(1 (2 (3 (4 (5 6)))))", "21", F);
		verificar4("(1 (2 (3 (4 (5 6)))) 2)", "(1 20 2)", F);
		verificar4("(1 (2 (3 (4 (5 6))) 2))", "(3 18 2)", F);
		verificar4("(1 (2 (3 (4 (5 6)) 2)))", "(6 15 2)", F);
		verificar4("(1 (2 (3 (4 (5 6) 2))))", "(10 11 2)", F);
		verificar4("(1 (2 (3 (4 (5 6 2)))))", "(15 6 2)", F);
		verificar4("(0 (0 (0 (0 (0 (0 0))))) (0 (0 (0 (0 (0 0))))))", "(0 0 0)", F);
		verificar4("(0 (0 (0 (0 (0 (0 1))))) (0 (0 (0 (0 (1 1))))))", "(0 1 2)", F);
		verificar4("(1 (1 (1 1) (1 (1 1) (1 (1 1) 1))) (1 41))", "(1 (1 2 (1 2 (1 2 1))) 42)", F);
		cout << "Se termino de evaluar el ejercicio 4" << endl << endl;
	}

	// Ejercicio 5
	/*
	Escribir una funcion 'void suma_nivel (tree<int> &T, list<int> &L)' que cargue 
	en L la suma de todos los nodos de cada nivel de T,
       	ordenados del nivel menor al mayor, siendo el 
	primer nivel el correspondiente a la raiz.

	Ejemplos:
	T = (1 (2 (3 (4))))
	L debe quedar = [1 2 3 4]
	Cada nivel tiene un solo nodo

	T = (1 1 1)
	L debe quedar = [1 2]
	El ultimo nivel tiene dos nodos con valor 1, la suma es 2.

	T = (3 1 (1 4 4) (2 (2 1) 5))
	L debe quedar = [3 4 15 1]
	*/
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

	void verificar5(string s1, string s2, void (*F) (tree<int>&, list<int>&))
	{
		tree<int> T;
		list<int> L1, L2;
		s2t(s1, T);
		s2l(s2, L1);
		F(T, L2);

		bool b = (L1 == L2);
		
		if (b)
		{
			cout << "Bien" << endl;
		}
		else
		{
			cout << endl;
			cout << "Mal" << endl;
			cout << "T1 = " << s1 << endl;
			cout << "Respuesta correcta L = [" << s2 << "]" << endl;
			cout << "Tu respuesta fue L =   [";
			prl(L2);
			cout << "]" << endl;
			cout << endl << endl;
		}
	}

	void evaluar5(void (*F) (tree<int>&, list<int>&))
	{
		cout << "Evaluando ejercicio 5" << endl;
		verificar5("(3 1 (1 4 4) (2 (2 1) 5)", "3 4 15 1", F);
		verificar5("(1 1 (1 4 4) (2 (2 1) 5)", "1 4 15 1", F);
		verificar5("1", "1", F);
		verificar5("0", "0", F);
		verificar5("(5 (5 5 5) (5 5 5) (5 5 5))", "5 15 30", F);
		verificar5("(1 1 1 1 1 1 1 1 1 1 1)", "1 10", F);
		verificar5("(1 (1 1) (1 1) (1 1) (1 1) (1 1) (1 1) (1 1) (1 1) (1 1) (1 1))", "1 10 10", F);
		verificar5("(1 (1 2) (1 2) (1 2) (1 2) (1 2) (1 2) (1 2) (1 2) (1 2) (1 2))", "1 10 20", F);
		verificar5("(1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 1)))))))))))))", "1 1 1 1 1 1 1 1 1 1 1 1 1 1", F);
		verificar5("(1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 1)))))))))))) 1)", "1 2 1 1 1 1 1 1 1 1 1 1 1 1", F);
		verificar5("(1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 1))))))))))) 1))", "1 1 2 1 1 1 1 1 1 1 1 1 1 1", F);
		verificar5("(1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 1)))))))))) 1)))", "1 1 1 2 1 1 1 1 1 1 1 1 1 1", F);
		verificar5("(1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 1))))))))) 1))))", "1 1 1 1 2 1 1 1 1 1 1 1 1 1", F);
		verificar5("(1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 1)))))))) 1)))))", "1 1 1 1 1 2 1 1 1 1 1 1 1 1", F);
		verificar5("(1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 1))))))) 1))))))", "1 1 1 1 1 1 2 1 1 1 1 1 1 1", F);
		verificar5("(1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 1)))))) 1)))))))", "1 1 1 1 1 1 1 2 1 1 1 1 1 1", F);
		verificar5("(1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 1))))) 1))))))))", "1 1 1 1 1 1 1 1 2 1 1 1 1 1", F);
		verificar5("(1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 1)))) 1)))))))))", "1 1 1 1 1 1 1 1 1 2 1 1 1 1", F);
		verificar5("(1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 1))) 1))))))))))", "1 1 1 1 1 1 1 1 1 1 2 1 1 1", F);
		verificar5("(1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 1)) 1)))))))))))", "1 1 1 1 1 1 1 1 1 1 1 2 1 1", F);
		verificar5("(1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 1) 1))))))))))))", "1 1 1 1 1 1 1 1 1 1 1 1 2 1", F);
		verificar5("(1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 (1 1 1)))))))))))))", "1 1 1 1 1 1 1 1 1 1 1 1 1 2", F);
		cout << "Se termino de evaluar el ejercicio 5" << endl << endl;
	}

};
} // namespace aed

#endif
