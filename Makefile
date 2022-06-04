# created by Nicolas Bayle on 4/6/2022

CC=g++

week1: exceptions algos
	$(CC) -c -o ./build/percolation.o ./src/Percolation.cpp
	$(CC) -c -o ./build/percolationStats.o ./src/PercolationStats.cpp
	$(CC) -c -o ./build/week1Main.o ./src/week1Main.cpp
	$(CC) -o ./build/week1 ./build/unionFind.o ./build/percolation.o ./build/percolationStats.o ./build/week1Main.o

#################### libraries ####################

exceptions:

algos: UnionFind

UnionFind:
	$(CC) -c -o ./build/unionFind.o ./libs/algorithmsAndDataStructures/src/UnionFind.cpp