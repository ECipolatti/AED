#include <list>
#include <map>


/*!
##################################
# Ejercicio 1
##################################
Escriba una función void acum_hasta(list<int> &L, int n) que dada una lista de enteros L, y un entero n,
modificar la lista in-place de manera que todos los elementos de la lista sean mayores o iguales a n.
La forma de hacerlo es ir acumulando valores consecutivos de L hasta que dicha condición se cumpla, dejando la suma como elemento de la lista.
Continuar hasta que todos los elementos de la lista cumplan la condición, con excepción, quizás, del último elemento.
=================================
Ejemplo:

L = [1, 3, 2, 1, 2]
n = 4

Lista resultante = [4, 5]

Procedimiento:
Si vamos acumulando los elementos consecutivamente, con los dos primeros ya llegamos a n (1+3).
A partir de ahí­, necesitamos los 3 elementos siguientes para llegar, ya que con los dos siguientes no alcanza.  
=================================
Ejemplo:

L = [3, 4, 2, 5, 1, 1]
n = 3
Lista resultante = [3, 4, 7, 2]

Procedimiento:
En este ejemplo los dos primeros valores de la lista cumplen la condición, así­ que se dejan tal cual.
Luego sigue el 2, que es menor que n, entonces se continúa acumulando, al acumularlo con el 5, se obtiene 7 que cumple la condición,
y se deja este número.  Quedan dos 1, que aunque no lleguen a la condición, se acumulan igual por ser los últimos restantes.
*/

void acum_hasta(list<int> &L, int n){
	list<int> :: iterator l = L.begin();
	while (l != L.end() ){
		if( *l >= n ){
			l++;
		}
		else{
			while (*l < n ){
				list<int> :: iterator sig = l;
				sig++;
				if( sig != L.end()){
					*l = *l + *sig;
					L.erase (sig);
				}
				else
					return;
			}
			l++;
		}
		
	}
}


/*!
##################################
## Ejercicio 2
##################################
Escribir una función:
list< list<int> > colas(list<int> &L)

Que devuelve una lista de listas de enteros, con todas las "colas" de L.
Sea una lista L = [l1, l2, ..., ln] definimos cola de una lista como una lista
Li = [lk, lk+1, ..., ln] con 1 <= k <= n.
=================================
Ejemplo:
L = [1, 2, 3]
La lista resultante debe ser:
L = [ [1, 2, 3], [2, 3], [3] ]
*/

list <list<int> > Colas (list<int> &L){
	list<int> :: iterator aux = L.begin();
	list<list<int> > LL;
	list<int> p;
	
	if(L.empty()) return LL;
	while ( aux != L.end()){
		list<int> :: iterator l = aux;
		while ( l != L.end() ){
			p.insert(p.end(), *l);
			l++;
		}
		LL.insert( LL.end(), p);
		p.clear();
		aux = L.erase(L.begin());
	}
	return LL;
}


/*!
##################################
## Ejercicio 3
##################################

Dado un map<int, list<bool> > M, verificar que para
todas las claves pares, la lista correspondiente tenga todos
sus elementos en true o bien que sea vacia. Si el map no
tiene elementos, la salida debe ser true.
**Tomado en parcial de lab 2011-09-17**.


Ejemplos:
=================================
M = {2 -> [true, true], 4 ->[]} -> returns true
M = {1 -> [false]} -> returns true
M = {2 -> [true, true, true], 3 -> [true, false]} -> returns true
M = {} -> returns true
M = {6 -> [false, true], 4 -> [true, true]} -> returns false

La funcion debe tener la siguiente signatura 
bool mostrar_map(map<int, list<bool> >&)

*/	
bool mostrar_map (map<int, list<bool> > &M){
	map<int, list<bool> > :: iterator m = M.begin();
	
	while ( m != M.end()){
		int x = m->first;
		if(x%2 == 0){
			list<bool> L = m->second;
			list<bool> :: iterator l = L.begin();
			while ( l != L.end() ){
				if ( *l == false ){
					return false;
				}
				else
					l++;
			}
		}
		m++;
	}
	return true;
}
/*!
##################################
## Ejercicio 4
##################################
Dado un map<int, list<int> > utilizar cout (se debe utilizar cout, no printf) para mostrar dicho map con el siguiente formato:

M = {0->[27, 42, 21, 6], 1->[], 2->[28, 40, 3, 3], 3->[], 4->[11, 12, 13, 36]}

Donde, para el ejemplo dado, el map tiene las keys {0, 1, 2, 3, 4} y con una flechita (->) se indica la lista correspondiente entre corchetes.
El formato debe ser tal cual, se deben respetar las comas y los espacios. NO se debe dejar un salto de línea al final (ni en ningún lugar), es decir, nunca deberían usar endl o '\n'.
Notar que las claves se indican en orden ascendiente, que corresponde al orden en que se obtienen iterando la clase map de la biblioteca estándar de C++.

La función debe tener la signatura:

void (*) (map<int, list<int> >&)

Es decir, podrían hacer la siguiente función:
void mostrar_map(map<int, list<int> >& M)
que muestra M con el formato indicado.
*/

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
