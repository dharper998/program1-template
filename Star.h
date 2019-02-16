#ifndef STAR_AG
#define STAR_AG
#include "Planet.h"

class Starlist{
private:
  int current_planets;
public:
  Planet ** planets;
  Starlist();
	~Starlist();
  long addPlanet();
	bool removePlanet(long);
	Planet *getPlanet(long);
	void orbit();
  void printStarInfo();
  unsigned int getCurrentNumPlanets(){return this -> current_planets;}
};

class Starvector{
private:
  int current_planets;
public:
  Planet ** planets;
  Starvector();
	~Starvector();
  long addPlanet();
	bool removePlanet(long);
	Planet *getPlanet(long);
	void orbit();
  void printStarInfo();
  unsigned int getCurrentNumPlanets(){return this -> current_planets;}
};

#endif
