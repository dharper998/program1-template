#include "Star.h"
#include <iostream>
#include <cstdlib>

Starlist::Starlist(){
	this -> next_id = 0;
	this -> current_planets = 0;
	this -> planets = NULL;
}

Starlist::~Starlist(){
	if(this -> planets == NULL){return;}
	delete[] this -> planets;
}

int Starlist::addPlanet(){
	Planet ** arr = new Planet*[this -> current_planets + 1];
	for(int i = 0; i < this -> current_planets; i++){
		arr[i] = this -> planets[i];
	}
	int id = this -> next_id;
	this -> next_id++;
	Planet *p = new Planet(id);
	arr[this -> current_planets] = p;
	this -> current_planets++;
	delete[] this -> planets;
	this -> planets = arr;
	return id;
}

bool Starlist::removePlanet(int id){
	for(int i = 0; i < this -> current_planets; i++){
		if(this -> planets[i] -> getID() == id){
			Planet ** arr = new Planet*[this -> current_planets - 1];
			
			bool passed = false;
			for(int j = 0; j < this -> current_planets-1; j++){
				if(j == i){passed = true;}
				if(!passed){arr[j] = this -> planets[j];}
				else{arr[j] = this -> planets[j+1];}
			}
			delete planets[i];
			delete[] this -> planets;
			this -> planets = arr;
			this -> current_planets--;
			return true;
		}
	}
	return false;
}

Planet * Starlist::getPlanet(int index){
	for(int i = 0; i < this -> current_planets; i++){
		if(this -> planets[i] -> getID() == index){
			return this -> planets[i];
		}
	}
	return NULL;
}

void Starlist::orbit(){
	for(int i = 0; i < this -> current_planets; i++){
		this -> planets[i] -> orbit();
	}
}

void Starlist::printStarInfo(){
	std::cout << "The star currently has " << this -> current_planets << " planets." << std::endl;
	std::cout << "Planets:" << std::endl;
	for(int i = 0; i < this -> current_planets; i++){
		std::cout << "        " << this -> planets[i] -> getType() << " Planet " << this -> planets[i] -> getID() << " is " << this -> planets[i] -> getDistance() << " million miles away at position " << this -> planets[i] -> getPos() << " around the star." << std::endl;
	}
}


Starvector::Starvector(){
	this -> next_id = 0;
	this -> current_planets = 0;
	this -> planets = NULL;
}

Starvector::~Starvector(){
	if(this -> planets == NULL){return;}
	delete[] this -> planets;
}

int Starvector::addPlanet(){
	Planet ** arr = new Planet*[this -> current_planets + 1];
	for(int i = 0; i < this -> current_planets; i++){
		arr[i] = this -> planets[i];
	}
	int id = this -> next_id;
	this -> next_id++;
	Planet *p = new Planet(id);
	arr[this -> current_planets] = p;
	this -> current_planets++;
	delete[] this -> planets;
	this -> planets = arr;
	return id;
}

bool Starvector::removePlanet(int id){
	for(int i = 0; i < this -> current_planets; i++){
		if(this -> planets[i] -> getID() == id){
			Planet ** arr = new Planet*[this -> current_planets - 1];
			
			bool passed = false;
			for(int j = 0; j < this -> current_planets-1; j++){
				if(j == i){passed = true;}
				if(!passed){arr[j] = this -> planets[j];}
				else{arr[j] = this -> planets[j+1];}
			}
			delete planets[i];
			delete[] this -> planets;
			this -> planets = arr;
			this -> current_planets--;
			return true;
		}
	}
	return false;
}

Planet * Starvector::getPlanet(int index){
	for(int i = 0; i < this -> current_planets; i++){
		if(this -> planets[i] -> getID() == index){
			return this -> planets[i];
		}
	}
	return NULL;
}

void Starvector::orbit(){
	for(int i = 0; i < this -> current_planets; i++){
		this -> planets[i] -> orbit();
	}
}

void Starvector::printStarInfo(){
	std::cout << "The star currently has " << this -> current_planets << " planets." << std::endl;
	std::cout << "Planets:" << std::endl;
	for(int i = 0; i < this -> current_planets; i++){
		std::cout << "        " << this -> planets[i] -> getType() << " Planet " << this -> planets[i] -> getID() << " is " << this -> planets[i] -> getDistance() << " million miles away at position " << this -> planets[i] -> getPos() << " around the star." << std::endl;
	}
}
