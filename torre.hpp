#ifndef __TORRE_HPP__
#define __TORRE_HPP__

#include "pieza.hpp"
#include <array>
#include <vector>

namespace Moyanos
{
    class Torre : public Pieza
    {
    protected:
        // Constructor de copia
        Torre(const Torre &other);

    public:
        // Constructor especifico
        Torre(unsigned c);

        // Destructor
        virtual ~Torre();

        // Comprueba si es posible el paso de la pieza del origen al destino
        // a traves del parametro ok, y en caso de serlo devuelve un vector
        // con las posisciones por las cuales pasaria
        //
        // Parametros de entrada:
        // origen --> posicion actual de la pieza. Ejemplo([0,0])
        // destino --> posicion final de la pieza. Ejemplo([4,0])
        //
        // Parametros de salida:
        // paso --> Lugares por los que pasa la pieza en el tablero.
        // ok --> Dictamina si es posible el movimiento en
        //        caso de no haber piezas por medio

        // Ejemplo :
        // torre.mover([0,0] , [4,0] , paso , ok)
        // paso = [1,0] , [2,0] , [3,0]
        // ok = True
        virtual void mover(const std::array<unsigned, 2> &origen,
                           const std::array<unsigned, 2> &destino,
                           std::vector<std::array<unsigned, 2>> &paso,
                           bool &ok);

        virtual Torre *clonar() const; // Deuelve una copia del objeto actual

        Torre &operator=(const Torre &) = delete; // Desactivado operator=
    };
}

#endif