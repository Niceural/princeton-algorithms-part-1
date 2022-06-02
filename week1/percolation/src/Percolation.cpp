#include "../include/Percolation.h"

Percolation::Percolation(unsigned int n):
    m_grid(n*n+2), // uf for grid +2 for top and bottom virtual sites
    m_size(n),
    m_sizeSquared(n*n),
    m_numberOfOpenSites(0),
    m_topVirtualSite(0),
    m_bottomVirtualSite(m_sizeSquared+1)
{
    if(m_size >= 65536)
        throw IllegalArgumentException();
    
    // initializes sites to full
    m_isSiteOpen = new bool[m_sizeSquared];
    for (unsigned int i = 0; i < m_sizeSquared; i++) {
        m_isSiteOpen[i] = false;
    }
}

void Percolation::open(unsigned int row, unsigned int col) {

}

Percolation::~Percolation() {
    delete [] m_isSiteOpen;
}

// takes a row and a column number from 1 to m_size and
// returns the index from 1 to m_sizeSquared
unsigned int Percolation::getIndex(unsigned int row, unsigned int col) {
    return (row-1) * m_size + col;
}

bool Percolation::isOpen(unsigned int row, unsigned int col) {
    unsigned int i = getIndex(row,col) - 1;
    return m_isSiteOpen[i];
}

bool Percolation::isFull(unsigned int row, unsigned int col) {
    unsigned int i = getIndex(row,col) - 1;
    return !m_isSiteOpen[i];
}

unsigned int Percolation::numberOfOpenSites() {
    return m_numberOfOpenSites;
}

bool Percolation::percolates() {
    return m_grid.connected(m_topVirtualSite, m_bottomVirtualSite);
}

char Percolation::position(unsigned int index) {
    if (index < m_size) {
        if ((index % m_size) == 0) {
            return '1'; // if site in top left corner
        } else if ((index % m_size + 1) == 0) {
            return '2'; // if site in top right corner
        } else {
            return 't'; // if site at the top
        }
    } else if (index >= (m_sizeSquared-m_size)) {
        if ((index % m_size) == 0) {
            return '3'; // if site at bottom left corner
        } else if ((index % m_size + 1) == 0) {
            return '4'; // if site at bottom right corner
        } else {
            return 'b'; // if site at the bottom
        }
    } else if ((index % m_size) == 0) {
        return 'l'; // if site on the left
    } else if((index % m_size + 1) == 0) {
        return 'r'; // if site on the right
    } else {
        return 'c'; // if site centered
    }
}