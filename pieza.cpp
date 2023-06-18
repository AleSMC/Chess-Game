#include "pieza.hpp"

namespace Moyanos
{
    // Constructor de copia
    Pieza::Pieza(const Pieza &other) : color{other.color} {}

    // Constructor especifico
    Pieza::Pieza(unsigned c) : color{c} {}

    // Destructor
    Pieza::~Pieza() {}

    // Devuelve el color de la pieza
    unsigned Pieza::getColor() const { return color; }

    // Devuelvo una copia del objeto pieza
    Pieza *Pieza::clonar() const { return new Pieza(*this); }

}