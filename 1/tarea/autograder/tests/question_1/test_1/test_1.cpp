//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_1() {
    CommonSetup setup;

    REQUIRE_NOTHROW(LightDrone(10.0, setup.strategy1));
    REQUIRE_NOTHROW(HeavyDrone(25.0, setup.strategy2));

    LightDrone d1(10.0, setup.strategy1);
    HeavyDrone d2(25.0, setup.strategy2);

    REQUIRE(d1.calculate_range() > 0.0);
    REQUIRE(d2.calculate_range() > 0.0);
    REQUIRE(d1.can_execute_delivery(setup.light_delivery));
    REQUIRE_FALSE(d1.can_execute_delivery(setup.overweight_for_light));
    REQUIRE_FALSE(d1.can_execute_delivery(setup.invalid_payload));
    REQUIRE(d2.can_execute_delivery(setup.light_delivery));
    REQUIRE(d2.can_execute_delivery(setup.heavy_delivery));
}

TEST_CASE("Question #1.1") {
    execute_test("question_1_test_1.in", test_1);
}
