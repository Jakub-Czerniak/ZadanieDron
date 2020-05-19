#include <iostream>

#include "Draw3D_api_interface.hh"
#include "Dr3D_gnuplot_api.hh"
#include "MacierzOb.hh"
#include "Macierz.hh"
#include "Wektor.hh"
#include "prostopadloscian.hh"
#include "graniastoslup.hh"
#include "dron.hh"
#include "sruba.hh"

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
sruba L(Wektor3D(-2,-1.1,0),0.5,1);
sruba P(Wektor3D(-2,1.1,0),0.5,1);
dron plywak(L, P, Wektor3D(-2,-1.5,-1),Wektor3D(-2,1.5,-1),Wektor3D(2,1.5,-1),Wektor3D(2,-1.5,-1),Wektor3D(-2,-1.5,1),Wektor3D(-2,1.5,1),Wektor3D(2,1.5,1),Wektor3D(2,-1.5,1)); 




drawNS::Draw3DAPI * api = new APIGnuPlot3D(-20,20,-20,20,-20,20,0); 



      api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-20,-20,-19), drawNS::Point3D(-20,-10,-19), drawNS::Point3D(-20,0,-19), drawNS::Point3D(-20,10,-19), drawNS::Point3D(-20,20,-19)
	  },{
  drawNS::Point3D(-15,-20,-19), drawNS::Point3D(-15,-10,-19), drawNS::Point3D(-15,0,-19), drawNS::Point3D(-15,10,-19), drawNS::Point3D(-15,20,-19)
	  },{
	drawNS::Point3D(-10,-20,-19), drawNS::Point3D(-10,-10,-19), drawNS::Point3D(-10,0,-19), drawNS::Point3D(-10,10,-19), drawNS::Point3D(-10,20,-19)       
	  },{
  drawNS::Point3D(-5,-20,-19), drawNS::Point3D(-5,-10,-19), drawNS::Point3D(-5,0,-19), drawNS::Point3D(-5,10,-19), drawNS::Point3D(-5,20,-19)       
	  },{
	drawNS::Point3D(-0,-20,-19), drawNS::Point3D(-0,-10,-19), drawNS::Point3D(-0,0,-19), drawNS::Point3D(-0,10,-19), drawNS::Point3D(-0,20,-19)       
	  },{
  drawNS::Point3D(5,-20,-19), drawNS::Point3D(5,-10,-19), drawNS::Point3D(5,0,-19), drawNS::Point3D(5,10,-19), drawNS::Point3D(5,20,-19)       
	  },{
	drawNS::Point3D(10,-20,-19), drawNS::Point3D(10,-10,-19), drawNS::Point3D(10,0,-19), drawNS::Point3D(10,10,-19), drawNS::Point3D(10,20,-19)       
	  },{
  drawNS::Point3D(15,-20,-19), drawNS::Point3D(15,-10,-19), drawNS::Point3D(15,0,-19), drawNS::Point3D(15,10,-19), drawNS::Point3D(15,20,-19)       
	  },{    
	drawNS::Point3D(20,-20,-19), drawNS::Point3D(20,-10,-19), drawNS::Point3D(20,0,-19), drawNS::Point3D(20,10,-19), drawNS::Point3D(20,20,-19)       
	  }},"grey");

    api->redraw();

      api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-20,-20,15), drawNS::Point3D(-20,-10,15), drawNS::Point3D(-20,0,15), drawNS::Point3D(-20,10,15), drawNS::Point3D(-20,20,15)
	  },{
  drawNS::Point3D(-15,-20,17), drawNS::Point3D(-15,-10,17), drawNS::Point3D(-15,0,17), drawNS::Point3D(-15,10,17), drawNS::Point3D(-15,20,17)
	  },{
	drawNS::Point3D(-10,-20,15), drawNS::Point3D(-10,-10,15), drawNS::Point3D(-10,0,15), drawNS::Point3D(-10,10,15), drawNS::Point3D(-10,20,15)       
	  },{
  drawNS::Point3D(-5,-20,17), drawNS::Point3D(-5,-10,17), drawNS::Point3D(-5,0,17), drawNS::Point3D(-5,10,17), drawNS::Point3D(-5,20,17)       
	  },{
	drawNS::Point3D(-0,-20,15), drawNS::Point3D(-0,-10,15), drawNS::Point3D(-0,0,15), drawNS::Point3D(-0,10,15), drawNS::Point3D(-0,20,15)       
	  },{
  drawNS::Point3D(5,-20,17), drawNS::Point3D(5,-10,17), drawNS::Point3D(5,0,17), drawNS::Point3D(5,10,17), drawNS::Point3D(5,20,17)       
	  },{
	drawNS::Point3D(10,-20,15), drawNS::Point3D(10,-10,15), drawNS::Point3D(10,0,15), drawNS::Point3D(10,10,15), drawNS::Point3D(10,20,15)       
	  },{
  drawNS::Point3D(15,-20,17), drawNS::Point3D(15,-10,17), drawNS::Point3D(15,0,17), drawNS::Point3D(15,10,17), drawNS::Point3D(15,20,17)       
	  },{    
	drawNS::Point3D(20,-20,15), drawNS::Point3D(20,-10,15), drawNS::Point3D(20,0,15), drawNS::Point3D(20,10,15), drawNS::Point3D(20,20,15)       
	  }},"light-blue");

api->redraw();

plywak.rysujD(*api);

api->redraw();

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
  plywak.plyn_anim(odleglosc, kat, *api);

  break;

  case 'o':
  cout << "Podaj wartosc kata obrotu w stopniach." << endl; 
  cout << "Wartosc kata> ";
  cin >> kat;
  cout << kat << endl << endl;
  plywak.obrot_anim(kat, *api);
  
  break;

  case 'm':
    menu();
    break;
  } 
}


}