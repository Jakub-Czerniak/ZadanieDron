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

dron dron::plyn(double odl,double kat) 
{
MacierzOb MacO(kat,'y');
Wektor3D ruch;
orientacja=MacO*orientacja;
ruch=orientacja*odl;
for (int i=0;i<8;i++)
{
    wierzcholki[i]=wierzcholki[i]+ruch;
}
return *this;
}

void dron::rotacjaZ(const double kat)
{
MacierzOb MacO(kat,'z');

orientacja=MacO*orientacja;

     for(int ind=0;ind<8;ind++)
    {
    wierzcholki[ind]=MacO*wierzcholki[ind];
    }
}
void dron::rotacjaY(const double kat)
{
MacierzOb MacO(kat,'x');

orientacja=MacO*orientacja;

     for(int ind=0;ind<8;ind++)
    {
    wierzcholki[ind]=MacO*wierzcholki[ind];
    }
}
void dron::rotacjaX(const double kat)
{
MacierzOb MacO(kat,'y');

orientacja=MacO*orientacja;

     for(int ind=0;ind<8;ind++)
    {
    wierzcholki[ind]=MacO*wierzcholki[ind];
    }
}