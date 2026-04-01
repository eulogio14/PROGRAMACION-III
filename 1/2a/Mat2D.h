//
// Created by rodri on 01/04/2026.
//

#ifndef INC_2A_MAT2D_H
#define INC_2A_MAT2D_H


class Mat2D {
private:
    int filas;
    int columnas;
    int **mat;
public:

    Mat2D();
    Mat2D(int n);
    Mat2D(int f, int c);
    ~Mat2D();
    friend void print(const Mat2D& m);
};


#endif //INC_2A_MAT2D_H