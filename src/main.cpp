#include <iostream>

#include "Draw3D_api_interface.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Obiekt3D.hh"
#include "MacierzOb.hh"
#include "Macierz.hh"
#include "prostopadloscian.hh"
#include "graniastoslup.hh"
#include "dron.hh"
#include "sruba.hh"
#include "powierzchnia.hh"
#include "dno.hh"
#include "prst_przeszkoda.hh"
#include "Wektor3D.hh"

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::cin;
using std::vector;
using std::shared_ptr;
using std::endl;




void menu()
{
cout << endl;
cout << "r - zadaj ruch na wprost" << endl;
cout << "o - zadaj zmiane orientacji" << endl;
cout << "z - zmien drona" << endl;
cout << "m - wyswietl menu" << endl << endl;
cout << "k - koniec dzialania programu" << endl << endl;
}

int Wektor3D::AktualnaIl;
int Wektor3D::LacznaIl;

int main() {
vector<przeszkoda*> LPrzeszkod;
dron *LDronow[2];
int kat, odleglosc;
int dronid=0;
char wybor;
dron plywak0(sruba(Wektor3D(-2,-1.1,0),0.5,1), sruba(Wektor3D(-2,1.1,0),0.5,1), 4,5,5);
dron plywak1(sruba(Wektor3D(-2,-1.1,0),0.5,1), sruba(Wektor3D(-2,1.1,0),0.5,1), 4,4,3); 
powierzchnia Pow(Wektor3D(0,0,18),20);
dno Dno(Wektor3D(0,0,-20),20);
PrstPrzeszkoda Prst0(8,7,9,Wektor3D(-2,-2,-15.5));
PrstPrzeszkoda Prst1(1.5,1.5,20,Wektor3D(18,18,-11));
PrstPrzeszkoda Prst2(3,3,7,Wektor3D(13,-15,-17));
PrstPrzeszkoda Prst3(2,32,8,Wektor3D(-15,0,-16));
drawNS::Draw3DAPI * api = new APIGnuPlot3D(-20,20,-20,20,-20,20,0); 

plywak0.plyn(10,45);
cout<< plywak0.Get_C();
Prst0.Set_api(api);
Prst1.Set_api(api);
Prst2.Set_api(api);
Prst3.Set_api(api);
Pow.Set_api(api);
Dno.Set_api(api);
plywak0.Set_api(api);
plywak1.Set_api(api);
Prst0.rysuj();
Prst1.rysuj();
Prst2.rysuj();
Prst3.rysuj();
Pow.rysuj();
Dno.rysuj();
plywak0.rysuj();
plywak1.rysuj();

LPrzeszkod.push_back(&Prst0);
LPrzeszkod.push_back(&Prst1);
LPrzeszkod.push_back(&Prst2);
LPrzeszkod.push_back(&Prst3);
LPrzeszkod.push_back(&Pow);
LPrzeszkod.push_back(&Dno);
LPrzeszkod.push_back(&plywak1);
LDronow[0]=&plywak0;
LDronow[1]=&plywak1;


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
  if(kat>90 || kat<-90)
  cout<<"Podaj kat miedzy 90, a -90."<< endl <<endl;
  else
  {
  cout << "Podaj wartosc odleglosci, na ktora ma sie przemiescic dron." << endl;
  cout << "Wartosc odleglosci> ";
  cin >> odleglosc;
  cout << endl << endl;
  if(odleglosc<0)
  cout<<"Podaj dodatnią odleglosc."<<endl<<endl;
  else
  LDronow[dronid]->plyn_anim(odleglosc, kat,  LPrzeszkod);
  cout<< "Aktualna ilosc obiektow Wektor3D:" << Wektor3D::IleAktu() << endl;
  cout << "Laczna ilosc obiektow Wektor3D:" << Wektor3D::IleLaczn() <<endl << endl;
  }
  
  break;

  case 'o':
  cout << "Podaj wartosc kata obrotu w stopniach." << endl; 
  cout << "Wartosc kata> ";
  cin >> kat;
  cout << endl;
  LDronow[dronid]->obrot_anim(kat);
  cout<< "Aktualna ilosc obiektow Wektor3D:" << Wektor3D::IleAktu() << endl;
  cout << "Laczna ilosc obiektow Wektor3D:" << Wektor3D::IleLaczn() <<endl << endl;
  break;

  case 'm':
  menu();
  break;
  

  case 'z':
  cout<<"Zmiana drona"<<endl<<endl;
  if(dronid==1)
  {
  dronid=0;
  LPrzeszkod[6]=&plywak1;
  }
  else
  {
  dronid=1;
  LPrzeszkod[6]=&plywak0;
  }
  
  break;
  }
}


}