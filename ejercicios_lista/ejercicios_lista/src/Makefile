all: junta random_shuffle intercala creciente ordenag particiona rejunta ascendente chunk-revert encuentra reemplaza concatena refina print_back sorted_list1 sorted_list2 sorted_list3 cadena_pq josephus

junta: util.o junta.cpp
	g++ $^ -o bin/junta.out

josephus: util.o josephus.cpp
	g++ $^ -o bin/josephus.out

nilpot: util.o nilpot.cpp
	g++ $^ -o bin/nilpot.out

espermut: util.o espermut.cpp
	g++ $^ -o bin/espermut.out

es_biyectiva: util.o es_biyectiva.cpp
	g++ $^ -o bin/es_biyectiva.out

propsubset: util.o propsubset.cpp
	g++ $^ -o bin/propsubset.out

ismapset: util.o ismapset.cpp
	g++ $^ -o bin/ismapset.out

incluido: util.o incluido.cpp
	g++ $^ -o bin/incluido.out

cadena_pq: util.o cadena_pq.cpp
	g++ $^ -o bin/cadena_pq.out

sorted_list1: util.o sorted_list1.cpp
	g++ $^ -o bin/sorted_list1.out

sorted_list2: util.o sorted_list2.cpp
	g++ $^ -o bin/sorted_list2.out

sorted_list3: util.o sorted_list3.cpp
	g++ $^ -o bin/sorted_list3.out

print_back: util.o print_back.cpp
	g++ $^ -o bin/print_back.out

refina: util.o refina.cpp
	g++ $^ -o bin/refina.out

concatena: util.o concatena.cpp
	g++ $^ -o bin/concatena.out

reemplaza: util.o reemplaza.cpp
	g++ $^ -o bin/reemplaza.out

encuentra: util.o encuentra.cpp
	g++ $^ -o bin/encuentra.out

chunk-revert: util.o chunk-revert.cpp
	g++ $^ -o bin/chunk-revert.out

ascendente: util.o ascendente.cpp
	g++ $^ -o bin/ascendente.out

rejunta: util.o rejunta.cpp
	g++ $^ -o bin/rejunta.out

particiona: util.o particiona.cpp
	g++ $^ -o bin/particiona.out

ordenag: util.o ordenag.cpp
	g++ $^ -o bin/ordenag.out

creciente: util.o creciente.cpp
	g++ $^ -o bin/creciente.out

intercala: util.o intercala.cpp
	g++ $^ -o bin/intercala.out

random_shuffle: util.o random_shuffle.cpp
	g++ $^ -o bin/random_shuffle.out

.PHONY: clean

clean:
	rm *.o bin/*.out
