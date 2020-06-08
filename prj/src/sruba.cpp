#include "sruba.hh"

sruba::sruba()
{
     wierzcholki[0]=Wektor3D();
    wierzcholki[1]=Wektor3D();
    wierzcholki[2]=Wektor3D();
    wierzcholki[3]=Wektor3D();
    wierzcholki[4]=Wektor3D();
    wierzcholki[5]=Wektor3D();
    wierzcholki[6]=Wektor3D();
    wierzcholki[7]=Wektor3D();
    wierzcholki[8]=Wektor3D();
    wierzcholki[9]=Wektor3D();
    wierzcholki[10]=Wektor3D();
    wierzcholki[11]=Wektor3D();
}


sruba::sruba(Wektor3D Zaczepienie, double R, double H)
{
    wierzcholki[0]=Wektor3D(Zaczepienie[0],Zaczepienie[1]-R,Zaczepienie[2]);
    wierzcholki[1]=Wektor3D(Zaczepienie[0],Zaczepienie[1]-R/sqrt(3),Zaczepienie[2]+2*R/sqrt(3));
    wierzcholki[2]=Wektor3D(Zaczepienie[0],Zaczepienie[1]+R/sqrt(3),Zaczepienie[2]+2*R/sqrt(3));
    wierzcholki[3]=Wektor3D(Zaczepienie[0],Zaczepienie[1]+R,Zaczepienie[2]);
    wierzcholki[4]=Wektor3D(Zaczepienie[0],Zaczepienie[1]+R/sqrt(3),Zaczepienie[2]-2*R/sqrt(3));
    wierzcholki[5]=Wektor3D(Zaczepienie[0],Zaczepienie[1]-R/sqrt(3),Zaczepienie[2]-2*R/sqrt(3));
    wierzcholki[6]=Wektor3D(Zaczepienie[0]-H,Zaczepienie[1]-R,Zaczepienie[2]);
    wierzcholki[7]=Wektor3D(Zaczepienie[0]-H,Zaczepienie[1]-R/sqrt(3),Zaczepienie[2]+2*R/sqrt(3));
    wierzcholki[8]=Wektor3D(Zaczepienie[0]-H,Zaczepienie[1]+R/sqrt(3),Zaczepienie[2]+2*R/sqrt(3));
    wierzcholki[9]=Wektor3D(Zaczepienie[0]-H,Zaczepienie[1]+R,Zaczepienie[2]);
    wierzcholki[10]=Wektor3D(Zaczepienie[0]-H,Zaczepienie[1]+R/sqrt(3),Zaczepienie[2]-2*R/sqrt(3));
    wierzcholki[11]=Wektor3D(Zaczepienie[0]-H,Zaczepienie[1]-R/sqrt(3),Zaczepienie[2]-2*R/sqrt(3));

    Macierz<double,3> Mac(Wektor3D(1,0,0),Wektor3D(0,1,0),Wektor3D(0,0,1));
    Orientacja=Mac;
    Srodek=Wektor3D(0,0,0);
    wysokosc=H;
}

double sruba::Get_H()
{
  return wysokosc;
}

void sruba::rysuj()
{
 Wektor3D wierzcholki_Glb[12];

  for(int ind=0;ind<12;ind++)
{
wierzcholki_Glb[ind]=Srodek+Orientacja*wierzcholki[ind];
}
api->erase_shape(ID);
ID= api->draw_polyhedron(vector<vector<Point3D> > {{
	Point3D(wierzcholki_Glb[0][0],wierzcholki_Glb[0][1],wierzcholki_Glb[0][2]), Point3D(wierzcholki_Glb[1][0],wierzcholki_Glb[1][1],wierzcholki_Glb[1][2]), Point3D(wierzcholki_Glb[2][0],wierzcholki_Glb[2][1],wierzcholki_Glb[2][2]),Point3D(wierzcholki_Glb[3][0],wierzcholki_Glb[3][1],wierzcholki_Glb[3][2]),Point3D(wierzcholki_Glb[4][0],wierzcholki_Glb[4][1],wierzcholki_Glb[4][2]), Point3D(wierzcholki_Glb[5][0],wierzcholki_Glb[5][1],wierzcholki_Glb[5][2])
      },{
	Point3D(wierzcholki_Glb[6][0],wierzcholki_Glb[6][1],wierzcholki_Glb[6][2]), Point3D(wierzcholki_Glb[7][0],wierzcholki_Glb[7][1],wierzcholki_Glb[7][2]), Point3D(wierzcholki_Glb[8][0],wierzcholki_Glb[8][1],wierzcholki_Glb[8][2]), Point3D(wierzcholki_Glb[9][0],wierzcholki_Glb[9][1],wierzcholki_Glb[9][2]), Point3D(wierzcholki_Glb[10][0],wierzcholki_Glb[10][1],wierzcholki_Glb[10][2]),Point3D(wierzcholki_Glb[11][0],wierzcholki_Glb[11][1],wierzcholki_Glb[11][2])
	  }},"blue");
}