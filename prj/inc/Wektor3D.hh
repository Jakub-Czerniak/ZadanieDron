#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

#include "Wektor.hh"

class Wektor3D: public Wektor<double,3>
{
    protected:
static int AktualnaIl;
static int LacznaIl;
    public:
Wektor3D();
Wektor3D(double xx,double yy,double zz);
Wektor3D(Wektor<double,3> W);
Wektor3D(Wektor3D &W);
~Wektor3D();
static int IleAktu();
static int IleLaczn();
};

#endif