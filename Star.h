#ifndef STAR_AG
#define STAR_AG
#include "Planet.h"

class Starlist{
private:
        int current_planets;
        int next_id;
public:
        Planet ** planets;
        Starlist();
	~Starlist();
        int addPlanet();
	bool removePlanet(int);
	Planet *getPlanet(int);
	void orbit();
        void printStarInfo();
        int getCurrentNumPlanets(){return this -> current_planets;}
};

class Starvector{
private:
        int current_planets;
        int next_id;
public:
        Planet ** planets;
        Starvector();
	~Starvector();
        int addPlanet();
	bool removePlanet(int);
	Planet *getPlanet(int);
	void orbit();
        void printStarInfo();
        int getCurrentNumPlanets(){return this -> current_planets;}
};

#endif
