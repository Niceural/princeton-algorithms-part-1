#include "../include/week1/PercolationStats.h"

PercolationStats::PercolationStats(int n, int trials): m_numberOfSites(n*n) {
    for (int i = 0; i < trials; i++) {
        srand(i);
        std::vector<int> ids(m_numberOfSites);
        for (int j=0; j < m_numberOfSites; j++) ids[j] = j;
        Percolation percolation(n);
        while (!percolation.percolates()) {
            int rn = rand() % ids.size();
            percolation.open(rn/n +1, rn%n +1);
            ids[rn] = ids.back();
            ids.pop_back();
        }
        m_minNumSites.push_back(percolation.numberOfOpenSites());
    }
    std::cout << m_minNumSites[0] << std::endl;
}
