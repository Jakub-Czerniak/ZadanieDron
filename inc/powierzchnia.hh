#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH

#include "Obiekt3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Wektor.hh"
#include "Draw3D_api_interface.hh"
#include "przeszkoda.hh"

using std::vector;
using std::cout;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using Wektor3D=Wektor<double,3>;

class powierzchnia: public Obiekt3D, public przeszkoda
{
private:
    double X;
public:
    powierzchnia(Wektor3D srodek,double x);
    bool Czy_Kolizja(InterfejsDrona *InDr);
    void rysuj();
};

#endif