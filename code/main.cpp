#include <iostream>
#include "cenario_1.h"
#include "cenario_2.h"
#include "cenario_3.h"

int main() {

    cenario_1 x;
    cenario_2 y;
    cenario_3 z;

    int q = x.place();
    int w = y.place();
    int e = z.place();

    //std::cout << "cenario 1: "<< q << "\n";
    //std::cout << "cenario 2: "<< w << "\n";
    //std::cout << "cenario 3: "<< e << "\n";
    return 0;
}