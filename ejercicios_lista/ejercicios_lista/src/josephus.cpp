// $Id$
/*
  COMIENZO DE DESCRIPCION

7. Problema de Josephus. Un grupo de soldados se haya rodeado por una fuerza enemiga. No hay esperanzas de victoria si no llegan refuerzos y existe solamente un caballo disponible para el escape. Los soldados se ponen de acuerdo en un pacto para determinar cu\'al de ellos debe escapar y solicitar ayuda. Forman un c\'irculo y se escoge un n\'umero n al  azar. Igualmente se escoge el nombre de un soldado. Comenzando por el soldado cuyo nombre se ha seleccionado, comienzan a contar en la direcci\'on del reloj alrededor del c\'irculo. Cuando la cuenta alcanza el valor n, este soldado es retirado del c\'irculo y la cuenta comienza de nuevo, con el soldado siguiente. El proceso contin\'ua de tal manera que cada vez que se llega al valor de n se retira un soldado. El \'ultimo soldado que queda es el que debe tomar el caballo y escapar. Entonces, dados un n\'umero n y una lista de nombres, que es el ordenamiento en el sentido de las agujas del reloj de los soldados en el c\'irculo (comenzando por aqu\'el a partir del cual se inicia la cuenta), escribir un procedimiento que obtenga los nombres de los soldados en el orden que han de ser eliminados y el nombre del soldado que escapa.
  keywords: lista

  FIN DE DESCRIPCION 
*/
// -----------------------------------------------------------------
// GNU:   g++ -w -c util.cpp
//        g++ -w -c josephus.cpp
//        g++ -w -o josephus.exe util.o josephus.o
// INTEL: icc -w -c util.cpp
//        icc -w -c josephus.cpp
//        icc -w -o josephus.exe util.o josephus.o
// -----------------------------------------------------------------
#include <list>
#include <iostream>
using namespace std;

// __FUNC_START__
// -----------------------------------------------------------------
// Debe retornar una lista con las numeros relativos de soldados de
// que van saliendo segun el algoritmo de Josephus, donde "n" es la 
// cantidad de soldados y "s" es el salto en el juego
// -----------------------------------------------------------------
void josephus (int n,int s,list<int> &L) {
  list <int> H;
  list <int> :: iterator p;
  // Inicialmente carga en lista auxiliar H con los enteros [0,n]
  for (int j=0;j<n;j++) H.insert(H.end(),j);
     p=H.begin();
    // Va simulando el algoritmos extrayendo soldados de H y
    // pasandolos a L. Como hay que extraer exactamente N soldados 
    // directamente hacemos un lazo de 0 a N-1
    for (int k = 0; k < n ; k++) {
    // Avanzamos S posiciones en sentido circular por lo que nunca 
    // debe quedar en H.end (). Para evitarlo, cuando llega a
    // ser H.end () pasamos a H.begin ().
    for (int j = 0 ; j < s-1; j++) 
      if (++p == H.end()) p = H.begin (); // Notar pre-incremento
      // Pasamos el soldado en P a la lista L
      L.insert (L.end(),*p);
      // Borra en sentido circular, es decir, si P es el
      // ultimo elemento, entonces al borrar queda en H.end(), 
      // en ese caso lo pasamos a H.begin ()
      p = H.erase(p);
      if (p == H.end () ) p = H.begin ();
    } // end j
} // end void
// __FUNC_END__

// -----------------------------------------------------------------
int main() {
  list<int>  L;
  list<int>::iterator p; 

  cout << endl;
  josephus (7,4,L);
  p = L.begin();
  while (p!=L.end()) cout << *p++ << " ";
  cout << endl;

  cout << endl;
  return 0;
}
// -----------------------------------------------------------------
