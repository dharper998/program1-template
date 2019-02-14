#include "Planet.h"
#include <iostream>
#include <cstdlib>


Planet::Planet(int distance){
	this->id = (long int)this;
	this->distance = distance;
	this->pos = rand() % 360;
	int random = rand() % 3;
	if(random == 0){this -> type ='h';}
	else if(random == 1){this -> type = 'r';}
	else{this -> type = 'g';}
}

int Planet::orbit(){
	if(this -> pos >= 0 && this -> pos < 359)
		this -> pos++;
	else
		this -> pos = 0;
	return this -> pos;
}

