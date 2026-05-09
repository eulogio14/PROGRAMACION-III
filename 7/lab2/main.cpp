#include <iostream>
#include <vector>
#include <functional>
#include <string>
struct Event {
    int document_id;
    std::string action;
    auto lmb_sumar[](int id,std::string sumar){};
};
class EventBus {
private:
    std::vector<Event>vectorDeFunciones;
public:
    // TODO: implementar subscribe
    // TODO: implementar publish
};
int main() {
    EventBus bus;
    bus.subscribe([](const Event& e) {
    std::cout << "[Audit] Documento "
    << e.document_id
    << " accion: "
    << e.action
    << '\n';
    });
    bus.subscribe([](const Event& e) {
    std::cout << "[Metrics] Evento registrado: "
    << e.action
    << '\n';
    });
    std::string username = "Ruben";
    bus.subscribe([username](const Event& e) {
    std::cout << "[User] "
    << username
    << " recibio evento sobre documento "
    << e.document_id
    << '\n';
    });
    bus.publish({42, "approved"});
    return 0;
}