#ifndef MACIERZOB_HH
#define MACIERZOB_HH

#include <math.h>
#include <iostream>
#include "Macierz.hh"

class MacierzOb: public Macierz<double, 3>
{
public:
MacierzOb(double kat, char Os);

};

#endif