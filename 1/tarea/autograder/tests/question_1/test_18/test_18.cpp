//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_18() {
    CommonSetup setup;

    vector<unique_ptr<Drone>> drones;
    drones.push_back(make_unique<HeavyDrone>(25.0, setup.strategy2));
    drones.push_back(make_unique<LightDrone>(10.0, setup.strategy1));
    drones.push_back(make_unique<HeavyDrone>(40.0, setup.strategy2));

    sort(drones.begin(), drones.end(),
         [](const unique_ptr<Drone>& a, const unique_ptr<Drone>& b) {
             return *a < *b;
         });

    REQUIRE(drones[0]->calculate_range() <= drones[1]->calculate_range());
    REQUIRE(drones[1]->calculate_range() <= drones[2]->calculate_range());
    REQUIRE(drones.front()->calculate_range() <= drones.back()->calculate_range());
}

TEST_CASE("Question #1.18") {
    execute_test("question_1_test_18.in", test_18);
}
