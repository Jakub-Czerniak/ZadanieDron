#ifndef PROSTOPALOSCIAN_HH
#define PROSTOPALOSCIAN_HH


#include "Obiekt3D.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzOb.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "InterfejsDrona.hh"

using std::vector;
using std::cout;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using Wektor3D=Wektor<double,3>;

class prostopadloscian : public Obiekt3D
{
protected:
    Wektor3D wierzcholki[8];
public:
    prostopadloscian();
    prostopadloscian(double X, double Y, double Z);
    void przesun(Wektor3D &Wek);
    void rotacjaZ(const double kat);
    void rotacjaY(const double kat);
    void rotacjaX(const double kat);
    void rysuj();
    
};


#endif