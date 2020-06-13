#include "Template.hpp"

// Definir los tipos para el template no tiene sentido porque para
//hacer esto sobrecargo el metodo y lo defino para cada tipo que quiera
//usar.

//Sólo puede tener sentido si para algún tipo concreto quiero
//hacer algo en especial, pero lo útil de las plantillas es definirlo
//e implementarlo en los fichero .hpp ya que las plantillas requieren
//ser compiladas siempre para inferir los tipos.
template <>
Complejo<double, double> &Complejo<double, double>::operator*(double operando1)
{
    this->real = (this->real * operando1) + 1.0;
    this->imaginaria = this->imaginaria * operando1;

    return *this;
}
