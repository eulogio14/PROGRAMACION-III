#include <iostream>
#include "Mat2D.h"
#include "VectorND.h"
int main() {
    srand(time(NULL));
    Mat2D matriz(7,7);
    print(matriz);
    double datos[] = {2.32,4.6,7.7};
    VectorND v(3,datos);
    print(v);
    std::cout<<"EL MODULO ES : "<<v.modulo()<<std::endl;
    return 0;
}