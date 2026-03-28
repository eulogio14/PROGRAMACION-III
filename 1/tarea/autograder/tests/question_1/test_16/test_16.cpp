//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_16() {
    LightDrone light(15.0, make_shared<FastRoute>());
    HeavyDrone heavy(30.0, make_shared<SafeRoute>());

    const bool light_less = light < heavy;
    const bool heavy_less = heavy < light;

    REQUIRE(light_less);
    REQUIRE_FALSE(heavy_less);
    REQUIRE(light_less != heavy_less);
}

TEST_CASE("Question #1.16") {
    execute_test("question_1_test_16.in", test_16);
}
