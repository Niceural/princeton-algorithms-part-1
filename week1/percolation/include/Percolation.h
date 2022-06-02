#ifndef PERCOLATION_H
#define PERCOLATION_H 

#include <iostream>
#include <vector>

#include "../libs/exceptions/include/IllegalArgumentException.h"
#include "../libs/algorithmsAndDataStructures/include/unionFind/UnionFind.h"

class Percolation {
// private:
    UnionFind m_grid;
    bool *m_isSiteOpen;

    unsigned int m_size;
    unsigned int m_sizeSquared;
    unsigned int m_numberOfOpenSites;
    unsigned int m_topVirtualSite;
    unsigned int m_bottomVirtualSite;

    unsigned int getIndex(unsigned int, unsigned int);
    char position(unsigned int);
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