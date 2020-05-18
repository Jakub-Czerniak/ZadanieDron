#include "MacierzOb.hh"


MacierzOb::MacierzOb()
{
    tab[0][0]=1;
    tab[0][1]=0;
    tab[0][2]=0;
    tab[1][0]=0;
    tab[1][1]=1;
    tab[1][2]=0;
    tab[2][0]=0;
    tab[2][1]=0;
    tab[2][2]=1;
}
MacierzOb::MacierzOb(Macierz3D &Mac) : Macierz3D(Mac)
{ 
    if(abs(wyznacznik(Mac,3)-1)>0.0000001)
    {
        std::cout<<"Macierz nie jest ortonormalna" << std::endl; // później na cerr i exit(1)
    }

    Macierz3D PomTrans;
    Macierz3D Pom;
    
    PomTrans= Mac.transponuj();
    Pom=Mac*PomTrans;
    Macierz3D PomJed(Wektor3D(1,0,0),Wektor3D(0,1,0),Wektor3D(0,0,1));
    if(Pom!=PomJed)
    {
       std::cout<<"Macierz nie jest ortonormalna" << std::endl; // później na cerr i exit(1)
    }
}

MacierzOb::MacierzOb(double kat, char Os)
{
    double pi=3.14159265358979323846264338327;
    
    switch (Os)
{
case 'x':
    tab[0][0]=1;
    tab[0][1]=0;
    tab[0][2]=0;
    tab[1][0]=0;
    tab[1][1]=cos(kat*pi/180);
    tab[1][2]=-sin(kat*pi/180);
    tab[2][0]=0;
    tab[2][1]=sin(kat*pi/180);
    tab[2][2]=cos(kat*pi/180);
    break;

case 'z':
    tab[0][0]=cos(kat*pi/180);
    tab[0][1]=-sin(kat*pi/180);
    tab[0][2]=0;
    tab[1][0]=sin(kat*pi/180);
    tab[1][1]=cos(kat*pi/180);
    tab[1][2]=0;
    tab[2][0]=0;
    tab[2][1]=0;
    tab[2][2]=1;
    break;

case 'y':
    tab[0][0]=cos(kat*pi/180);
    tab[0][1]=0;
    tab[0][2]=sin(kat*pi/180);
    tab[1][0]=0;
    tab[1][1]=1;
    tab[1][2]=0;
    tab[2][0]=-sin(kat*pi/180);
    tab[2][1]=0;
    tab[2][2]=cos(kat*pi/180);
    break;

default:
    std::cerr<<"Brak takiej osi w ukladzie. " << std::endl;
    exit(1);
    break;
}
}