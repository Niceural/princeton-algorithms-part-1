#include "../include/week1/PercolationStats.h"

PercolationStats::PercolationStats(int n, int trials): 
    m_size(n),
    m_numberOfSites(n*n),
    m_numOfTrials(trials),
    m_mean(0.0),
    m_stddev(0.0),
    m_confLo(0.0),
    m_confHi(0.0) 
{
    std::srand(2/*std::time(0)*/);
    for (int i(0); i < m_numOfTrials; i++) {
        int percThre = computePercolationThreshold();
        m_percolationThreshold.push_back(percThre);
    }
}

int PercolationStats::computePercolationThreshold() {
    Percolation perco(m_size);
    int rn(0);
    int site(0);

    std::vector<int> sites(m_numberOfSites);
    for (int i(0); i < sites.size(); i++) sites[i] = i;

    while(!perco.percolates()) {
        //std::cout << sites.size() << std::endl;
        rn = std::rand() % sites.size();
        //std::cout << rn << std::endl;
        site = sites[rn];
        //std::cout << site/m_size+1 << ", " << site%m_size+1 << std::endl;
        perco.open(site/m_size+1, site%m_size+1);
        sites[rn] = sites.back();
        sites.pop_back();
    }
    return perco.numberOfOpenSites();
}

double PercolationStats::mean() {
    m_mean = 0.0;
    for (int i: m_percolationThreshold)
        m_mean += i;
    m_mean /= m_numOfTrials * m_numberOfSites;
    return m_mean;
}

double PercolationStats::stddev() {
    if (m_mean == 0) m_mean = mean();
    m_stddev = 0.0;
    for (int i: m_percolationThreshold) {
        m_stddev += (i-m_mean) * (i-m_mean);
    }
    m_stddev /= m_numOfTrials -1;
    m_stddev = std::sqrt(m_stddev);
    return m_stddev;
}

double PercolationStats::confidenceLo() {
    if (m_mean == 0) m_mean = mean();
    if (m_stddev == 0) m_stddev = stddev();
    m_confLo = m_mean - 1.96 * m_stddev / std::sqrt(m_numOfTrials);
    return m_confLo;
}

double PercolationStats::confidenceHi() {
    if (m_mean == 0) m_mean = mean();
    if (m_stddev == 0) m_stddev = stddev();
    m_confLo = m_mean + 1.96 * m_stddev / std::sqrt(m_numOfTrials);
    return m_confHi;
}