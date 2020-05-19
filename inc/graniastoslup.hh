#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

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

class graniastoslup : public Obiekt3D
{protected:
Wektor3D wierzcholki[12]; 
public:
    graniastoslup();
    graniastoslup(Wektor3D A, Wektor3D B, Wektor3D C, Wektor3D D, Wektor3D E, Wektor3D F, Wektor3D G, Wektor3D H, Wektor3D I, Wektor3D J, Wektor3D K, Wektor3D L);
    void przesun(Wektor3D &Wek);
    void rotacjaZ(const double kat);
    void rotacjaX(const double kat);
    void rysuj(drawNS::Draw3DAPI & api);
};



#endif