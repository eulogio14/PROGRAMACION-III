//
// Created by rodri on 01/04/2026.
//

#include "Mat2D.h"
#include <cstdlib>
#include <iostream>
#include <ostream>
Mat2D::Mat2D():Mat2D(3,3) {}

Mat2D::Mat2D(int n):Mat2D(n,n) {}
Mat2D::Mat2D(int f, int c):filas(f),columnas(c) {
    mat = new int*[filas];
    for (int i = 0; i < filas; i++) {
        mat[i] = new int[columnas];
        for (int j = 0; j < columnas; j++) {
            mat[i][j] = rand() % 1000;
        }
    }
}
Mat2D::~Mat2D() {
    for (int i = 0; i < filas; i++) {
        delete[] mat[i];
    }
    delete[] mat;
    std::cout<<"matriz de "<<filas<<" x " <<columnas<<" elimninado."<<std::endl;
}
void print(const Mat2D& m){
    for (int i=0;i<m.filas;i++) {
        for (int j=0;j<m.columnas;j++) {
            std::cout<<m.mat[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}





