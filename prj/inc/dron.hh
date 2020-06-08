#ifndef DRON_HH
#define DRON_HH

#include <math.h>
#include "Obiekt3D.hh"
#include "InterfejsDrona.hh"
#include "Wektor3D.hh"
#include "Macierz.hh"
#include "MacierzOb.hh"
#include "prostopadloscian.hh"
#include "graniastoslup.hh"
#include "dno.hh"
#include "sruba.hh"
#include "powierzchnia.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "przeszkoda.hh"
using std::vector;
using std::shared_ptr;


class dron: public InterfejsDrona, public prostopadloscian, public przeszkoda
{
protected:
    sruba lewa;
    sruba prawa;
    double promien;
public:
dron(sruba L, sruba P, double X, double Y, double Z);

double Get_R();
Wektor3D Get_C();
void plyn(double odl, double kat);
void plyn_anim(double odl,double kat, vector<przeszkoda*> LPrzeszkod);
void obrot_anim(double kat);
void rysuj();
void Set_api(drawNS::Draw3DAPI *Api);
bool Czy_Kolizja(InterfejsDrona *InDr);
bool Czy_Kolizja(vector<przeszkoda*> LPrzeszkod);
};



#endif