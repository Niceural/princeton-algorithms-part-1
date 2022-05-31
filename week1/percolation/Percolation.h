#ifndef PERCOLATION_H
#define PERCOLATION_H 

#include <iostream>
#include <vector>
#include "IllegalArgumentException.h"

class Percolation {
// private:
    unsigned int* m_grid;
    unsigned int m_size;
    unsigned int m_sizeSquared;
    unsigned int m_numberOfOpenSites;

    unsigned int m_valueForFull;
    unsigned int m_valueForTop;
    unsigned int m_valueForBottom;

    std::vector<unsigned int> m_topRoots;
    std::vector<unsigned int> m_bottomRoots;

    unsigned int m_getIndex(unsigned int, unsigned int);
    char m_position(unsigned int);
    unsigned int m_root(unsigned int);
public:
    Percolation(unsigned int);
    ~Percolation();
    void open(unsigned int, unsigned int);
    bool isOpen(unsigned int, unsigned int);
    bool isFull(unsigned int, unsigned int);
    unsigned int numberOfOpenSites();
    bool percolates();
};

#endif // PERCOLATION_H 