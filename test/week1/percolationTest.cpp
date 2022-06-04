#define BOOST_TEST_MODULE test_percolation
#include <boost/test/included/unit_test.hpp>
#include "../../include/week1/Percolation.h"

BOOST_AUTO_TEST_SUITE(opening_sites);

BOOST_AUTO_TEST_CASE(site_opens) {
    int n = 9;
    int r(3), c(7);
    Percolation p(n);
    BOOST_CHECK_EQUAL(p.isOpen(r, c), false);
    p.open(r, c);
    BOOST_CHECK_EQUAL(p.isOpen(r, c), true);
}

BOOST_AUTO_TEST_CASE(percolates) {
    int n = 3;
    Percolation p(n);
    BOOST_CHECK_EQUAL(p.percolates(), false);
    p.open(1, 2);
    BOOST_CHECK_EQUAL(p.percolates(), false);
    p.open(2, 2);
    BOOST_CHECK_EQUAL(p.percolates(), false);
    p.open(3, 2);
    BOOST_CHECK_EQUAL(p.percolates(), true);
}

BOOST_AUTO_TEST_SUITE_END();