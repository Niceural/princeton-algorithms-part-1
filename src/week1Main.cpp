#include "../include/week1/PercolationStats.h"

int main() {
    PercolationStats perco(200, 100);
    std::cout << "mean: " << perco.mean() << std::endl;
    return 0;
}