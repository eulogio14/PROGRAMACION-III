#include <iostream>
#include <vector>
#include <algorithm>

struct Impresor {
    void operator()(const std::vector<int>& v) {
        std::cout <<"[";
        for (int i:v) {
            std::cout << i<<" ";
        }
        std::cout << "]"<<std::endl;
    }
};
template <typename... Operaciones>
void ejecutar_pipeline(std::vector<int>& datos, Operaciones... ops) {
    (ops(datos),...);
}
int main() {
    std::vector<int> numeros = {15,2,8,1,9,10};

    auto ordenador =[](std::vector<int>& v) {
        std::sort(v.begin(), v.end());
    };
    auto duplicador =[](std::vector<int>& v) {
        std::for_each(v.begin(), v.end(),[](int &x){x *= 2;});
    };
    auto contador = [](const std::vector<int>& v) {
        int pares = std::count_if(v.begin(), v.end(),[](int x){return x%2 == 0;});
        std::cout<<"Total numero de pares: "<<pares<<std::endl;
    };
    Impresor mi_impresor;
    std::cout<<"Iniaciando pipeline..."<<std::endl;
    // 4. EJECUCIÓN (El pipeline respetará el orden exacto en el que pases los parámetros)
    ejecutar_pipeline(
        numeros,       // Los datos
        mi_impresor,   // Imprime original: [ 15 2 8 1 9 10 ]
        ordenador,     // Lo ordena silenciosamente
        mi_impresor,   // Imprime ordenado: [ 1 2 8 9 10 15 ]
        duplicador,    // Lo multiplica silenciosamente
        mi_impresor,   // Imprime duplicado:[ 2 4 16 18 20 30 ]
        contador       // Imprime texto: Total de numeros pares: 6
    );

    return 0;

}