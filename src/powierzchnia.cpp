#include "powierzchnia.hh"

    powierzchnia::powierzchnia(Wektor3D srodek,double x,double z)
    {
        Srodek=srodek;
        X=x;
        Z=z;
    }
    void powierzchnia::rysuj(drawNS::Draw3DAPI & api)
    {
      ID= api.draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-X,-X,Z-2), drawNS::Point3D(-X,-0.5*X,Z-2), drawNS::Point3D(-X,0,Z-2), drawNS::Point3D(-X,0.5*X,Z-2), drawNS::Point3D(-X,X,Z-2)
	  },{
  drawNS::Point3D(-0.75*X,-X,Z), drawNS::Point3D(-0.75*X,-0.5*X,Z), drawNS::Point3D(-0.75*X,0,Z), drawNS::Point3D(-0.75*X,0.5*X,Z), drawNS::Point3D(-0.75*X,X,Z)
	  },{
	drawNS::Point3D(-0.5*X,-X,Z-2), drawNS::Point3D(-0.5*X,-0.5*X,Z-2), drawNS::Point3D(-0.5*X,0,Z-2), drawNS::Point3D(-0.5*X,0.5*X,Z-2), drawNS::Point3D(-0.5*X,X,Z-2)       
	  },{
  drawNS::Point3D(-0.25*X,-X,Z), drawNS::Point3D(-0.25*X,-0.5*X,Z), drawNS::Point3D(-0.25*X,0,Z), drawNS::Point3D(-0.25*X,0.5*X,Z), drawNS::Point3D(-0.25*X,X,Z)       
	  },{
	drawNS::Point3D(-0,-X,Z-2), drawNS::Point3D(-0,-0.5*X,Z-2), drawNS::Point3D(-0,0,Z-2), drawNS::Point3D(-0,0.5*X,Z-2), drawNS::Point3D(-0,X,Z-2)       
	  },{
  drawNS::Point3D(0.25*X,-X,Z), drawNS::Point3D(0.25*X,-0.5*X,Z), drawNS::Point3D(0.25*X,0,Z), drawNS::Point3D(0.25*X,0.5*X,Z), drawNS::Point3D(0.25*X,X,Z)       
	  },{
	drawNS::Point3D(0.5*X,-X,Z-2), drawNS::Point3D(0.5*X,-0.5*X,Z-2), drawNS::Point3D(0.5*X,0,Z-2), drawNS::Point3D(0.5*X,0.5*X,Z-2), drawNS::Point3D(0.5*X,X,Z-2)       
	  },{
  drawNS::Point3D(0.75*X,-X,Z), drawNS::Point3D(0.75*X,-0.5*X,Z), drawNS::Point3D(0.75*X,0,Z), drawNS::Point3D(0.75*X,0.5*X,Z), drawNS::Point3D(0.75*X,X,Z)       
	  },{    
	drawNS::Point3D(X,-X,Z-2), drawNS::Point3D(X,-0.5*X,Z-2), drawNS::Point3D(X,0,Z-2), drawNS::Point3D(X,0.5*X,Z-2), drawNS::Point3D(X,X,Z-2)       
	  }},"gray");
    }