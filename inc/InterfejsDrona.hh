#ifndef INTERFEJSDRONA_HH
#define INTERFEJSDRONA_HH

#include "Dr3D_gnuplot_api.hh"
#include "Draw3D_api_interface.hh"
#include "Wektor.hh"
using Wektor3D=Wektor<double,3>;

class InterfejsDrona
{
public:
virtual double Get_R()=0;
virtual Wektor3D Get_C()=0;
virtual void plyn(double odl, double kat)=0;
virtual void obrot_anim(double kat)=0;
virtual void rysuj()=0;
virtual void Set_api(drawNS::Draw3DAPI *Api)=0;
};

#endif