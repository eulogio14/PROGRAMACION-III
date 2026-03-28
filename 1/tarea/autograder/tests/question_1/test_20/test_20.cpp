//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_20() {
    CommonSetup setup;

    auto source = make_unique<LightDrone>(10.0, setup.strategy1);
    unique_ptr<Drone> step1 = std::move(source);
    unique_ptr<Drone> step2 = std::move(step1);

    REQUIRE(source == nullptr);
    REQUIRE(step1 == nullptr);
    REQUIRE(step2 != nullptr);
    REQUIRE(step2->calculate_range() > 0.0);

    ostringstream out;
    out << *step2;
    REQUIRE_FALSE(out.str().empty());
}

TEST_CASE("Question #1.20") {
    execute_test("question_1_test_20.in", test_20);
}
