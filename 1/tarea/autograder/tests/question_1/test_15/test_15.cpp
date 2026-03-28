//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_15() {
    LightDrone source(10.0, make_shared<FastRoute>());
    LightDrone copy_target(5.0, make_shared<SafeRoute>());
    copy_target = source;

    ostringstream source_state;
    ostringstream copy_state;
    source_state << source;
    copy_state << copy_target;

    REQUIRE(copy_target.calculate_range() == source.calculate_range());
    REQUIRE(source_state.str() == copy_state.str());

    LightDrone move_source(20.0, make_shared<SafeRoute>());
    const double move_range = move_source.calculate_range();
    LightDrone move_target(1.0, make_shared<FastRoute>());
    move_target = std::move(move_source);

    REQUIRE(move_target.calculate_range() == move_range);
    REQUIRE(move_target.calculate_range() > 0.0);
    ostringstream copy_target_state;
    ostringstream move_target_state;
    copy_target_state << copy_target;
    move_target_state << move_target;
    REQUIRE_FALSE(copy_target_state.str().empty());
    REQUIRE_FALSE(move_target_state.str().empty());
}

TEST_CASE("Question #1.15") {
    execute_test("question_1_test_15.in", test_15);
}
