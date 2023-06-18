#include "torre.hpp"

using namespace std;

namespace
{
    // Devuelve el numero de pasos por los que pasa
    int num_pasos(unsigned origen, unsigned destino)
    {
        return (destino - origen);
    }

    // Devuelve los las posiciones de los pasos
    std::vector<std::array<unsigned, 2>> pasos(bool left,
                                               const std::array<unsigned, 2> &origen,
                                               const std::array<unsigned, 2> &destino,
                                               unsigned num_pasos)
    {
        std::vector<std::array<unsigned, 2>> pasos;

        if (left)
        {
            unsigned i = origen[0] + 1;

            while (num_pasos > 0)
            {
                pasos.push_back({i, origen[1]});
                --num_pasos;
                ++i;
            }
        }
        else // right
        {
            unsigned i = origen[1] + 1;

            while (num_pasos > 0)
            {
                pasos.push_back({origen[0], i});
                --num_pasos;
                ++i;
            }
        }
        return pasos;
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
                      std::vector<std::array<unsigned, 2>> &paso,
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
            // Compruebo en que direccion se ha movido (De forma vertical u horizontal)
            if (left)
            { // Vertical

                // El ultimo paso lo quito ya que en caso de que hubiera pieza no importaria
                int num = num_pasos(origen[0], destino[0]) - 1;

                if (num > 0)
                {
                    // La pieza va hacia arriba
                    paso = pasos(left, origen, destino, num);
                }
                else if (num < 0)
                {
                    // La pieza va hacia abajo
                    paso = pasos(left, destino, origen, (num * -1));
                }
            }
            else // right = true , left = false
            {    // Horizontal

                // El ultimo paso lo quito ya que en caso de que hubiera pieza no importaria
                int num = num_pasos(origen[1], destino[1]) - 1;

                if (num > 0)
                {
                    // La pieza va hacia la derecha
                    paso = pasos(left, origen, destino, num);
                }
                else if (num < 0)
                {
                    // La pieza va hacia la izquierda
                    paso = pasos(left, destino, origen, (num * -1));
                }
            }

            ok = true;
        }
    }

    Torre *Torre::clonar() const { return new Torre(*this); } // Deuelve una copia del objeto actual
}