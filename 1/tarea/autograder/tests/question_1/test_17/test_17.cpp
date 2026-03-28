//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_17() {
    OperationsCenter center;
    auto original = make_unique<LightDrone>(10.0, make_shared<FastRoute>());
    ostringstream original_state;
    original_state << *original;
    auto clone = original->clone();

    clone->set_strategy(make_shared<SafeRoute>());
    ostringstream clone_state;
    clone_state << *clone;

    REQUIRE(original_state.str() != clone_state.str());

    center.add_drone(std::move(original));
    center.add_drone(std::move(clone));

    REQUIRE(center.drone_count() == 2);
    ScopedCoutCapture capture;
    REQUIRE_NOTHROW(center.show_drones());
    REQUIRE_FALSE(capture.str().empty());
}

TEST_CASE("Question #1.17") {
    execute_test("question_1_test_17.in", test_17);
}
