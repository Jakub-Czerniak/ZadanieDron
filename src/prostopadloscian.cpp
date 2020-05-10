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

     for(int ind=0;ind<8;ind++)
    {
    wierzcholki[ind]=MacO*wierzcholki[ind];
    }
}

void prostopadloscian::rotacjaX(const double kat)
{ 
    MacierzOb MacO(kat,'x');

     for(int ind=0;ind<8;ind++)
    {
    wierzcholki[ind]=MacO*wierzcholki[ind];
    }
}

void prostopadloscian::rotacjaY(const double kat)
{ 
    MacierzOb MacO(kat,'y');

     for(int ind=0;ind<8;ind++)
    {
    wierzcholki[ind]=MacO*wierzcholki[ind];
    }
}

int prostopadloscian::rysuj(drawNS::Draw3DAPI & api)
{
int pom= api.draw_polyhedron(vector<vector<Point3D> > {{
	Point3D(wierzcholki[0][0],wierzcholki[0][1],wierzcholki[0][2]), Point3D(wierzcholki[1][0],wierzcholki[1][1],wierzcholki[1][2]), Point3D(wierzcholki[2][0],wierzcholki[2][1],wierzcholki[2][2]),Point3D(wierzcholki[3][0],wierzcholki[3][1],wierzcholki[3][2])
      },{
	Point3D(wierzcholki[4][0],wierzcholki[4][1],wierzcholki[4][2]), Point3D(wierzcholki[5][0],wierzcholki[5][1],wierzcholki[5][2]), Point3D(wierzcholki[6][0],wierzcholki[6][1],wierzcholki[6][2]), Point3D(wierzcholki[7][0],wierzcholki[7][1],wierzcholki[7][2])      
	  }},"blue");
return pom;
}