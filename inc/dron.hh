#ifndef DRON_HH
#define DRON_HH

#include <math.h>
#include "Obiekt3D.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzOb.hh"
#include "prostopadloscian.hh"
#include "graniastoslup.hh"
#include "sruba.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
using Wektor3D=Wektor<double,3>;

class dron: public prostopadloscian
{
    sruba lewa;
    sruba prawa;
public:
dron(sruba L, sruba P, Wektor3D A, Wektor3D B, Wektor3D C, Wektor3D D, Wektor3D E, Wektor3D F, Wektor3D G, Wektor3D H);

dron plyn(double odl, double kat);
dron plyn_anim(double odl,double kat, drawNS::Draw3DAPI & api);
void obrot_anim(double kat, drawNS::Draw3DAPI &api);
void rysujD(drawNS::Draw3DAPI &api);
};



#endif