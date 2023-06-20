#include "alfil.hpp"

using namespace std;

namespace
{
    // Devuelve el numero de casillas por los que pasa la pieza
    int num_pasos(unsigned origen, unsigned destino)
    {
        return destino - origen;
    }

    // Devuelve los las posiciones de los pasos si van en esta direccion "\"
    std::vector<std::array<unsigned, 2>> pasos_abajo(unsigned left,
                                                     const std::array<unsigned, 2> &origen)
    {
        std::vector<std::array<unsigned, 2>> pasos;
        for (unsigned i = 1; i < left; ++i)
        {
            pasos.push_back({origen[0] + i, origen[1] + i});
        }
    }

    // Devuelve los las posiciones de los pasos si van en esta direccion "/"
    std::vector<std::array<unsigned, 2>> pasos_arriba(unsigned left,
                                                      const std::array<unsigned, 2> &origen)
    {
        std::vector<std::array<unsigned, 2>> pasos;
        for (unsigned i = 1; i < left; ++i)
        {
            pasos.push_back({origen[0] + i, origen[1] + i});
        }
    }
}

namespace Moyanos
{
    // Constructor de copia
    Alfil::Alfil(const Alfil &other) : Pieza{other} {}

    // Constructor especifico
    Alfil::Alfil(unsigned c) : Pieza{c} {}

    // Destructor
    Alfil::~Alfil() {}

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
    void Alfil::mover(const std::array<unsigned, 2> &origen,
                      const std::array<unsigned, 2> &destino,
                      std::vector<std::array<unsigned, 2>> &paso,
                      bool &ok)
    {
        unsigned left = num_pasos(origen[0], destino[0]),
                 right = num_pasos(origen[1], destino[1]);

        if (left != 0) // Se mueve
        {
            if (left == right) //  -- o ++
            {
                if (left > 0) // ++
                {
                    paso = pasos_abajo(left, origen);
                }
                else // --
                {
                    paso = pasos_abajo((left * -1), destino);
                }
            }
            else if (left == (right * -1)) // -+ o +-
            {
                if (left > 0) // +-
                {
                    paso = pasos_arriba(left, destino);
                }
                else // -+
                {
                    paso = pasos_arriba((left * -1), origen);
                }
            }
            ok = true;
        }
        else // No se mueve o se mueve en una direccion distinta a un alfil
        {
            ok = false;
        }
    }

    Alfil *Alfil::clonar() const { return new Alfil(*this); } // Deuelve una copia del objeto actual
}