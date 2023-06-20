#include "alfil.hpp"
#include <iostream>
#include <cassert>

using namespace std;
using namespace Moyanos;

void color()
{
    Alfil alfil1{1}, // alfil negra
        alfil2{0};   // alfil blanca

    assert(alfil1.getColor() == 1);
    assert(alfil2.getColor() == 0);
}

void movimientos_correctos()
{
    Alfil alfil{1}; // alfil negra

    std::vector<std::array<unsigned, 2>> pasos,
        objetivo = {{1, 3}, {2, 4}, {3, 5}, {4, 6}};

    bool movimiento_correcto;

    alfil.mover({0, 2}, {5, 7}, pasos, movimiento_correcto);

    assert(movimiento_correcto == true);
    assert(pasos == objetivo);

    objetivo = {{3, 4}, {2, 5}, {1, 6}};
    alfil.mover({4, 3}, {0, 7}, pasos, movimiento_correcto);
    assert(movimiento_correcto == true);
    assert(pasos == objetivo);

    alfil.mover({7, 0}, {7, 0}, pasos, movimiento_correcto);
    assert(movimiento_correcto == false);
}

void clonar()
{
    Alfil alfil{1};  // alfil negra
    Alfil *Ptralfil; // Puntero de alfil

    Ptralfil = alfil.clonar();
    assert(Ptralfil->getColor() == alfil.getColor());
}

int main()
{
    cout << "Consultando color..." << endl;
    color();
    cout << "--OK" << endl;

    cout << "Consultando movimientos..." << endl;
    movimientos_correctos();
    cout << "--OK" << endl;

    cout << "Cunsultando clonar..." << endl;
    clonar();
    cout << "--OK" << endl;

    return 0;
}