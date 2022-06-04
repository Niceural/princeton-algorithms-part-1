#ifndef PERCOLATIONSTATS_H
#define PERCOLATIONSTATS_H

#include <random>
#include <vector>
#include <iostream>

#include "./Percolation.h"

class PercolationStats {
// private:
    int m_numberOfSites;
    std::vector<int> m_minNumSites;

public:
    PercolationStats(int, int);
    double mean();
    double stddev();
    double confidenceLo();
    double confidenceHi();
};

#endif // PERCOLATIONSTATS_H