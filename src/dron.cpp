#include "dron.hh"


dron::dron(sruba L, sruba P, double X, double Y, double Z) 
{
    wierzcholki[0]=Wektor3D(-0.5*X, -0.5*Y, -0.5*Z);
    wierzcholki[1]=Wektor3D(-0.5*X, 0.5*Y, -0.5*Z);
    wierzcholki[2]=Wektor3D(0.5*X, 0.5*Y, -0.5*Z);
    wierzcholki[3]=Wektor3D(0.5*X, -0.5*Y, -0.5*Z);
    wierzcholki[4]=Wektor3D(-0.5*X, -0.5*Y, 0.5*Z);
    wierzcholki[5]=Wektor3D(-0.5*X, 0.5*Y, 0.5*Z);
    wierzcholki[6]=Wektor3D(0.5*X, 0.5*Y, 0.5*Z);
    wierzcholki[7]=Wektor3D(0.5*X, -0.5*Y, 0.5*Z);
    Macierz<double,3> Mac(Wektor3D(1,0,0),Wektor3D(0,1,0),Wektor3D(0,0,1));
    Orientacja=Mac;
    Wektor3D Wek(0,0,0);
    Srodek=Wek;
    lewa=L;
    prawa=P;

double H_srb=L.Get_H();
if(H_srb+X>Z && H_srb+X>Y)
    promien= (H_srb+X)/2;
    else if(Y>Z)
    promien=Y/2;
    else
    promien=Z/2;
    
}

double dron::Get_R()
{
  return promien;
}

Wektor3D dron::Get_C()
{
  return Srodek;
}


void dron::plyn(double odl,double kat) 
{
Wektor3D ruch(cos(kat*M_PI/180)*odl,0,sin(kat*M_PI/180)*odl);
ruch=Orientacja*ruch;
lewa.przesun(ruch);
prawa.przesun(ruch);
przesun(ruch);
}

void dron::plyn_anim(double odl,double kat, przeszkoda *LPrzeszkod[7])
{
  bool skoncz=false;
      for(int i=0;i<odl*10 && skoncz!=true ;i++)
{
skoncz=Czy_Kolizja(LPrzeszkod);
if(skoncz==false)
{
    plyn(0.1,kat);
    rysuj(); 
}
else
{
    plyn(0.1,kat+180);
    rysuj(); 
}

}
}


void dron::obrot_anim(double kat)
{
  if(kat<0)
  {
      for (int j=0;j<abs(kat);j++)
    {
      lewa.rotacjaZ(-1);
      prawa.rotacjaZ(-1);
      rotacjaZ(-1); 
      rysuj();
    }
  }
  if(kat>0)
  {
        for (int j=0;j<kat;j++)
    {
      lewa.rotacjaZ(1);
      prawa.rotacjaZ(1);
      rotacjaZ(1); 
      rysuj();
    }
  }
}

void dron::rysuj()
{
this->prostopadloscian::rysuj();
lewa.sruba::rysuj();
prawa.sruba::rysuj();
}

void dron::Set_api(drawNS::Draw3DAPI *Api)
{
    api=Api;
    lewa.sruba::Set_api(Api);
    prawa.sruba::Set_api(Api);
}

bool dron::Czy_Kolizja(InterfejsDrona *InDr)
{
  Wektor3D Srodek2=InDr->Get_C();
  double promien2=InDr->Get_R();

  if(dlugosc(Srodek-Srodek2)<=promien+promien2)
  {
    std::cout<<"Dron Kolizja"<< std::endl;
    return true;
  }
  return false;
}

bool dron::Czy_Kolizja(przeszkoda *LPrzeszkod[7])
{
for(int i=0;i<7;i++)
{
if(LPrzeszkod[i]->Czy_Kolizja(this)==true)
{
  
return true;
}
}
return false;
}