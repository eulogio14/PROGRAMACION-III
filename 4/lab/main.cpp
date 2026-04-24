#include <iostream>
#include <string>
#include <vector>

// ==========================================
// 1. EL CATÁLOGO UNIVERSAL (Class Template)
// ==========================================
// Encapsula una misma estructura para varios tipos .
// La interfaz se mantiene; el tipo concreto se fija al instanciar[cite: 165].
template <typename T>
class Inventario {
private:
    std::vector<T> items;
    int cantidad_total = 0;
public:
    void agregar(const T& item, int cantidad) {
        items.push_back(item);
        cantidad_total += cantidad;
        std::cout << "[+] Registrado en sistema: " << cantidad << " unidades de alta rotación.\n";
    }

    void reportar() const {
        std::cout << "-> Stock actual: " << cantidad_total << " unidades.\n";
    }
};

// Estructuras de nuestros productos base
struct Zapatilla { std::string modelo; int talla; };
struct Mueble { std::string tipo; float alto; float ancho; float profundo; };

// ==========================================
// 2. LA MUTACIÓN (Especialización de Clase)
// ==========================================
// Redefinimos el caso particular cuando el comportamiento general ya no basta [cite: 188-189].
// A diferencia de unas zapatillas, el inventario de muebles necesita calcular
// el volumen en metros cúbicos para la logística de almacén y fletes.
template <>
class Inventario<Mueble> {
private:
    std::vector<Mueble> items;
    float volumen_ocupado_m3 = 0.0f;
    int cantidad_total = 0;
public:
    void agregar(const Mueble& item, int cantidad) {
        items.push_back(item);
        cantidad_total += cantidad;

        // Lógica de negocio específica para este rubro
        float volumen = item.alto * item.ancho * item.profundo;
        volumen_ocupado_m3 += (volumen * cantidad);

        std::cout << "[!] Carga pesada detectada: " << cantidad << " muebles ingresados.\n";
    }

    void reportar() const {
        std::cout << "-> Stock logístico: " << cantidad_total
                  << " muebles. Espacio ocupado en almacén: " << volumen_ocupado_m3 << " m^3.\n";
    }
};

// ==========================================
// 3. EL DISPARADOR MASIVO (Variadic Template)
// ==========================================
// Recibe un número variable de argumentos manteniendo chequeo de tipos [cite: 232-233].
template <typename... Inventarios>
void procesarIngresoMasivo(Inventarios&... almacenes) {
    std::cout << "\n=== INICIANDO SINCRONIZACIÓN OMNICANAL ===\n";

    // La fold expression reduce un paquete a una sola expresión[cite: 241].
    // Ejecutamos la función reportar() de TODOS los inventarios en una sola línea.
    (..., almacenes.reportar());

    std::cout << "=== SINCRONIZACIÓN COMPLETADA ===\n\n";
}

int main() {
    // Instanciación del template [cite: 167]
    Inventario<Zapatilla> almacenSneakers;
    Inventario<Mueble> almacenRoperos;

    std::cout << "--- INGRESO DE MERCADERÍA ---\n";
    almacenSneakers.agregar({"Zapatilla Urbana Blanca", 42}, 150);
    almacenRoperos.agregar({"Ropero Caoba 3 Puertas", 2.0, 1.5, 0.6}, 12);

    // Disparamos la sincronización masiva pasándole todos los almacenes a la vez
    procesarIngresoMasivo(almacenSneakers, almacenRoperos);

    return 0;
}