#define BOOST_TEST_MODULE deque_test
#include <boost/test/included/unit_test.hpp>
#include "../../include/week2/Deque.h"

BOOST_AUTO_TEST_SUITE(push_test);

BOOST_AUTO_TEST_CASE(push_front_test) {
    Deque<int> dq;
    dq.pushFront(4);
}

BOOST_AUTO_TEST_SUITE_END();