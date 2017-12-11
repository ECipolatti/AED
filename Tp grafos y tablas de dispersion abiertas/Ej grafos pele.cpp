#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>


using namespace std;

typedef map<int, set<int> > gmap;
typedef vector< set<int> > graph;

// ===========================
// GRAFOS

// Determinar si un grafo simple no dirigido dado es completo
// 
// Nivel b�sico
bool es_completo(map <int, set<int> > &G){
	if (G.empty()) return true;
	map <int , set <int> >::iterator f=G.begin();
	while(f!=G.end()){
		set <int> & adj=f->second;
		if(adj.size()<(G.size()-1))return false;
		set <int>:: iterator s=adj.begin();
		
		
	}
	return true;
}


// Dado un grafo dirigido, devolver la cantidad de aristas
// 
// Nivel b�sico
int cantAristasDirigido(graph &G){
	
}


// Dado un grafo no dirigido, devolver la cantidad de aristas
//
// Nivel b�sico
int cantAristasNoDirigido(graph &G){
	
}


// Dado un grafo simple no dirigido y una lista, determinar
// si la lista corresponde a un camino euleriano.
// Esto es, si se visita cada arista exactamente una vez.
// La lista representa un camino, donde se indican los 
// nodos visitados en orden. Por ejemplo, si la lista es
// [1, 3, 4], se comienza en 1, luego se visita 3 y finalmente 4.
// La lista puede ni siquiera ser un camino v�lido (es decir, 
// puede tener nodos que no existen en el grafo), en tal caso, 
// naturalmente, se debe devolver false.
//
// Nivel intermedio
bool is_eulerian_path(gmap &G, list<int> &L){
	
}


// Dado un grafo simple no dirigido determinar si es conexo
//
// Nivel intermedio
bool es_conexo_no_dirigido(graph &G){
	
}


// Dado un grafo simple no dirigido determinar la cantidad 
// de componentes conexas.
//
// Nivel intermedio
int componentes_conexas(graph &G){
	
}


// Dado un grafo simple no dirigido conexo, determinar si es posible
// eliminar una unica arista para que el grafo deje de ser conexo.
// Dicha arista se llama "bridge" o "arista de corte".
//
// Nivel intermedio+
bool bridge(graph &G){
	
}


// Dado un grafo dirigido determinar si es d�bilmente conexo.
// Un grafo dirigido se dice que es d�bilmente conexo si el grafo
// no es conexo, pero transformando cada arista dirigida en una 
// no dirigida, s� lo es.
//
// Nivel intermedio
bool es_debilmente_conexo(gmap &G){
	
}


// Dado un grafo dirigido, determinar si es fuertemenete conexo.
// Un grafo dirigido es fuertemente conexo si para cada par de 
// v�rtices u, v, existe un camino de u a v,
// y un camino de v a u.
// 
// Nivel intermedio
bool es_fuertemente_conexo(gmap &G){
	
}


// Dado un grafo simple no dirigido conexo, determinar la 
// m�xima cantidad de aristas que se pueden eliminar para 
// que el grafo siga siendo conexo.
//
// Nivel intermedio
int cant_eliminar_aristas(graph &G){
	
}


// Dado un grafo simple no dirigido y una coloraci�n del grafo,
// determinar si la coloraci�n es v�lida.
// Una coloraci�n es v�lida cuando para cualquieras dos nodos 
// adyacentes, estos tienen distinto color.
// La coloraci�n est� dada como un map donde las keys son los 
// nodos del grafo y el value es el color correspondiente a ese 
// nodo (indicado con un entero).
//
// Nivel intermedio
bool coloracion_valida(gmap &G, map<int, int> &coloracion){
	
}


// Determinar si es posible bicolorear un grafo simple no dirigido,
// y si lo es, determinar una posible coloraci�n.
// Devolver en 'coloracion' la coloraci�n posible.
// La coloraci�n se debe indicar con un vector de enteros, 
// donde el �ndice indica el nodo y el valor el color.
//
// Nivel intermedio
bool bicolorear(graph &G, vector<int> &coloracion){
	
}


// Determinar si es posible tricolorear un grafo simple no dirigido,
// y si lo es, determinar una posible coloraci�n.
//
// Nivel avanzado
bool tricolorear(graph &G, vector<int> &coloracion){
	
}


// Determinar si es posible k-colorear un grafo simple no dirigido,
// y si lo es, determinar una posible coloraci�n.
//
// Nivel avanzado
bool kcolorear(graph &G, vector<int> &coloracion, int k){
	
}


