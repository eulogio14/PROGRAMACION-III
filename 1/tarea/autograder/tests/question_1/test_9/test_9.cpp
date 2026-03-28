//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_9() {
    CommonSetup setup;
    LightDrone d1(10.0, setup.strategy1);

    ostringstream out;
    out << d1;
    REQUIRE_FALSE(out.str().empty());
    REQUIRE(out.str().find("LightDrone") != string::npos);
    REQUIRE(out.str().find("strategy=") != string::npos);
}

TEST_CASE("Question #1.9") {
    execute_test("question_1_test_9.in", test_9);
}
