#include "../include/unionFind/UnionFind.h"
#include "../../exceptions//include/IllegalArgumentException.h"

UnionFind::UnionFind(int n): m_count(n), m_length(n) {
    if (n < 1)
        throw IllegalArgumentException();

    m_parent = new int[m_length]; 
    m_size = new int[m_length];

    for (unsigned int i = 0; i < n; i++) {
        m_parent[i] = i;
        m_size[i] = 1;
    }
}

UnionFind::~UnionFind() {
    delete [] m_parent;
    delete [] m_size;
}

int UnionFind::root(int i) {
    while (i != m_parent[i])
        i = m_parent[i];
    return i;
}

bool UnionFind::connected(int p, int q) {
    if ((p > m_length) || (p < 0) || (q > m_length) || (q < 0)) {
        throw IllegalArgumentException();
    }
    return root(p) == root(q);
}

void UnionFind::unify(int p, int q) {
    if ((p >= m_length) || (p < 0) || (q >= m_length) || (q < 0)) {
        throw IllegalArgumentException();
    }

    int rootP = root(p);
    int rootQ = root(q);

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

int UnionFind::count() {
    return m_count;
}

int UnionFind::length() {
    return m_length;
}