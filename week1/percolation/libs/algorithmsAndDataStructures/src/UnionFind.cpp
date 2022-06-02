#include "../include/unionFind/UnionFind.h"

UnionFind::UnionFind(unsigned int n): m_count(n) {
    m_parent = new unsigned int[n]; 
    for (unsigned int i = 0; i < n; i++) {
        m_parent[i] = i;
        m_size[i] = 1;
    }
}

UnionFind::~UnionFind() {
    delete [] m_parent;
}

unsigned int UnionFind::root(unsigned int i) {
    while (i != m_parent[i])
        i = m_parent[i];
    return i;
}

bool UnionFind::connected(unsigned int p, unsigned int q) {
    return root(p) == root(q);
}

void UnionFind::unify(unsigned int p, unsigned int q) {
    unsigned int rootP = root(p);
    unsigned int rootQ = root(q);

    if (rootP == rootQ)
        return;
    if (m_size[rootP] < m_size[rootQ]) {
        m_parent[rootP] = rootQ;
        m_size[rootQ] += m_size[rootP];
    } else {
        m_parent[rootQ] = rootP;
        m_size[rootP] += m_size[rootQ];
    }
    m_count--;
}

unsigned int UnionFind::count() {
    return m_count;
}