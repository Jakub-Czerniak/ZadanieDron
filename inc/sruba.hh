#ifndef SRUBA_HH
#define SRUBA_HH


#include <math.h>
#include "graniastoslup.hh"
#include "Obiekt3D.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzOb.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"

using std::vector;
using std::cout;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using Wektor3D=Wektor<double,3>;

class sruba: public graniastoslup
{
    double wysokosc;
public:
sruba();
sruba(Wektor3D Zaczepienie, double R, double H);
double Get_H();
void rysuj();
};



#endif