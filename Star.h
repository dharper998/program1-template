#ifndef STAR_AG
#define STAR_AG
#include "Planet.h"

class Starnode{
public:
  Planet * planet;
  Starnode * next;
  Starnode * prev;
  Starnode();
  Starnode(Planet * p);
};

class Starlist{
private:
  int current_planets;
public:
  Starnode * head, * tail;
  Starlist();
	~Starlist();
  long addPlanet();
	bool removePlanet(int);
	Planet *getPlanet(int);
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
