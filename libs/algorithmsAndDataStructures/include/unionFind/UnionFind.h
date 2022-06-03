#ifndef UNIONFIND_H
#define UNIONFIND_H

class UnionFind {
    int * m_parent;
    int m_length;
    int * m_size;
    int m_count;

    int root(int);

public:
    UnionFind(int);
    ~UnionFind();
    bool connected(int, int);
    void unify(int, int);
    int count();
    int length();
};

#endif