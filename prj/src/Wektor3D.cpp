#include "Wektor3D.hh"


Wektor3D::Wektor3D(double xx,double yy,double zz) 
{
  tab[0]= xx;
  tab[1]= yy;
  tab[2]= zz;
  ++LacznaIl;
  ++AktualnaIl;
}

Wektor3D::Wektor3D() 
{
  tab[0]= 0;
  tab[1]= 0;
  tab[2]= 0;
  ++LacznaIl;
  ++AktualnaIl;
}

Wektor3D::Wektor3D(Wektor3D &W)
{
  tab[0]=W.tab[0] ;
  tab[1]=W.tab[1];
  tab[2]=W.tab[2];
  ++LacznaIl;
  ++AktualnaIl;
}

Wektor3D::Wektor3D(Wektor<double,3> W) : Wektor<double,3>(W)
{
  ++LacznaIl;
  ++AktualnaIl;
}

Wektor3D::~Wektor3D()
{
  --AktualnaIl;
}

int Wektor3D::IleAktu()
{
  return AktualnaIl;
}
int Wektor3D::IleLaczn()
{
  return LacznaIl;
}