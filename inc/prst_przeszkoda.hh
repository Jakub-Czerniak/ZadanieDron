#ifndef PRST_PRZESZKODA_HH
#define PRST_PRZESZKODA_HH

#include "prostopadloscian.hh"
#include "przeszkoda.hh"
#include "InterfejsDrona.hh"
#include "Wektor.hh"
using Wektor3D=Wektor<double,3>;


class PrstPrzeszkoda: public prostopadloscian, public przeszkoda
{
public:
PrstPrzeszkoda(double X, double Y, double Z, Wektor3D Przesuniecie);
bool Czy_Kolizja(InterfejsDrona *InDr);
};

#endif