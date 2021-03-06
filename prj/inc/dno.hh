#ifndef DNO_HH
#define DNO_HH

#include "Obiekt3D.hh"
#include "Wektor3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "InterfejsDrona.hh"
#include "przeszkoda.hh"

using std::vector;
using std::cout;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


class dno: public Obiekt3D, public przeszkoda
{
private:
    double X;
public:
    dno(Wektor3D srodek,double x);
    bool Czy_Kolizja(InterfejsDrona *InDr);
    void rysuj();
};

#endif