#include "dron.hh"

dron::dron(prostopadloscian prst, Wektor3D orient)
{
    for (int i=0;i<8;i++)
    {
        wierzcholki[i]=prst[i];
    }
    orientacja=orient;
}

Wektor3D dron::znajdzOrientacje()
{
    return orientacja;
}
void dron::zmienOrientacje(Wektor3D Wek)
{
    orientacja = Wek;
}

dron dron::plyn(double odl,double kat) //nie dziala
{
MacierzOb MacO(kat,'x');
Wektor3D ruch;
orientacja=MacO*orientacja;
ruch=orientacja*odl;
for (int i=0;i<8;i++)
{
    wierzcholki[i]=wierzcholki[i]+ruch;
}
return *this;
}
