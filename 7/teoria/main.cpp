#include <iostream>
#include <string>
#include <thread>

template<class T>
void foo(T a, T& b) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    b = b+a;
}


void pregunta1(bool puntero) {
    std::string e1, e2;
    std::string respuesta1 = "CPU";
    std::string respuesta2 = "GPU";
    std::cout<<"Poner las respuestas en mayusculas por favor"<<std::endl;
    std::cout<<"El computador tiene PRINCIPALMENTE un a y un b"<<std::endl;
    std::cout<<"a: ";
    std::cin >> e1;
    std::cout<<"b: ";
    std::cin>>e2;
    if (e1 == respuesta1 && e2 == respuesta2) {
        std::cout<<"Felicidades sacaste 20"<<std::endl;
        std::cout<<"Se cierra el programa"
        puntero = false;
    }else if (e1 == respuesta1 || e2 == respuesta2) {
        std::cout<<"Fallaste en una BRO"<<std::endl;
    }else {
        std::cout<<"Fallaste todas"<<std::endl;
    }
}
int main() {
    //Hoy aprendimos que la GPU ES PARA TAREAS DEBILES MIENTRAS QUE LA CPU SE USA PARA TAREAS FUERTES COMO JUEGOS

    bool estado = true;
    bool *ptr = &estado;
    float a= 1.1, b= 2.2;
    std::thread t(foo<float>, a, std::ref(b));
    std::cout<<"b = "<<b<<std::endl;
    t.join();
    std::cout<<"AHORA B ES LUEGO DE LANZAR LA FUNCION THREAD, EL NUEVO VALOR DE B ES: "<<b<<std::endl;
    do {
        pregunta1(*ptr);
    }while (estado == true);
    return 0;
}