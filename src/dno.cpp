   #include "dno.hh"
   
    dno::dno(Wektor3D srodek,double x)
    {
        Srodek=srodek;
        X=x;
    }

   bool dno::Czy_Kolizja(InterfejsDrona *InDr)
   {
     double R=InDr->Get_R();
     Wektor3D C=InDr->Get_C();
     
     if(Srodek[2]+R<=C[2])
      return false;
      std::cout<<"Dno Kolizja"<< std::endl;
     return true;
   }

    void dno::rysuj()
    {
             ID= api->draw_surface(vector<vector<Point3D> > {{
	drawNS::Point3D(-X+Srodek[0],-X+Srodek[1],Srodek[2]), drawNS::Point3D(-X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(-X+Srodek[0],0+Srodek[1],Srodek[2]), drawNS::Point3D(-X+Srodek[0],0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(-X+Srodek[0],X+Srodek[1],Srodek[2])
	  },{
  drawNS::Point3D(-0.75*X+Srodek[0],-X+Srodek[1],Srodek[2]), drawNS::Point3D(-0.75*X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(-0.75*X+Srodek[0],0+Srodek[1],Srodek[2]), drawNS::Point3D(-0.75*X+Srodek[0],0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(-0.75*X+Srodek[0],X+Srodek[1],Srodek[2])
	  },{
	drawNS::Point3D(-0.5*X+Srodek[0],-X+Srodek[1],Srodek[2]), drawNS::Point3D(-0.5*X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(-0.5*X+Srodek[0],0+Srodek[1],Srodek[2]), drawNS::Point3D(-0.5*X+Srodek[0],0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(-0.5*X+Srodek[0],X+Srodek[1],Srodek[2])       
	  },{
  drawNS::Point3D(-0.25*X+Srodek[0],-X+Srodek[1],Srodek[2]), drawNS::Point3D(-0.25*X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(-0.25*X+Srodek[0],0+Srodek[1],Srodek[2]), drawNS::Point3D(-0.25*X+Srodek[0],0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(-0.25*X+Srodek[0],X+Srodek[1],Srodek[2])       
	  },{
	drawNS::Point3D(-0+Srodek[0],-X+Srodek[1],Srodek[2]), drawNS::Point3D(-0+Srodek[0],-0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(-0+Srodek[0],0+Srodek[1],Srodek[2]), drawNS::Point3D(-0+Srodek[0],0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(-0+Srodek[0],X+Srodek[1],Srodek[2])       
	  },{
  drawNS::Point3D(0.25*X+Srodek[0],-X+Srodek[1],Srodek[2]), drawNS::Point3D(0.25*X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(0.25*X+Srodek[0],0+Srodek[1],Srodek[2]), drawNS::Point3D(0.25*X+Srodek[0],0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(0.25*X+Srodek[0],X+Srodek[1],Srodek[2])       
	  },{
	drawNS::Point3D(0.5*X+Srodek[0],-X+Srodek[1],Srodek[2]), drawNS::Point3D(0.5*X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(0.5*X+Srodek[0],0+Srodek[1],Srodek[2]), drawNS::Point3D(0.5*X+Srodek[0],0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(0.5*X+Srodek[0],X+Srodek[1],Srodek[2])       
	  },{
  drawNS::Point3D(0.75*X+Srodek[0],-X+Srodek[1],Srodek[2]), drawNS::Point3D(0.75*X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(0.75*X+Srodek[0],0+Srodek[1],Srodek[2]), drawNS::Point3D(0.75*X+Srodek[0],0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(0.75*X+Srodek[0],X+Srodek[1],Srodek[2])       
	  },{    
	drawNS::Point3D(X+Srodek[0],-X+Srodek[1],Srodek[2]), drawNS::Point3D(X+Srodek[0],-0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(X+Srodek[0],0+Srodek[1],Srodek[2]), drawNS::Point3D(X+Srodek[0],0.5*X+Srodek[1],Srodek[2]), drawNS::Point3D(X+Srodek[0],X+Srodek[1],Srodek[2])       
	  }},"grey");
    }