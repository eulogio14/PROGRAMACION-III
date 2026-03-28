//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_8() {
    CommonSetup setup;

    LightDrone d1(10.0, setup.strategy1);
    HeavyDrone d2(25.0, setup.strategy2);
    const bool result = d1 < d2;

    REQUIRE(result);
    REQUIRE((d1 < d2) == result);
}

TEST_CASE("Question #1.8") {
    execute_test("question_1_test_8.in", test_8);
}
