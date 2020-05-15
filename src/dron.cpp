#include "dron.hh"

dron::dron(prostopadloscian prst)
{
    Macierz<double,3> Mac(Wektor3D(1,0,0),Wektor3D(0,1,0),Wektor3D(0,0,1));
    MacierzOb MacJedn(Mac);
    Orientacja=Mac;
    Wektor3D Wek(0,0,0);
    Srodek=Wek;
    for (int i=0;i<8;i++)
    {
        wierzcholki[i]=prst[i];
    }
}


dron dron::plyn(double odl,double kat) 
{
double pi=3.14159265358979323846264338327;
Wektor3D ruch(cos(kat*pi/180)*odl,0,sin(kat*pi/180)*odl);
ruch=Orientacja*ruch;
przesun(ruch);

return *this;
}