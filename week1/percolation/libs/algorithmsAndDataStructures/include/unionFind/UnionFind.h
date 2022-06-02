#ifndef UNIONFIND_H
#define UNIONFIND_H

class UnionFind {
    unsigned int * m_parent;
    unsigned int * m_size;
    unsigned int m_count;

    unsigned int root(unsigned int);

public:
    UnionFind(unsigned int);
    ~UnionFind();
    bool connected(unsigned int, unsigned int);
    void unify(unsigned int, unsigned int);
    unsigned int count();
};

#endif