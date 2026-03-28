//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "question_1/test_support.h"
#include "drone_system.h"
using namespace std;

static void test_19() {
    CommonSetup setup;

    auto d1 = make_unique<LightDrone>(10.0, setup.strategy1);
    auto d2 = make_unique<HeavyDrone>(25.0, setup.strategy2);
    auto d3 = d1->clone();

    d3->set_strategy(make_shared<SafeRoute>());

    ostringstream original_state;
    ostringstream clone_state;
    original_state << *d1;
    clone_state << *d3;

    REQUIRE(original_state.str() != clone_state.str());
    REQUIRE(static_cast<bool>(*d1));
    REQUIRE(static_cast<bool>(*d2));

    OperationsCenter center;
    center.add_drone(std::move(d1));
    center.add_drone(std::move(d2));
    center.add_drone(std::move(d3));

    REQUIRE(center.drone_count() == 3);
    {
        ScopedCoutCapture capture;
        REQUIRE_NOTHROW(center.show_drones());
        REQUIRE_FALSE(capture.str().empty());
    }

    vector<DeliveryRequest> requests{setup.light_delivery, setup.heavy_delivery};
    {
        ScopedCoutCapture capture;
        REQUIRE_NOTHROW(center.dispatch_deliveries(requests));
        REQUIRE(capture.str().find("REQ-LIGHT") != string::npos);
        REQUIRE(capture.str().find("REQ-HEAVY") != string::npos);
    }
}

TEST_CASE("Question #1.19") {
    execute_test("question_1_test_19.in", test_19);
}
