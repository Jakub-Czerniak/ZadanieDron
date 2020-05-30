#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "InterfejsDrona.hh"

class przeszkoda
{
public:
virtual bool Czy_Kolizja(InterfejsDrona *InDr)=0; 
};

#endif