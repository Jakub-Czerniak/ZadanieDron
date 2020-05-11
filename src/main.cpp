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
cout << "k - koniec dzialania programu" << endl;
}


int main() {

int kat, odleglosc;
char wybor;
prostopadloscian prst(Wektor3D(0,0,0),Wektor3D(0,3,0),Wektor3D(4,3,0),Wektor3D(4,0,0),Wektor3D(0,0,2),Wektor3D(0,3,2),Wektor3D(4,3,2),Wektor3D(4,0,2));
Wektor3D orient(1,0,0);
dron plywak(prst, orient);

drawNS::Draw3DAPI * api = new APIGnuPlot3D(-10,10,-10,10,-10,10,0); 

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
  api->erase_shape(a);
  plywak.plyn(odleglosc, kat); //nie dziala jeszcze
  a=plywak.rysuj(*api); 
   break;

  case 'o':
    cout << "Podaj wartosc kata obrotu w stopniach." << endl; 
    cout << "Wartosc kata> ";
    cin >> kat;
    cout << endl << endl;
    api->erase_shape(a);
    plywak.rotacjaZ(kat); 
    a=plywak.rysuj(*api);
    break;

  case 'm':
    menu();
    break;
  } 
}


}