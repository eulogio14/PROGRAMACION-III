#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// RETO 2: Función Plantilla
// ==========================================
template <class T>
T ObtenerMayor(T a, T b) {
    if (a > b) {
        return a;
    } else { // Cambiado a 'else' simple para cubrir si b > a, o si son iguales
        return b;
    }
}

// ==========================================
// RETO 1: Clase Plantilla Genérica
// ==========================================
template<typename T>
class Bodega {
private:
    vector<T> arreglo;

public:
    void agregarCarga(T nuevoElemento) {
        arreglo.push_back(nuevoElemento);
    }

    void mostrarCarga() {
        // Bucle for estándar para cualquier tipo de dato
        for (int i = 0; i < arreglo.size(); i++) {
            cout << "- " << arreglo.at(i) << endl;
        }
    }
};

// ==========================================
// RETO 3: Especialización para strings
// ==========================================
// Le decimos al compilador que si la Bodega es de textos (string),
// debe usar esta versión de mostrarCarga() en lugar de la genérica.
template<>
void Bodega<string>::mostrarCarga() {
    cout << "[ALERTA DE SEGURIDAD] Cargamento confidencial." << endl;
    for (int i = 0; i < arreglo.size(); i++) {
        cout << "  > TOP SECRET: " << arreglo.at(i) << endl;
    }
}

// ==========================================
// EJECUCIÓN PRINCIPAL
// ==========================================
int main() {
    // 1. Probamos con Minerales (Decimales / float)
    Bodega<float> minerales;
    minerales.agregarCarga(15.5);
    minerales.agregarCarga(20.2);
    minerales.agregarCarga(8.9);

    cout << "--- BODEGA DE MINERALES (Toneladas) ---" << endl;
    minerales.mostrarCarga();

    // 2. Probamos con Droides (Enteros / int)
    Bodega<int> droides;
    droides.agregarCarga(10);
    droides.agregarCarga(42);

    cout << "\n--- BODEGA DE DROIDES (Unidades) ---" << endl;
    droides.mostrarCarga();

    // 3. Probamos la Especialización con Mensajes (Textos / string)
    Bodega<string> mensajes;
    mensajes.agregarCarga("Coordenadas de la base rebelde");
    mensajes.agregarCarga("Planos del hiperimpulsor");

    cout << "\n--- BODEGA DE MENSAJES DIPLOMATICOS ---" << endl;
    mensajes.mostrarCarga(); // Aquí se activará tu método especializado

    // 4. Probamos la función independiente
    cout << "\n---------------------------------------" << endl;
    cout << "El lote mayor de droides tiene: " << ObtenerMayor(10, 42) << " unidades." << endl;
    cout << "El cargamento mayor de minerales es de: " << ObtenerMayor(15.5, 8.9) << " toneladas." << endl;

    return 0;
}