#include "prostopadloscian.hh"

prostopadloscian::prostopadloscian()
{
    wierzcholki[0]=Wektor3D();
    wierzcholki[1]=Wektor3D();
    wierzcholki[2]=Wektor3D();
    wierzcholki[3]=Wektor3D();
    wierzcholki[4]=Wektor3D();
    wierzcholki[5]=Wektor3D();
    wierzcholki[6]=Wektor3D();
    wierzcholki[7]=Wektor3D();
}

prostopadloscian::prostopadloscian(double X, double Y, double Z)
{
    wierzcholki[0]=Wektor3D(-0.5*X, -0.5*Y, -0.5*Z);
    wierzcholki[1]=Wektor3D(-0.5*X, 0.5*Y, -0.5*Z);
    wierzcholki[2]=Wektor3D(0.5*X, 0.5*Y, -0.5*Z);
    wierzcholki[3]=Wektor3D(0.5*X, -0.5*Y, -0.5*Z);
    wierzcholki[4]=Wektor3D(-0.5*X, -0.5*Y, 0.5*Z);
    wierzcholki[5]=Wektor3D(-0.5*X, 0.5*Y, 0.5*Z);
    wierzcholki[6]=Wektor3D(0.5*X, 0.5*Y, 0.5*Z);
    wierzcholki[7]=Wektor3D(0.5*X, -0.5*Y, 0.5*Z);
}


void prostopadloscian::rotacjaZ(const double kat)
{ 
  MacierzOb MacO(kat,'z');
  Macierz3D Pom;
  Pom=MacO*Orientacja;
  Orientacja=MacierzOb(Pom);
}

void prostopadloscian::przesun(Wektor3D &Wek)
{
 Srodek= Srodek + Wek;
}


void prostopadloscian::rysuj()
{
 Wektor3D wierzcholki_Glb[8];
  for(int ind=0;ind<8;ind++)
{
wierzcholki_Glb[ind]=Srodek+Orientacja*wierzcholki[ind];
}
if(ID!=-1)
api->erase_shape(ID);
ID= api->draw_polyhedron(vector<vector<Point3D> > {{
	Point3D(wierzcholki_Glb[0][0],wierzcholki_Glb[0][1],wierzcholki_Glb[0][2]), Point3D(wierzcholki_Glb[1][0],wierzcholki_Glb[1][1],wierzcholki_Glb[1][2]), Point3D(wierzcholki_Glb[2][0],wierzcholki_Glb[2][1],wierzcholki_Glb[2][2]),Point3D(wierzcholki_Glb[3][0],wierzcholki_Glb[3][1],wierzcholki_Glb[3][2])
      },{
	Point3D(wierzcholki_Glb[4][0],wierzcholki_Glb[4][1],wierzcholki_Glb[4][2]), Point3D(wierzcholki_Glb[5][0],wierzcholki_Glb[5][1],wierzcholki_Glb[5][2]), Point3D(wierzcholki_Glb[6][0],wierzcholki_Glb[6][1],wierzcholki_Glb[6][2]), Point3D(wierzcholki_Glb[7][0],wierzcholki_Glb[7][1],wierzcholki_Glb[7][2])      
	  }},"blue");
}