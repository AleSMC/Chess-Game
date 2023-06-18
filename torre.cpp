#include "torre.hpp"

using namespace std;

namespace
{
    // Devuelve el numero de pasos por los que pasa
    int num_pasos(unsigned origen, unsigned destino)
    {
        return (destino - origen);
    }
}

namespace Moyanos
{
    // Constructor de copia
    Torre::Torre(const Torre &other) : Pieza{other} {}

    // Constructor especifico
    Torre::Torre(unsigned c) : Pieza{c} {}

    // Destructor
    Torre::~Torre() {}

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
    void Torre::mover(const std::array<unsigned, 2> &origen,
                      const std::array<unsigned, 2> &destino,
                      const std::vector<std::array<unsigned, 2>> &paso,
                      bool &ok)
    {
        // Las torres solo se pueden mover de forma recta en diagonal u horizontal
        // por lo que la posicion 0 (izquierda) o 1 (derecha) del origen tiene que
        // ser igual a la del detino.
        // En caso de ser los dos iguales no seria un movimiento valido ya que
        // significa que la pieza no se a movido.

        bool left = origen[0] == destino[0],
             right = origen[1] == destino[1];

        if (left == right || left == false || right == false)
        {
            ok = false;
        }
        else // La pieza se puede mover del origen al destino
        {
            // Compruebo en que direccion se ha movido (De forma diagonal u horizontal)
            if (left)
            {
                int num = num_pasos(origen[0], destino[0]);
            }
            else // right = true
            {
                int num = num_pasos(origen[1], destino[1]);
            }
        }
    }

    Torre *Torre::clonar() const { return new Torre(*this); } // Deuelve una copia del objeto actual
}