//
// Created by rodri on 28/03/2026.
//

#ifndef INC_1A_VECTORND_H
#define INC_1A_VECTORND_H
#include <vector>


class VectorND {
private:
    int n;
    double* cords;
public:
    VectorND();
    VectorND(int dimensiones, double* valores);
    ~VectorND();
    double modulo() const;
    friend void print(const VectorND& v);
};


#endif //INC_1A_VECTORND_H