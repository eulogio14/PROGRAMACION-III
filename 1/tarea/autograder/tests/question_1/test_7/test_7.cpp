//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_7() {
    CommonSetup setup;

    LightDrone original(10.0, setup.strategy1);
    const double previous_range = original.calculate_range();
    LightDrone moved = std::move(original);

    REQUIRE(moved.calculate_range() == previous_range);
    REQUIRE(moved.calculate_range() > 0.0);

    ostringstream out;
    out << moved;
    REQUIRE_FALSE(out.str().empty());
}

TEST_CASE("Question #1.7") {
    execute_test("question_1_test_7.in", test_7);
}
