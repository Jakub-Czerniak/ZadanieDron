#ifndef DRON_HH
#define DRON_HH

#include <math.h>
#include "Obiekt3D.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzOb.hh"
#include "prostopadloscian.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
using Wektor3D=Wektor<double,3>;

class dron: public prostopadloscian
{
public:
dron(prostopadloscian prst);

dron plyn(double odl, double kat);
};



#endif