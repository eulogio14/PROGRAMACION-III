//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_10() {
    CommonSetup setup;

    LightDrone active(10.0, setup.strategy1);
    LightDrone inactive(0.0, setup.strategy1);

    REQUIRE(static_cast<bool>(active));
    REQUIRE_FALSE(static_cast<bool>(inactive));
}

TEST_CASE("Question #1.10") {
    execute_test("question_1_test_10.in", test_10);
}
