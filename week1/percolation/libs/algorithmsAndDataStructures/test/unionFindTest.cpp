#define BOOST_TEST_MODULE boost_test_macro3
#include <boost/test/included/unit_test.hpp>
#include <iostream>

#include "../include/unionFind/UnionFind.h"

BOOST_AUTO_TEST_CASE(test_op_reportings) {
    unsigned int n = 197;
    UnionFind uf(n);
    unsigned int count = uf.count();
    std::cout << count << std::endl;
    BOOST_TEST(count == n);
}