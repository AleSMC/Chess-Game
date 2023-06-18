#ifndef __TORRE_HPP__
#define __TORRE_HPP__

#include "pieza.hpp"
#include <array>

namespace Moyanos
{
    class Torre : public Pieza
    {
    protected:
        // Constructor de copia
        Torre(const Torre &other);

    public:
        // Coonstructor especifico
        Torre(unsigned c);

        // Destructor
        virtual ~Torre();

        // Comprueba si es posible el paso de la pieza del origen al destino
        // a traves del parametro ok, y en caso de serlo devuelve un vector
        // con las posisciones por las cuales pasaria
        virtual void mover(const std::array<unsigned, 2> &origen,
                           const std::array<unsigned, 2> &destino,
                           const std::vector<std::array<unsigned, 2>> &paso,
                           bool &ok);

        virtual Torre *clonar() const; // Deuelve una copia del objeto actual

        Torre &operator=(const Torre &) = delete; // Desactivado operator=
    };
}

#endif