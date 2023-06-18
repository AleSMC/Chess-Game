#include "torre.hpp"
#include <iostream>
#include <cassert>

using namespace std;
using namespace Moyanos;

void color(Torre &torre)
{
    assert(torre.getColor() == 1);
}

void movimientos_correctos(Torre &torre)
{
    std::vector<std::array<unsigned, 2>> pasos,
        objetivo = {{1, 0}, {2, 0}, {3, 0}};

    bool movimiento_correcto;

    torre.mover({0, 0}, {4, 0}, pasos, movimiento_correcto);

    assert(movimiento_correcto == true);
    assert(pasos == objetivo);
}

int main()
{
    Torre torre{1}; // Torre negra

    cout << "Consultando color..." << endl;
    color(torre);
    cout << "--OK" << endl;

    cout << "Consultando movimientos..." << endl;
    movimientos_correctos(torre);
    cout << "--OK" << endl;
    return 0;
}