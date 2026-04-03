//
// Created by rodri on 01/04/2026.
//


#include "VectorND.h"
#include <iostream>
#include <cmath>
VectorND::VectorND():n(3) {
    lista = new double[n];
    for (int i = 0;i<n;i++) lista[i] = 0.0;
}
VectorND::VectorND(int dimensiones, double *valores):n(dimensiones) {
    lista = new double [n];
    for (int i=0;i<n;i++) {
        lista[i] = valores[i];
    }
}
VectorND::~VectorND() {
    delete[] lista;
    std::cout << "VectorND destructor called."<<std::endl;
}

double VectorND::modulo() {
    double suma = 0;
    for (int i=0;i<n;i++) {
        suma += lista[i]*lista[i];
    }
    return sqrt(suma);
}
void print(const VectorND& v) {
    std::cout << "[";
    for (int i=0;i<v.n;i++) {
        if (v.n == 0) std::cout<<v.lista[i];
        std::cout<<v.lista[i]<<" ";
    }
    std::cout << "]" << std::endl;
}