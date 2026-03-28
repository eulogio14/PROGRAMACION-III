//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_5() {
    CommonSetup setup;
    LightDrone d1(10.0, setup.strategy1);

    auto clone = d1.clone();
    ostringstream original_before;
    ostringstream clone_before;
    original_before << d1;
    clone_before << *clone;

    REQUIRE(typeid(*clone) == typeid(d1));
    REQUIRE(original_before.str() == clone_before.str());

    clone->set_strategy(make_shared<SafeRoute>());

    ostringstream original_after;
    ostringstream clone_after;
    original_after << d1;
    clone_after << *clone;

    REQUIRE(original_after.str() != clone_after.str());
}

TEST_CASE("Question #1.5") {
    execute_test("question_1_test_5.in", test_5);
}
