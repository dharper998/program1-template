#ifndef PLANET_AG
#define PLANET_AG

class Planet{
	private:
		long id;
		int pos;
		int distance;
		char type;
	public:
		Planet(int);
    int orbit();
		long getID(){return this -> id;}
    int getDistance(){return this -> distance;}
    int getPos(){return this -> pos;}
		char getType(){return this -> type;}
		//you may add any additional methods you may need.
};

#endif
