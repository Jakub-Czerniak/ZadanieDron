#include "dron.hh"


dron::dron(sruba L, sruba P, Wektor3D A, Wektor3D B, Wektor3D C, Wektor3D D, Wektor3D E, Wektor3D F, Wektor3D G, Wektor3D H) 
{
    wierzcholki[0]=A;
    wierzcholki[1]=B;
    wierzcholki[2]=C;
    wierzcholki[3]=D;
    wierzcholki[4]=E;
    wierzcholki[5]=F;
    wierzcholki[6]=G;
    wierzcholki[7]=H;
    Macierz<double,3> Mac(Wektor3D(1,0,0),Wektor3D(0,1,0),Wektor3D(0,0,1));
    Orientacja=Mac;
    Wektor3D Wek(0,0,0);
    Srodek=Wek;
    lewa=L;
    prawa=P;
}


dron dron::plyn(double odl,double kat) 
{
Wektor3D ruch(cos(kat*M_PI/180)*odl,0,sin(kat*M_PI/180)*odl);
ruch=Orientacja*ruch;
lewa.przesun(ruch);
prawa.przesun(ruch);
przesun(ruch);

return *this;
}

dron dron::plyn_anim(double odl,double kat, drawNS::Draw3DAPI &api)
{
      for(int i=0;i<odl*10;i++)
{
  plyn(0.1,kat);
  rysujD(api); 
  api.redraw();
}
return *this;
}


void dron::obrot_anim(double kat, drawNS::Draw3DAPI &api)
{
  if(kat<0)
  {
      for (int j=0;j<abs(kat);j++)
    {
      lewa.rotacjaZ(-1);
      prawa.rotacjaZ(-1);
      rotacjaZ(-1); 
      rysujD(api);
      api.redraw();
    }
  }
  if(kat>0)
  {
        for (int j=0;j<kat;j++)
    {
      lewa.rotacjaZ(1);
      prawa.rotacjaZ(1);
      rotacjaZ(1); 
      rysujD(api);
      api.redraw();
    }
  }
}

void dron::rysujD(drawNS::Draw3DAPI &api)
{
this->rysuj(api);
lewa.rysuj(api);
prawa.rysuj(api);
}