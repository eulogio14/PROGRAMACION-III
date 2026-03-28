//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_11() {
    CommonSetup setup;

    OperationsCenter center;
    auto d1 = make_unique<LightDrone>(10.0, setup.strategy1);
    center.add_drone(std::move(d1));

    REQUIRE(d1 == nullptr);
    REQUIRE(center.drone_count() == 1);
}

TEST_CASE("Question #1.11") {
    execute_test("question_1_test_11.in", test_11);
}
