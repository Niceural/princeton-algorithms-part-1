#define BOOST_TEST_MODULE test_union_find
#include <boost/test/included/unit_test.hpp>
#include "../../include/unionFind/UnionFind.h"

BOOST_AUTO_TEST_SUITE(unification);

BOOST_AUTO_TEST_CASE(unify) {
    int n(73);
    int t1(39), t2(61);
    UnionFind uf(n);
    BOOST_CHECK_EQUAL(uf.connected(t1, t2), false);
    uf.unify(t1, t2);
    BOOST_CHECK_EQUAL(uf.connected(t1, t2), true);
}

BOOST_AUTO_TEST_SUITE_END();