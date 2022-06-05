# created by Nicolas Bayle on 4/6/2022

CC=g++

#################### week1 ####################

week1: exceptions algs Percolation
	$(CC) -c -o ./build/percolationStats.o ./src/PercolationStats.cpp
	$(CC) -c -o ./build/week1Main.o ./src/week1Main.cpp
	$(CC) -o ./build/week1 ./build/unionFind.o ./build/percolation.o ./build/percolationStats.o ./build/week1Main.o
	
Percolation: exceptions algs
	$(CC) -c -o ./build/week1/Percolation.o ./src/Percolation.cpp

PercolationStats: exceptions algs Percolation
	$(CC) -c -o ./build/week1/PercolationStats.o ./src/PercolationStats.cpp

week1Main: exceptions algs Percolation PercolationStats
	$(CC) -c -o ./build/week1/week1Main.o ./src/week1Main.cpp
	$(CC) -o ./build/week1/week1Main ./build/algorithmsAndDataStructures/UnionFind.o ./build/week1/Percolation.o ./build/week1/PercolationStats.o ./build/week1/week1Main.o 
	./build/week1/week1Main

test_Percolation: exceptions algs Percolation
	$(CC) -c -o ./build/week1/percolationTest.o ./test/week1/percolationTest.cpp
	$(CC) -o ./build/week1/percolationTest ./build/algorithmsAndDataStructures/UnionFind.o ./build/week1/Percolation.o ./build/week1/percolationTest.o 
	./build/week1/percolationTest

#################### week2 ####################

Deque: exceptions 
	$(CC) -c -o ./build/week2/Deque.o ./src/Deque.cpp

test_Deque: Deque
	$(CC) -c -o ./build/week2/dequeTest.o ./test/week2/dequeTest.cpp
	$(CC) -o ./build/week2/dequeTest ./build/week2/Deque.o ./build/week2/dequeTest.o 
	./build/week2/dequeTest

#################### exceptions ####################

exceptions:

#################### algs ####################

algs: UnionFind

UnionFind:
	$(CC) -c -o ./build/algorithmsAndDataStructures/UnionFind.o ./libs/algorithmsAndDataStructures/src/UnionFind.cpp

test_unionFind: exceptions UnionFind
	$(CC) -c -o ./build/algorithmsAndDataStructures/test/unionFindTest.o ./libs/algorithmsAndDataStructures/test/unionFind/unionFindTest.cpp
	$(CC) -o ./build/algorithmsAndDataStructures/test/unionFindTest ./build/algorithmsAndDataStructures/unionFind.o ./build/algorithmsAndDataStructures/test/unionFindTest.o 
	./build/algorithmsAndDataStructures/test/unionFindTest