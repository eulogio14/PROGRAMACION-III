//
// Created by rodri on 01/04/2026.
//

#ifndef INC_2A_VECTORND_H
#define INC_2A_VECTORND_H


class VectorND {
private:
    int n;
    double* lista;

public:
    VectorND();
    VectorND(int dimensiones,double *valores);
    ~VectorND();
    double modulo();
    friend void print(const VectorND& v);

};


#endif //INC_2A_VECTORND_H