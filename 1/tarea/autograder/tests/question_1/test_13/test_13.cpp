//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_13() {
    CommonSetup setup;

    OperationsCenter center;
    vector<DeliveryRequest> requests{setup.request1, setup.request2};
    REQUIRE(center.drone_count() == 0);
    ScopedCoutCapture capture;
    REQUIRE_NOTHROW(center.dispatch_deliveries(requests));
}

TEST_CASE("Question #1.13") {
    execute_test("question_1_test_13.in", test_13);
}
