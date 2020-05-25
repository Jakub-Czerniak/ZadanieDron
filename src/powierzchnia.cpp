#include "powierzchnia.hh"

    powierzchnia::powierzchnia(Wektor3D srodek,double x)
    {
        Srodek=srodek;
        X=x;
    }
    void powierzchnia::rysuj(drawNS::Draw3DAPI & api)
    {
      ID= api.draw_surface(vector<vector<Point3D> > {{
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