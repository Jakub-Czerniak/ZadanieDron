#include "Obiekt3D.hh"

Obiekt3D::Obiekt3D()
{
    Srodek=Wektor3D();
    Orientacja=MacierzOb();
}

void Obiekt3D::Set_api(drawNS::Draw3DAPI *Api)
{
    api=Api;
}