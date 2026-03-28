//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_6() {
    CommonSetup setup;

    LightDrone original(10.0, setup.strategy1);
    LightDrone copy = original;

    ostringstream original_before;
    ostringstream copy_before;
    original_before << original;
    copy_before << copy;

    REQUIRE(copy.calculate_range() == original.calculate_range());
    REQUIRE(original_before.str() == copy_before.str());

    copy.set_strategy(make_shared<SafeRoute>());

    ostringstream original_after;
    ostringstream copy_after;
    original_after << original;
    copy_after << copy;

    REQUIRE(original_after.str() != copy_after.str());
}

TEST_CASE("Question #1.6") {
    execute_test("question_1_test_6.in", test_6);
}
