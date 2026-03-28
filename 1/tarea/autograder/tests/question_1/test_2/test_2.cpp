//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_2() {
    CommonSetup setup;

    vector<unique_ptr<Drone>> drones;
    drones.push_back(make_unique<LightDrone>(10.0, setup.strategy1));
    drones.push_back(make_unique<HeavyDrone>(25.0, setup.strategy2));

    REQUIRE(typeid(*drones[0]) == typeid(LightDrone));
    REQUIRE(typeid(*drones[1]) == typeid(HeavyDrone));

    for (const auto& drone : drones) {
        ScopedCoutCapture capture;
        REQUIRE_NOTHROW(drone->execute_delivery(setup.light_delivery));
        REQUIRE_FALSE(capture.str().empty());
        ostringstream out;
        out << *drone;
        REQUIRE_FALSE(out.str().empty());
    }
}

TEST_CASE("Question #1.2") {
    execute_test("question_1_test_2.in", test_2);
}
