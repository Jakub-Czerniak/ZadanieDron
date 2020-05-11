#include "MacierzOb.hh"

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
