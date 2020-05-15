#ifndef OBIEKT3D_HH
#define OBIEKT3D_HH

#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzOb.hh"

using Wektor3D=Wektor<double,3>;

class Obiekt3D
{
protected:
int ID;
Wektor3D Srodek;
MacierzOb Orientacja;
public:
Obiekt3D();
};

#endif