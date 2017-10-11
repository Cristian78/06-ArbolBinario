#include <iostream>
#include "../ArbolBinario/ArbolBinario.h"

int main() {
    ArbolBinario<int> arbolito;

    arbolito.put(5);
    arbolito.put(3);
    arbolito.put(7);
    arbolito.put(1);
    arbolito.put(2);
    arbolito.put(4);
    arbolito.put(6);
    arbolito.put(8);
    arbolito.put(9);

    arbolito.print();

    std::cout << "Ejercicio 06/01\n" << std::endl;
    return 0;
}