#include "prst_przeszkoda.hh"

PrstPrzeszkoda::PrstPrzeszkoda(double X, double Y, double Z, Wektor3D Przesuniecie)
{
    wierzcholki[0]=Wektor3D(-0.5*X, -0.5*Y, -0.5*Z);
    wierzcholki[1]=Wektor3D(-0.5*X, 0.5*Y, -0.5*Z);
    wierzcholki[2]=Wektor3D(0.5*X, 0.5*Y, -0.5*Z);
    wierzcholki[3]=Wektor3D(0.5*X, -0.5*Y, -0.5*Z);
    wierzcholki[4]=Wektor3D(-0.5*X, -0.5*Y, 0.5*Z);
    wierzcholki[5]=Wektor3D(-0.5*X, 0.5*Y, 0.5*Z);
    wierzcholki[6]=Wektor3D(0.5*X, 0.5*Y, 0.5*Z);
    wierzcholki[7]=Wektor3D(0.5*X, -0.5*Y, 0.5*Z);
    Srodek=Srodek+Przesuniecie;
}

bool PrstPrzeszkoda::Czy_Kolizja(InterfejsDrona *InDr)
{
Wektor3D OdlOdSrod=abs(Orientacja*wierzcholki[1]);
  double R=InDr->Get_R();
  Wektor3D C=InDr->Get_C();
   
  if(Srodek[2]+R+OdlOdSrod[2]<=C[2] || Srodek[1]+R+OdlOdSrod[1]<=C[1] || Srodek[0]+R+OdlOdSrod[0]<=C[0] )
    return false;
    std::cout<<"Prst Kolizja"<< std::endl;
  return true;
}