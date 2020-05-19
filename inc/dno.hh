#ifndef DNO_HH
#define DNO_HH

#include "Obiekt3D.hh"
#include "Wektor.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"

using std::vector;
using std::cout;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using Wektor3D=Wektor<double,3>;

class dno: public Obiekt3D
{
private:
    double X;
    double Z;
public:
    dno(Wektor3D srodek,double x,double z);
    void rysuj(drawNS::Draw3DAPI & api);
};

#endif