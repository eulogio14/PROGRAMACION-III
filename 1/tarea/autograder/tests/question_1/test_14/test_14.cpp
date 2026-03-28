//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_14() {
    LightDrone original(10.0, make_shared<FastRoute>());
    auto clone = original.clone();

    ostringstream original_before;
    ostringstream clone_before;
    original_before << original;
    clone_before << *clone;

    REQUIRE(typeid(*clone) == typeid(original));
    REQUIRE(original_before.str() == clone_before.str());

    clone->set_strategy(make_shared<SafeRoute>());

    ostringstream original_after;
    ostringstream clone_after;
    original_after << original;
    clone_after << *clone;

    REQUIRE(original_after.str() != clone_after.str());
}

TEST_CASE("Question #1.14") {
    execute_test("question_1_test_14.in", test_14);
}
