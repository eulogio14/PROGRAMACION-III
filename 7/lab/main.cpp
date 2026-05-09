#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include <array>
#include <limits>
#include <fstream>
// semana 7 laboratorio TEMA: ITERADORES Y RANGES
class SumarE {
    int& x;
public:
    SumarE(int &x):x{x} {} //NOLINT
    int operator()(int a, int b)const{ return a+b+x; }
};
int sumar(int a,int b) {return a+b;}
int restar(int a, int b){return a-b;}
int multiplicar(int a,int b){return a*b;}


void ejemplo2() {
    std::vector<int(*)(int,int)> vFunciones{sumar,restar,multiplicar};
    int x=100;
    int y=20;
    for (const auto& fun : vFunciones) {
        std::cout <<fun(x,y)<<std::endl;
    }
    vFunciones.push_back([](int a, int b){return a +b;});
    vFunciones.push_back([](int a, int b){return a-b;});
    vFunciones.push_back([](int a, int b){return a*b;});
}
void ejemplo3() {
    std::vector<int(*)(int,int)> vFunciones{sumar,restar,multiplicar};

    vFunciones.push_back([](int a, int b){return a +b;});
    vFunciones.push_back([](int a, int b){return a-b;});
    vFunciones.push_back([](int a, int b){return a*b;});
    int x = 100;
    int y = 1201;
    for (const auto& fun:vFunciones) {
        std::cout<<fun(x,y)<<std::endl;
    }
}
void ejemplo4() {
    std::vector<SumarE> vfuns;
    vfuns.emplace_back(10);
    vfuns.emplace_back(20);
    vfuns.emplace_back(30);
    int x=100;
    int y =20;
    for (const auto&fun: vfuns) {
        std::cout<<fun(x,y)<<std::endl;
    }
}

void ejemplo5() {
    auto lmb_sumar = [](int a, int b){return a +b;};
    auto lmb_restar = [](int a, int b){return a-b;};
    auto lmb_multiplicar = [](int a, int b){return a*b;};
    std::vector<decltype(lmb_sumar)> vfuns;
    vfuns.emplace_back(lmb_sumar);
    vfuns.emplace_back(lmb_restar);
}
typedef int(*ptrSumar)(int,int);



int main() {
    return 0;
}
/*
void recorrerArrayPorLiberiaEstandar(const std::array<int,3>& arr ) {
    for (auto i=0; i<std::size(arr); ++i) std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}

void recorrerArrayPorLibreriaEstandar(std::array <int,3>& arr) {
    int *ptr = arr.data();

    while (ptr != arr.data() + std::size(arr)) {
        std::cout<<*ptr<<" ";
        ++ptr;
    }
}

void recorrerVectoresConIteradores(const std::vector<int>& vec) {
    for (auto it = vec.begin(); it!= vec.end(); it++) {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
}

void recorrerConRange(const std::vector<int>& vec) {
    auto pares =vec | std::views::filter([](int n){return n/2 == 0;});
}
bool crearVector(std::vector<int>& vec) {
    int n;
    while (true) {
        std::cout << "Ingrese un numero (o una letra para terminar): ";

        if (!(std::cin >> n)) {
            // El usuario metió texto
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "String detectado. Terminando ingreso de datos...\n";
            break; // AQUI SALIMOS DEL BUCLE para que no haga el push_back
        }

        // Solo llega aquí si ingresó un número válido
        vec.push_back(n);
    }
    return true;
}
template <typename T>
void imprimirVector(const std::vector<T>& v ) {
    for (auto i : v) {
        std::cout<<i<<" "<<std::endl;
    }
}
int main() {
    std::vector<int> vec;
    std::vector<int> copia;
    crearVector(vec);
    std::copy(vec.begin(), vec.end(), std::back_inserter(copia));

    std::cout<<"Vector 1: "<<std::endl;
    imprimirVector(vec);


    std::cout<<"Vector 1 ordenado:"<<std::endl;
    std::ranges::sort(vec);
    imprimirVector(vec);

    std::cout<<"Vector 2 luego de copiar al anterior vector:"<<std::endl;
    imprimirVector(vec);



    //clase del profe
    for (const auto& i:std::ranges::views::iota(2,1000)) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    std::vector v= {1,2,3};
    auto r = v |std::ranges::views::transform([](auto i){return i*i;});

    for (const auto& i:r) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    auto r2 = std::ranges::views::iota(1) |
        std::ranges::views::take(200)
    |std::ranges::views::filter([](auto i){return i<100 && i% 7 == 0;})
    |std::ranges::views::transform([](auto i){return i +1;})
        | std::ranges::views::filter([](auto i) {return i<100 && i % 7 == 0;});

    std::ranges::copy(r2,std::ostream_iterator<int>(std::cout," "));
    for (const auto& i:r2) {
        std::cout<<i<<" ";
    }

    std::cout<<std::endl<<"Ingrese valores enteros: "<<std::endl;
    std::ifstream file("datos.txt");
    std::istream_iterator<int> first(file);
    std::istream_iterator<int> last;
    std::vector<int> va;
    return 0;
}
*/