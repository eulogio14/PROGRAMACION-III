//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_4() {
    CommonSetup setup;

    LightDrone drone(10.0, make_shared<FastRoute>());
    Route before = drone.plan_route(setup.light_delivery);

    drone.set_strategy(make_shared<SafeRoute>());
    Route after = drone.plan_route(setup.light_delivery);

    REQUIRE_FALSE(before.description.empty());
    REQUIRE_FALSE(after.description.empty());
    REQUIRE(before.estimated_distance > 0.0);
    REQUIRE(after.estimated_distance > 0.0);
    REQUIRE(
        (
            before.description != after.description ||
            before.estimated_distance != after.estimated_distance
        )
    );
    ScopedCoutCapture capture;
    REQUIRE_NOTHROW(drone.execute_delivery(setup.light_delivery));
    REQUIRE(capture.str().find("[OK]") != string::npos);
}

TEST_CASE("Question #1.4") {
    execute_test("question_1_test_4.in", test_4);
}
