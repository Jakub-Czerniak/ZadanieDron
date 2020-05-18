#include <iostream>

#include "Draw3D_api_interface.hh"
#include "Dr3D_gnuplot_api.hh"
#include "MacierzOb.hh"
#include "Macierz.hh"
#include "Wektor.hh"
#include "prostopadloscian.hh"
#include "dron.hh"

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::cin;
using std::endl;
using Wektor3D=Wektor<double,3>;



void menu()
{
cout << endl;
cout << "r - zadaj ruch na wprost" << endl;
cout << "o - zadaj zmiane orientacji" << endl;
cout << "m - wyswietl menu" << endl << endl;
cout << "k - koniec dzialania programu" << endl << endl;
}


int main() {

int kat, odleglosc;
char wybor;
prostopadloscian prst(Wektor3D(-2,-1.5,-1),Wektor3D(-2,1.5,-1),Wektor3D(2,1.5,-1),Wektor3D(2,-1.5,-1),Wektor3D(-2,-1.5,1),Wektor3D(-2,1.5,1),Wektor3D(2,1.5,1),Wektor3D(2,-1.5,1));
dron plywak(prst); 


drawNS::Draw3DAPI * api = new APIGnuPlot3D(-20,20,-20,20,-20,20,0); 

int a=plywak.rysuj(*api);
menu();

while(wybor!='k')
{
  cout << "Twoj wybor (m - menu): ";
  cin >> wybor;
  cout << endl;
  switch (wybor)
  {
  case 'r':
  cout << "Podaj wartosc kata (wznoszenia/opadania) w stopniach." << endl;
  cout << "Wartosc kata> ";
  cin >> kat;
  cout << endl << endl;

  cout << "Podaj wartosc odleglosci, na ktora ma sie przemiescic dron." << endl;
  cout << "Wartosc odleglosci> ";
  cin >> odleglosc;
  cout << endl << endl;
  for(int i=0;i<odleglosc*10;i++)
{
  api->erase_shape(a);
  plywak.plyn(0.1,kat);
  a=plywak.rysuj(*api); 
}
   break;

  case 'o':
    cout << "Podaj wartosc kata obrotu w stopniach." << endl; 
    cout << "Wartosc kata> ";
    cin >> kat;
    cout << endl << endl;

    for (int j=0;j<kat*10;j++)
    {
      api->erase_shape(a);
      plywak.rotacjaZ(0.1); 
      a=plywak.rysuj(*api);
    }

    break;

  case 'm':
    menu();
    break;
  } 
}


}