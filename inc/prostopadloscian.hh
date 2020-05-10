#ifndef PROSTOPALOSCIAN_HH
#define PROSTOPALOSCIAN_HH


#include "Wektor.hh"
#include "Macierz.hh"
#include "MacierzOb.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::vector;
using Wektor3D=Wektor<double,3>;

class prostopadloscian
{
protected:
    Wektor3D wierzcholki[8];
public:
    prostopadloscian();
    prostopadloscian(Wektor3D A, Wektor3D B, Wektor3D C, Wektor3D D, Wektor3D E, Wektor3D F, Wektor3D G, Wektor3D H);
    const Wektor3D  & operator[] (int index) const;
    Wektor3D & operator[] (int index);
    void rotacjaZ(const double kat);
    void rotacjaY(const double kat);
    void rotacjaX(const double kat);
    int rysuj(drawNS::Draw3DAPI & api);
    
};


#endif