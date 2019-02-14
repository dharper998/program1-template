#ifndef STAR_AG
#define STAR_AG
#include "Planet.h"

class Star{
	private:
        int current_planets;
        int next_id;
	public:
        Planet ** planets;
        Star();
		~Star();
        int addPlanet();
		bool removePlanet(int);
		Planet *getPlanet(int);
		void orbit();
        void printStarInfo();
        int getCurrentNumPlanets(){return this -> current_planets;}
        //you may add any additional methods you may need.
};

#endif
