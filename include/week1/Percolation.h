#ifndef PERCOLATION_H
#define PERCOLATION_H 

#include <iostream>
#include <vector>

#include "../../libs/exceptions/include/IllegalArgumentException.h"
#include "../../libs/algorithmsAndDataStructures/include/unionFind/UnionFind.h"

class Percolation {
// private:
    UnionFind m_grid;
    bool *m_isSiteOpen;

    int m_size;
    int m_sizeSquared;
    int m_numberOfOpenSites;
    int m_topVirtualSite;
    int m_bottomVirtualSite;

    int rcToId(int, int);
    char position(int);

public:
    Percolation(int);
    ~Percolation();
    void open(int, int);
    bool isOpen(int, int);
    bool isFull(int, int);
    int numberOfOpenSites();
    bool percolates();
};

#endif // PERCOLATION_H 