#ifndef __PIEZA_HPP__
#define __PIEZA_HPP__

namespace Moyanos
{
    class Pieza
    {
    private:
        // La variable hace referencia al color de la pieza
        // Negro = 1
        // Blanco = 0
        unsigned color;

    protected:
        Pieza(const Pieza &other);

    public:
        // Constructor especifico
        Pieza(unsigned c);

        // Destructor
        virtual ~Pieza();

        // Devuelve el color de la pieza
        virtual unsigned getColor() const;

        // Devuelvo una copia del objeto pieza
        virtual Pieza *clonar() const;

        // Desactivado operator =
        Pieza &operator=(const Pieza &) = delete;
    };
}

#endif