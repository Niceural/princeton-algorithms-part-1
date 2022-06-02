#include "Percolation.h"

// initializes the size by size grid in quadratic time
Percolation::Percolation(unsigned int size):
        m_size(size),
        m_sizeSquared(size*size),
        m_numberOfOpenSites(0),
        m_valueForFull(m_sizeSquared+1),
        m_valueForTop(m_sizeSquared+2),
        m_valueForBottom(m_sizeSquared+3)
    {
    if(size >= 65536) {
        throw IllegalArgumentException();
    }

    m_grid = new unsigned int[m_sizeSquared];

    for (unsigned int i = 0; i < m_sizeSquared; i++) {
        m_grid[i] = m_valueForFull;
    }
}

unsigned int Percolation::m_getIndex(unsigned int row, unsigned int col) {
    return row * m_size + col;
}


Percolation::~Percolation() {
    delete [] m_grid;
}

void Percolation::open(unsigned int row, unsigned int col) {
    if ((row >= m_size) || (col >= m_size)) {
        throw IllegalArgumentException();
    }

    // get 1D index from 2D row and col
    unsigned int index = m_getIndex(row, col);

    // checks that site is not open
    if (m_grid[index] != m_valueForFull) {
        char position = m_position(index);
        switch (position) {
            case 't':
                if (m_grid[index+m_size] == m_valueForFull) {
                    m_grid[index] = m_valueForTop;
                } else {
                    m_grid[index] = m_root(index+m_size);
                }
                break;
            case 'b':
                if (m_grid[index-m_size] == m_valueForFull) {
                    m_grid[index] = m_valueForBottom;
                } else {
                    m_grid[index] = m_root(index-m_size);
                }
                break;
            case 'l':
                break;
            case 'r':
                break;
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            default:
                break;
        }
    }
    // check if on the sides or on top/bottom
    // check if site to left/right top/bottom is open
    // connect to root of neighbours or connect to self
    //if (m_grid[index+1])
}

char Percolation::m_position(unsigned int index) {
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

unsigned int Percolation::m_root(unsigned int i) {
    if (i == m_grid[i])
        return i;
    return m_root(m_grid[i]);
}