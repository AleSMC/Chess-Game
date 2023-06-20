#ifndef __ALFIL_HPP__
#define __ALFIL_HPP__

#include "pieza.hpp"
#include <array>
#include <vector>

namespace Moyanos
{
    class Alfil : public Pieza
    {
    protected:
        // Constructor de copia
        Alfil(const Alfil &other);

    public:
        // Constructor especifico
        Alfil(unsigned c);

        // Destructor
        virtual ~Alfil();

        // Comprueba si es posible el paso de la pieza del origen al destino
        // a traves del parametro ok, y en caso de serlo devuelve un vector
        // con las posisciones por las cuales pasaria
        //
        // Parametros de entrada:
        // origen --> posicion actual de la pieza.
        // destino --> posicion final de la pieza.
        //
        // Parametros de salida:
        // paso --> Lugares por los que pasa la pieza en el tablero.
        // ok --> Dictamina si es posible el movimiento en
        //        caso de no haber piezas por medio

        // Ejemplo :
        // Alfil.mover([0,2] , [5,7] , paso , ok)
        // paso = [1,3] , [2,4] , [3,5] , [4,6]
        // ok = True
        virtual void mover(const std::array<unsigned, 2> &origen,
                           const std::array<unsigned, 2> &destino,
                           std::vector<std::array<unsigned, 2>> &paso,
                           bool &ok);

        virtual Alfil *clonar() const; // Deuelve una copia del objeto actual

        Alfil &operator=(const Alfil &) = delete; // Desactivado operator=
    };
}

#endif