#include <iostream>
#include "VectorND.h"
int main() {
    double datos[] = {15.4,19,7};
    VectorND A(2,datos);
    print(A);
    return 0;
}