#ifndef MACIERZOB_HH
#define MACIERZOB_HH

#include <math.h>
#include <iostream>
#include "Macierz.hh"
#include "Wektor3D.hh"

using Macierz3D=Macierz<double,3>;

class MacierzOb: public Macierz<double, 3>
{
public:
MacierzOb();
MacierzOb(Macierz3D &Mac);
MacierzOb(double kat, char Os);
};

#endif