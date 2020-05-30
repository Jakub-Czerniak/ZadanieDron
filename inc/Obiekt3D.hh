#ifndef OBIEKT3D_HH
#define OBIEKT3D_HH

#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzOb.hh"
#include "Draw3D_api_interface.hh"
#include "Dr3D_gnuplot_api.hh"


using Wektor3D=Wektor<double,3>;

class Obiekt3D
{
protected:
int ID=-1;
drawNS::Draw3DAPI *api;
Wektor3D Srodek;
MacierzOb Orientacja;
public:
Obiekt3D();
void Set_api(drawNS::Draw3DAPI *Api);
};

#endif