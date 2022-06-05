#ifndef PERCOLATIONSTATS_H
#define PERCOLATIONSTATS_H

#include <random>
#include <vector>
#include <iostream>
#include <cmath>
#include <ctime>

#include "./Percolation.h"

class PercolationStats {
// private:
    int m_size;
    int m_numberOfSites;
    int m_numOfTrials;
    std::vector<int> m_percolationThreshold;

    double m_mean;
    double m_stddev;
    double m_confLo;
    double m_confHi;

    int computePercolationThreshold();

public:
    PercolationStats(int, int);
    double mean();
    double stddev();
    double confidenceLo();
    double confidenceHi();
};

#endif // PERCOLATIONSTATS_H