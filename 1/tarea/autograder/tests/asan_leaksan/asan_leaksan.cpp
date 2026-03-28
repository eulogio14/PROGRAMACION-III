#include <memory>
#include <sstream>
#include <utility>
#include <vector>

#include "drone_system.h"

int main() {
    auto strategy1 = std::make_shared<FastRoute>();
    auto strategy2 = std::make_shared<SafeRoute>();

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

    auto d1 = std::make_unique<LightDrone>(10.0, strategy1);
    auto d2 = std::make_unique<HeavyDrone>(25.0, strategy2);
    auto d3 = d1->clone();

    d3->set_strategy(std::make_shared<SafeRoute>());

    std::ostringstream out;
    out << *d1;
    out << *d2;
    out << *d3;

    LightDrone copied(10.0, strategy1);
    LightDrone assigned(1.0, strategy2);
    assigned = copied;
    LightDrone moved = std::move(copied);

    if (static_cast<bool>(*d1) && (*d1 < *d2)) {
        out << "ordered";
    }
    out << assigned;
    out << moved;

    OperationsCenter center;
    center.add_drone(std::move(d1));
    center.add_drone(std::move(d2));
    center.add_drone(std::move(d3));

    center.show_drones();
    center.dispatch_delivery(request1);
    center.dispatch_deliveries(std::vector<DeliveryRequest>{request1, request2});

    return 0;
}
