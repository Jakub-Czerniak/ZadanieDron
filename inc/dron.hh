#ifndef DRON_HH
#define DRON_HH

#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzOb.hh"
#include "prostopadloscian.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
using Wektor3D=Wektor<double,3>;

class dron: public prostopadloscian
{
protected:
Wektor3D orientacja;

public:
dron(prostopadloscian prst, Wektor3D orient);
Wektor3D znajdzOrientacje();
void zmienOrientacje(Wektor3D Wek);
dron plyn(double odl, double kat);
};




#endif