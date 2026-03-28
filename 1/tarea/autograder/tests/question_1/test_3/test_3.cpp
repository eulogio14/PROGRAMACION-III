//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_3() {
    CommonSetup setup;

    FastRoute fast;
    SafeRoute safe;

    Route fast_route = fast.calculate_route(setup.request1);
    Route safe_route = safe.calculate_route(setup.request1);

    REQUIRE_FALSE(fast_route.description.empty());
    REQUIRE_FALSE(safe_route.description.empty());
    REQUIRE(fast_route.estimated_distance > 0.0);
    REQUIRE(safe_route.estimated_distance > 0.0);
    REQUIRE(safe_route.estimated_distance > fast_route.estimated_distance);
}

TEST_CASE("Question #1.3") {
    execute_test("question_1_test_3.in", test_3);
}
