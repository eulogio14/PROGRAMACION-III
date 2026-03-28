# Task #Task: Fundamentos de Programación - Gestor de Drones de Reparto Urbano
**course:** Programación III
**unit:** 1
**cmake project:** `prog3_unit1_fundamentos_v2026_01`

## Indicaciones Específicas
El tiempo límite para la evaluación es 1 semana.

Cada pregunta debe ser respondida en un archivo fuente y su cabecera correspondiente:

- `drone_system.h`
- `drone_system.cpp`

Puedes subir ambos archivos directamente a Gradescope o empaquetarlos en un `.zip`.

## Question #1 - Sistema integral de drones

Implementa un sistema en C++ para gestionar drones de reparto urbano usando:

- polimorfismo
- patrón Strategy
- patrón Prototype
- sobrecarga de operadores
- copy/move semantics
- una colección polimórfica administrada por `OperationsCenter`

### Archivos a completar

- [src/drone_system.h](/D:/Academic/UTEC/CS2013%20Prog3/Unit%201/prog3_unit1_fundamentos_v2026_01/src/drone_system.h)
- [src/drone_system.cpp](/D:/Academic/UTEC/CS2013%20Prog3/Unit%201/prog3_unit1_fundamentos_v2026_01/src/drone_system.cpp)

### Requerimientos mínimos

Debes definir al menos:

- `Location`, `Route`, `DeliveryRequest`
- `NavigationStrategy`, `FastRoute`, `SafeRoute`
- clase abstracta `Drone`
- clases concretas `LightDrone` y `HeavyDrone`
- `OperationsCenter`

La API esperada incluye como mínimo:

```cpp
class Drone {
public:
    virtual ~Drone() = default;
    virtual std::unique_ptr<Drone> clone() const = 0;
    virtual double calculate_range() const = 0;
    virtual void set_strategy(std::shared_ptr<NavigationStrategy> strategy) = 0;
    virtual Route plan_route(const DeliveryRequest& request) const = 0;
    virtual bool can_execute_delivery(const DeliveryRequest& request) const = 0;
    virtual void execute_delivery(const DeliveryRequest& request) = 0;
};
```

También debes implementar:

- `operator<` para comparar drones por autonomía
- `operator<<` para imprimir su estado
- `operator bool` para indicar si un drone está operativo
- constructor de copia y movimiento
- asignación por copia y movimiento

### Restricciones

- usar `std::unique_ptr` para drones
- usar `std::shared_ptr` para estrategias, o justificar otra decisión explícita
- no usar librerías externas
- separar `.h` y `.cpp`
- evitar memory leaks

### Cobertura del autograder

El autograder valida 20 casos basados en el enunciado:

- creación de drones
- polimorfismo
- estrategia inicial y cambio dinámico
- clonación
- copia, movimiento y asignación
- `operator<`, `operator<<` y `operator bool`
- registro y despacho en `OperationsCenter`
- centro vacío
- ordenamiento
- flujo completo
- movimientos múltiples

### Use Case

```cpp
#include "drone_system.h"
#include <iostream>
#include <memory>
#include <vector>

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

    if (*d1 < *d2) {
        std::cout << "d2 tiene mayor autonomia\n";
    }

    if (*d2) {
        std::cout << "d2 operativo\n";
    }

    OperationsCenter center;
    center.add_drone(std::move(d1));
    center.add_drone(std::move(d2));
    center.add_drone(std::move(d3));

    center.dispatch_deliveries({request1, request2});
}
```
