//
// Created by rodri on 28/03/2026.
//

#include "VectorND.h"
#include <iostream>
#include <cmath>
VectorND::VectorND():n(3) {
    cords = new double[n];
    for (int i = 0;i<n;i++) cords[i] = 0.0;
}
VectorND::VectorND(int dimensiones, double *valores):n(dimensiones) {
    cords = new double[n];
    for (int i=0;i<n;i++) {
        cords[i] = valores[i];
    }
}
VectorND::~VectorND() {
    delete[] cords;
    std::cout << "VectorND destructor called." <<VectorND<<std::endl;
}
double VectorND::modulo() const {
    double suma = 0;
    for (int i= 0;i<n;i++) {
         suma += cords[i]*cords[i];
    }
    return sqrt(suma);
}
void print(const VectorND& v) {
    std::cout << "[ ";
    for(int i = 0; i < v.n; i++) {
        if (i == v.n) std::cout << v.cords[i];
        std::cout << v.cords[i] << " ";
    }
    std::cout << "]" << std::endl;
}