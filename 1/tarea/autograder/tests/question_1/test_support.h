#ifndef PROG3_UNIT1_FUNDAMENTOS_V2026_01_TEST_SUPPORT_H
#define PROG3_UNIT1_FUNDAMENTOS_V2026_01_TEST_SUPPORT_H

#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>
#include <typeinfo>
#include <vector>

#include "catch.hpp"
#include "drone_system.h"

struct CommonSetup {
    std::shared_ptr<NavigationStrategy> strategy1 = std::make_shared<FastRoute>();
    std::shared_ptr<NavigationStrategy> strategy2 = std::make_shared<SafeRoute>();
    DeliveryRequest request1{
        "REQ-001",
        {0.0, 0.0, 10.0},
        {100.0, 50.0, 20.0},
        2.0
    };
    DeliveryRequest request2{
        "REQ-002",
        {10.0, 5.0, 12.0},
        {80.0, 20.0, 18.0},
        5.0
    };
    DeliveryRequest light_delivery{
        "REQ-LIGHT",
        {0.0, 0.0, 0.0},
        {3.0, 4.0, 0.0},
        2.0
    };
    DeliveryRequest heavy_delivery{
        "REQ-HEAVY",
        {0.0, 0.0, 0.0},
        {6.0, 8.0, 0.0},
        5.0
    };
    DeliveryRequest overweight_for_light{
        "REQ-OVER",
        {0.0, 0.0, 0.0},
        {1.0, 1.0, 0.0},
        5.0
    };
    DeliveryRequest invalid_payload{
        "REQ-INVALID",
        {0.0, 0.0, 0.0},
        {1.0, 0.0, 0.0},
        0.0
    };
};

class ScopedCoutCapture {
    std::ostringstream sink_;
    std::streambuf* previous_ = nullptr;
public:
    ScopedCoutCapture() : previous_(std::cout.rdbuf(sink_.rdbuf())) {}

    ScopedCoutCapture(const ScopedCoutCapture&) = delete;
    ScopedCoutCapture& operator=(const ScopedCoutCapture&) = delete;

    ~ScopedCoutCapture() {
        std::cout.rdbuf(previous_);
    }

    std::string str() const {
        return sink_.str();
    }
};

#endif
