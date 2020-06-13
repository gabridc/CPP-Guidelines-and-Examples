#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>
template <typename R, typename I>
class Complejo
{

public:
    I imaginaria;
    R real;

    Complejo(R _real = 0.0, I _imaginaria = 0.0) : real(_real), imaginaria(_imaginaria) {}
    template <typename T1>
    Complejo<R, I> &operator*(T1 operando1)
    {
        this->real = this->real * operando1;
        this->imaginaria = this->imaginaria * operando1;

        return *this;
    }
    Complejo<R, I> &operator*(double operando1);

    // Cuando el operador que queremos sobrecargar es un operador que al usarse
    // el objeto de la izquierda no es del tipo la clase en al que se quiere
    //sobrecargar hay que sobrecargarlo globalmente y usar la palabra friend
    //para que desde dentro de la función se puedan ver los atributos de la clase
    friend std::ostream &operator<<(std::ostream &o, const Complejo<R, I> &p)
    {
        o << "(" << p.real << ", " << p.imaginaria << ")";
        return o;
    }

    friend std::istream &operator>>(std::istream &is, Complejo<R, I> &p)
    {
        std::cout << "Real: ";
        is >> p.real;
        std::cout << "Imaginaria: ";
        is >> p.imaginaria;

        return is;
    }

private:
};

#endif