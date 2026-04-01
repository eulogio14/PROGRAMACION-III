#include <iostream>
using namespace std;
ostream &operator<<(ostream &os, const Coordenada &item){
    os << "(" << item.x << ", ";
    os << item.y << ")";
    return os;
}

int main() {
    //sobrecarga de operadores
    return 0;
}
