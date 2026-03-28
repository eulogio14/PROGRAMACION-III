//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_12() {
    CommonSetup setup;

    OperationsCenter center;
    center.add_drone(make_unique<LightDrone>(10.0, setup.strategy1));
    center.add_drone(make_unique<HeavyDrone>(25.0, setup.strategy2));

    vector<DeliveryRequest> requests{setup.light_delivery, setup.heavy_delivery};
    REQUIRE(center.drone_count() == 2);
    ScopedCoutCapture capture;
    REQUIRE_NOTHROW(center.dispatch_deliveries(requests));
    REQUIRE(capture.str().find("REQ-LIGHT") != string::npos);
    REQUIRE(capture.str().find("REQ-HEAVY") != string::npos);
    REQUIRE(capture.str().find("No available drone") == string::npos);
}

TEST_CASE("Question #1.12") {
    execute_test("question_1_test_12.in", test_12);
}
