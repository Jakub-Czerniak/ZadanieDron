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

prostopadloscian::prostopadloscian(Wektor3D A, Wektor3D B, Wektor3D C, Wektor3D D, Wektor3D E, Wektor3D F, Wektor3D G, Wektor3D H)
{
    wierzcholki[0]=A;
    wierzcholki[1]=B;
    wierzcholki[2]=C;
    wierzcholki[3]=D;
    wierzcholki[4]=E;
    wierzcholki[5]=F;
    wierzcholki[6]=G;
    wierzcholki[7]=H;
}

const Wektor3D & prostopadloscian::operator[] (int index) const
{
  if (index < 0 || index >=8)
    {
       std::cerr << "Index poza zakresem" << std::endl;
       exit(1);
    }
  return wierzcholki[index];  
}

Wektor3D & prostopadloscian::operator[] (int index)
{
  if (index < 0 || index >=8)
    {
      std::cerr << "Index poza zakresem" << std::endl;
      exit(1);
    }
  return wierzcholki[index];
}

void prostopadloscian::rotacjaZ(const double kat)
{ 
    MacierzOb MacO(kat,'z');
Macierz3D Pom;
Pom=Orientacja*MacO;
Orientacja=MacierzOb(Pom);
}


void prostopadloscian::przesun(Wektor3D &Wek)
{
 Srodek= Srodek + Wek;
}

int prostopadloscian::rysuj(drawNS::Draw3DAPI & api)
{
 Wektor3D wierzcholki_Glb[8];
  for(int ind=0;ind<8;ind++)
{
wierzcholki_Glb[ind]=Srodek+Orientacja*wierzcholki[ind];
}
int pom= api.draw_polyhedron(vector<vector<Point3D> > {{
	Point3D(wierzcholki_Glb[0][0],wierzcholki_Glb[0][1],wierzcholki_Glb[0][2]), Point3D(wierzcholki_Glb[1][0],wierzcholki_Glb[1][1],wierzcholki_Glb[1][2]), Point3D(wierzcholki_Glb[2][0],wierzcholki_Glb[2][1],wierzcholki_Glb[2][2]),Point3D(wierzcholki_Glb[3][0],wierzcholki_Glb[3][1],wierzcholki_Glb[3][2])
      },{
	Point3D(wierzcholki_Glb[4][0],wierzcholki_Glb[4][1],wierzcholki_Glb[4][2]), Point3D(wierzcholki_Glb[5][0],wierzcholki_Glb[5][1],wierzcholki_Glb[5][2]), Point3D(wierzcholki_Glb[6][0],wierzcholki_Glb[6][1],wierzcholki_Glb[6][2]), Point3D(wierzcholki_Glb[7][0],wierzcholki_Glb[7][1],wierzcholki_Glb[7][2])      
	  }},"blue");
return pom;
}