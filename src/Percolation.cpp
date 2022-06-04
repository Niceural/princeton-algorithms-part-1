#include "../include/week1/Percolation.h"

Percolation::Percolation(int n):
    m_size(n),
    m_sizeSquared(n*n),
    m_grid(UnionFind(m_sizeSquared+2)), // uf for grid +2 for top and bottom virtual sites
    m_numberOfOpenSites(0),
    m_topVirtualSite(m_sizeSquared),
    m_bottomVirtualSite(m_sizeSquared+1)
{
    if((m_size > 46339) || (m_size < 1)) // m_sizeSquared would be over INT_MAX
        throw IllegalArgumentException();
    
    // initializes sites to full
    m_isSiteOpen = new bool[m_sizeSquared];
    for (int i = 0; i < m_sizeSquared; i++) {
        m_isSiteOpen[i] = false;
    }
}

void Percolation::open(int row, int col) {
    if ((row > m_size) || (row < 1) || (col > m_size) || (col < 1))
        throw IllegalArgumentException();
    if (isOpen(row, col))
        return;

    int id = rcToId(row, col);
    char pos = position(id);
    m_isSiteOpen[id] = true;
    m_numberOfOpenSites++;

    switch(pos) {
        case 't':
            m_grid.unify(id, m_topVirtualSite);
            if (m_isSiteOpen[id+m_size])
                m_grid.unify(id, id+m_size);
            break;
        case 'b':
            m_grid.unify(id, m_bottomVirtualSite);
            if (m_isSiteOpen[id-m_size])
                m_grid.unify(id, id-m_size);
            break;
        case 'l':
            if (m_isSiteOpen[id+1])
                m_grid.unify(id, id+1);
            if (m_isSiteOpen[id-m_size])
                m_grid.unify(id, id-m_size);
            if (m_isSiteOpen[id+m_size])
                m_grid.unify(id, id+m_size);
            break;
        case 'r':
            if (m_isSiteOpen[id-1])
                m_grid.unify(id, id-1);
            if (m_isSiteOpen[id-m_size])
                m_grid.unify(id, id-m_size);
            if (m_isSiteOpen[id+m_size])
                m_grid.unify(id, id+m_size);
            break;
        default:
            if (m_isSiteOpen[id+1])
                m_grid.unify(id, id+1);
            if (m_isSiteOpen[id-1])
                m_grid.unify(id, id-1);
            if (m_isSiteOpen[id-m_size])
                m_grid.unify(id, id-m_size);
            if (m_isSiteOpen[id+m_size])
                m_grid.unify(id, id+m_size);
            break;
    }
}

Percolation::~Percolation() {
    delete [] m_isSiteOpen;
}

// takes a row and a column number from 1 to m_size and
// returns the index from 1 to m_sizeSquared
int Percolation::rcToId(int row, int col) {
    return (row-1) * m_size + col-1;
}

bool Percolation::isOpen(int row, int col) {
    if ((row > m_size) || (row < 1) || (col > m_size) || (col < 1))
        throw IllegalArgumentException();
    int i = rcToId(row,col);
    return m_isSiteOpen[i];
}

bool Percolation::isFull(int row, int col) {
    if ((row > m_size) || (row < 1) || (col > m_size) || (col < 1))
        throw IllegalArgumentException();
    int i = rcToId(row,col);
    return m_grid.connected(i, m_topVirtualSite);
}

int Percolation::numberOfOpenSites() {
    return m_numberOfOpenSites;
}

bool Percolation::percolates() {
    return m_grid.connected(m_topVirtualSite, m_bottomVirtualSite);
}

// takes an index from 1 to m_sizeSquared and return a char corresponding
// to the site position in the grid
char Percolation::position(int index) {
    if (index < m_size) {
        return 't'; // if site at the top
    } else if (index >= (m_sizeSquared-m_size)) {
        return 'b'; // if site at the bottom
    } else if ((index % m_size) == 0) {
        return 'l'; // if site on the left
    } else if(((index+1) % m_size) == 0) {
        return 'r'; // if site on the right
    } else {
        return 'c'; // if site centered
    }
}