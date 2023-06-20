#include "torre.hpp"
#include <iostream>
#include <cassert>

using namespace std;
using namespace Moyanos;

void color()
{
    Torre torre1{1}, // Torre negra
        torre2{0};   // Torre blanca

    assert(torre1.getColor() == 1);
    assert(torre2.getColor() == 0);
}

void movimientos_correctos()
{
    Torre torre{1}; // Torre negra

    std::vector<std::array<unsigned, 2>> pasos,
        objetivo = {{1, 0}, {2, 0}, {3, 0}};

    bool movimiento_correcto;

    torre.mover({0, 0}, {4, 0}, pasos, movimiento_correcto);

    assert(movimiento_correcto == true);
    assert(pasos == objetivo);

    objetivo = {{3, 3}, {3, 4}, {3, 5}, {3, 6}};
    torre.mover({3, 7}, {3, 2}, pasos, movimiento_correcto);
    assert(movimiento_correcto == true);
    assert(pasos == objetivo);

    torre.mover({3, 4}, {4, 5}, pasos, movimiento_correcto);
    assert(movimiento_correcto == false);
}

int main()
{
    cout << "Consultando color..." << endl;
    color();
    cout << "--OK" << endl;

    cout << "Consultando movimientos..." << endl;
    movimientos_correctos();
    cout << "--OK" << endl;
    return 0;
}