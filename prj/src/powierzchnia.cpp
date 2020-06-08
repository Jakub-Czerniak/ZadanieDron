#include "powierzchnia.hh"

    powierzchnia::powierzchnia(Wektor3D srodek,double x)
    {
        Srodek=srodek;
        X=x;
    }

   bool powierzchnia::Czy_Kolizja(InterfejsDrona *InDr)
   {
     Wektor3D C=InDr->Get_C();
     
     if(Srodek[2]>=C[2])
     {
      return false;
     }
      std::cout<<"Woda Kolizja"<< std::endl;
     return true;
   }


    void powierzchnia::rysuj()
    {
      ID= api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-X+Srodek[0],-X+Srodek[1],Srodek[2]-1), drawNS::Point3D(-X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]-1), drawNS::Point3D(-X+Srodek[0],0+Srodek[1],Srodek[2]-1), drawNS::Point3D(-X+Srodek[0],0.5*X+Srodek[1],Srodek[2]-1), drawNS::Point3D(-X+Srodek[0],X+Srodek[1],Srodek[2]-1)
	  },{
  drawNS::Point3D(-0.75*X+Srodek[0],-X+Srodek[1],Srodek[2]+1), drawNS::Point3D(-0.75*X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]+1), drawNS::Point3D(-0.75*X+Srodek[0],0+Srodek[1],Srodek[2]+1), drawNS::Point3D(-0.75*X+Srodek[0],0.5*X+Srodek[1],Srodek[2]+1), drawNS::Point3D(-0.75*X+Srodek[0],X+Srodek[1],Srodek[2]+1)
	  },{
	drawNS::Point3D(-0.5*X+Srodek[0],-X+Srodek[1],Srodek[2]-1), drawNS::Point3D(-0.5*X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]-1), drawNS::Point3D(-0.5*X+Srodek[0],0+Srodek[1],Srodek[2]-1), drawNS::Point3D(-0.5*X+Srodek[0],0.5*X+Srodek[1],Srodek[2]-1), drawNS::Point3D(-0.5*X+Srodek[0],X+Srodek[1],Srodek[2]-1)       
	  },{
  drawNS::Point3D(-0.25*X+Srodek[0],-X+Srodek[1],Srodek[2]+1), drawNS::Point3D(-0.25*X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]+1), drawNS::Point3D(-0.25*X+Srodek[0],0+Srodek[1],Srodek[2]+1), drawNS::Point3D(-0.25*X+Srodek[0],0.5*X+Srodek[1],Srodek[2]+1), drawNS::Point3D(-0.25*X+Srodek[0],X+Srodek[1],Srodek[2]+1)       
	  },{
	drawNS::Point3D(-0+Srodek[0],-X+Srodek[1],Srodek[2]-1), drawNS::Point3D(-0+Srodek[0],-0.5*X+Srodek[1],Srodek[2]-1), drawNS::Point3D(-0+Srodek[0],0+Srodek[1],Srodek[2]-1), drawNS::Point3D(-0+Srodek[0],0.5*X+Srodek[1],Srodek[2]-1), drawNS::Point3D(-0+Srodek[0],X+Srodek[1],Srodek[2]-1)       
	  },{
  drawNS::Point3D(0.25*X+Srodek[0],-X+Srodek[1],Srodek[2]+1), drawNS::Point3D(0.25*X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]+1), drawNS::Point3D(0.25*X+Srodek[0],0+Srodek[1],Srodek[2]+1), drawNS::Point3D(0.25*X+Srodek[0],0.5*X+Srodek[1],Srodek[2]+1), drawNS::Point3D(0.25*X+Srodek[0],X+Srodek[1],Srodek[2]+1)       
	  },{
	drawNS::Point3D(0.5*X+Srodek[0],-X+Srodek[1],Srodek[2]-1), drawNS::Point3D(0.5*X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]-1), drawNS::Point3D(0.5*X+Srodek[0],0+Srodek[1],Srodek[2]-1), drawNS::Point3D(0.5*X+Srodek[0],0.5*X+Srodek[1],Srodek[2]-1), drawNS::Point3D(0.5*X+Srodek[0],X+Srodek[1],Srodek[2]-1)       
	  },{
  drawNS::Point3D(0.75*X+Srodek[0],-X+Srodek[1],Srodek[2]+1), drawNS::Point3D(0.75*X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]+1), drawNS::Point3D(0.75*X+Srodek[0],0+Srodek[1],Srodek[2]+1), drawNS::Point3D(0.75*X+Srodek[0],0.5*X+Srodek[1],Srodek[2]+1), drawNS::Point3D(0.75*X+Srodek[0],X+Srodek[1],Srodek[2]+1)       
	  },{    
	drawNS::Point3D(X+Srodek[0],-X+Srodek[1],Srodek[2]-1), drawNS::Point3D(X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]-1), drawNS::Point3D(X+Srodek[0],0+Srodek[1],Srodek[2]-1), drawNS::Point3D(X+Srodek[0],0.5*X+Srodek[1],Srodek[2]-1), drawNS::Point3D(X+Srodek[0],X+Srodek[1],Srodek[2]-1)       
	  }},"light-blue");
    }