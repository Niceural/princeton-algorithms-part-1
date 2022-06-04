#include "../include/week1/PercolationStats.h"

int main() {
    //PercolationStats perco(20, 1);
    Percolation per(3);
    per.open(1, 2);
    per.open(2, 2);
    per.open(3, 2);
    std::cout << per.percolates() << std::endl;
    return 0;
}