// Determinar si es posible k-colorear un grafo simple no dirigido,
// donde algunos nodos ya vienen coloreados y no pueden cambiarse.
// Si se puede, determinar una posible coloraci�n.
// Se asegura que la coloraci�n inicial es v�lida.
// El vector coloracion ya viene con algunos nodos coloreados, 
// los nodos no coloreados tienen de valor 0.
// 
// Nivel avanzado+
bool kkcolorear(graph &G, vector<int> &coloracion, int k){
	
}


// Armar el grafo del sudoku.
// El grafo del sudoku se puede ver como una grilla 
// de nodos de tama�o 9x9 dividido en 9 zonas de 3x3, donde cada nodo tiene como 
// nodos adyacentes a todos los nodos de su misma columna, 
// todos los nodos de su misma fila, y todos los nodos 
// de su zona.
// El grafo est� representado por un:
// vector< vector< set< pair< int, int > > > >
// Es decir, una matriz, donde cada elemento de la matriz 
// es un conjunto de pares indicando los nodos adyacentes a dicho 
// elemento por medio del par (first = fila, second = columna).
//
// Nivel intermedio+
typedef vector< vector< set< pair< int, int > > > > sgraph;
sgraph sudoku_graph(){
	
}


// Resolver sudokus.
// Dado una matriz de nxn, donde algunos 
// valores son 0 y otros alg�n n�mero del 1 al 9 (inclusive).
// Reemplazar los ceros de la matriz con n�meros del 1 al 9, 
// de tal forma de resolver el sudoku correspondiente.
// Un sudoku resuelto es aquel que en una matriz de 9x9 n�meros
// del 1 al 9, dividida en 9 zonas de 3x3, resulta que 
// cada fila, cada columna, y cada zona, no tienen n�meros repetidos,
// es decir, cada fila, columna y zona contiene a 
// todos los n�meros del 1 al 9.
// Ayuda: Resolver un sudoku es lo mismo que colorear un grafo.
// El grafo a colorear es el grafo del sudoku, se debe colorear 
// con 9 colores donde algunos nodos ya vienen coloreados (aquellos 
// distintos de cero). Una 9-coloraci�n del grafo del sudoku, donde 
// los colores los enumeramos del 1 al 9, corresponde a un sudoku 
// resuelto. �Por qu�?.
//
// Nivel avanzado+
typedef vector< vector<int> > matriz;
void sudoku(matriz &M){
	
}


// ===================================
// CONJUNTOS

// Dados n conjuntos, determinar su intersecci�n.
// 
// Nivel b�sico
void interseccion(vector< set<int> > &S, set<int> &I){
	
}


// Dados n conjuntos, determinar su union.
// 
// Nivel b�sico
void uni(vector< set<int> > &S, set<int> &U){
	
}


// Dados dos conjuntos A y B, determinar 
// la diferencia A-B.
// 
// Nivel b�sico
void diferencia(set<int> &A, set<int> &B, set<int> &D){
	
}


// Dados dos conjuntos, determinar si son disjuntos.
//
// Nivel b�sico
bool disjuntos(set<int> &A, set<int> &B){
	
}


// Dado un conjunto S, determinar todas las combinaciones en C
// tomados de a k.
//
// Nivel intermedio
void combinaciones(set<int> &S, set< set<int> > &C, int k){
	
}


// Dado un conjunto, determinar su conjunto potencia.
//
// Nivel intermedio
void cpot(set<int> &S, set< set<int> > &spot){
	
}


// Dado un conjunto U y n subconjuntos de U. Determinar 
// si los subconjuntos son un exact cover de U.
// Se dice que dichos subconjuntos son un exact cover 
// de U si la uni�n de estos subconjuntos es igual a U, y 
// si estos subconjuntos son disjuntos de a pares.
// 
// Nivel intermedio
bool exact_cover(set<int> &U, vector< set<int> > &S){
	
}


// Dado un conjunto U, un conjunto S de n subconjuntos de U,
// y un entero k, k > n.
// Determinar si existe un subconjunto de S, de tama�o k, que sea 
// un exact cover de U.
//
// Nivel avanzado.
bool exact_cover(set<int> &U, vector< set<int> > &S, int k){
	
}


// Dados n conjuntos, determinar la m�nima cantidad de elementos 
// que se necesite eliminar de ellos, de forma que todos los
// conjuntos resulten disjuntos de a pares.
// Los conjuntos pueden inicialmente ser disjuntos, en tal caso la 
// respuesta es cero.
// 
// Nivel avanzado.
int eliminar_disjuntos(vector< set<int> > &S){
	
}



int main(int argc, char *argv[]) {
	
	return 0;
}

