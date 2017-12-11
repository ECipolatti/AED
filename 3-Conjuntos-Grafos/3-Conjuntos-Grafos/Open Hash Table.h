#include <iostream>
#include <vector>
#include <list>
using namespace std;

//! ================= TABLAS DE DISPERSION =================

bool oht_find( vector<list<int> > &table, unsigned int (*hash) ( const int&),
				const int &value, unsigned int &bucket,
				list<int> :: iterator &position){
	
	unsigned int B = table.size();
	unsigned int h = hash(value);
	bucket = h%B;        //Tomo el numero de la cubeta del resto entre el size del vec y el valor de retorno del hash!
	list<int> &L = table[bucket]; //Tomo la lista que voy a manejar del vector
	position = L.begin();
	
	while( position != L.end()){
		if( *position == value)
			return true;
		position++;
	}
	
	return false;
	
	
}

bool oht_insert(vector<list<int> > &table, unsigned int (*hash) ( const int&),
				const int &value, unsigned int &bucket,
				list<int> :: iterator &position){
	
	bool found = oht_find( table,hash,value,bucket,position);
	
	if(found) return false; //Si lo encontro no inserta y retorna falso!
	
	position = table[bucket].insert(position,value); //La cubeta donde deberia quedar inserta se determina en el find y la devuelve por referencia
	return true;
}

bool oht_erase(vector<list<int> > &table, unsigned int (*hash) ( const int&),
				const int &value){
	
	unsigned int bucket;
	list<int> :: iterator position;
	bool found = oht_find(table,hash,value,bucket,position);
	
	if(!found) return false; // Si no lo encontro retorna falso!
	
	table[bucket].erase(position);//La cubeta donde deberia quedar inserta se determina en el find y la devuelve por referencia luego uso el erase de list;
	return true;
}

void oht_clear(vector<list<int> > &table){
	for (int i = 0 ; i<table.size(); i++){
		table[i].clear();
	}
}
