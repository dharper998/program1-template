#include "Star.h"
#include <iostream>
#include <cstdlib>

Starnode::Starnode(){
	this->planet = NULL;
	this->next = NULL;
	this->prev = NULL;
}

Starnode::Starnode(Planet * p){
	this->planet = p;
	this->next = NULL;
	this->prev = NULL;
}

Starlist::Starlist(){
	this->head = NULL;
	this->tail = NULL;
	this->current_planets = 0;
}

Starlist::~Starlist(){
	for(Starnode *temp = this->head; temp != NULL; temp = temp->next){
		delete temp;
	}
}

long Starlist::addPlanet(){
	Planet * new_planet = new Planet(rand()%3001);
	Starnode * to_add = new Starnode(new_planet);
	if(this->head == NULL){
		this->head = to_add;
		this->tail = to_add;
	} else {
		(this->tail)->next = to_add;
		to_add->prev = this->tail;
		this->tail = to_add;
	}
	this->current_planets++;
	return new_planet->getID();
}

bool Starlist::removePlanet(int id){
	for(Starnode *temp = this->head; temp != NULL; temp = temp->next){
		if((temp->planet)->getID() == id) {
			if(temp->prev == NULL) {

			}
		}
	}
	return false;
}

Planet * Starlist::getPlanet(int index){

}

void Starlist::orbit(){
	for(Starnode *temp = this->head; temp != NULL; temp = temp->next){
		(temp->planet)->orbit();
		temp = temp->next;
	}
	return;
}

void Starlist::printStarInfo(){
	std::cout << "The star currently has " << this -> current_planets << " planets." << std::endl;
	std::cout << "Planets:" << std::endl;
	for(Starnode *temp = this->head; temp != NULL; temp = temp->next){
		std::cout << "        " << (temp->planet)->getType() << " Planet " << (temp->planet)->getID() << " is " << (temp->planet)->getDistance() << " million miles away at position " << (temp->planet)->getPos() << " around the star." << std::endl;
		temp = temp->next;
	}
	return;
}

///////////////////////////////////////////////////////////////////////////////////////////////

Starvector::Starvector(){
	this -> current_planets = 0;
	this -> planets = NULL;
}

Starvector::~Starvector(){
	if(this -> planets == NULL){return;}
	delete[] this -> planets;
}

long Starvector::addPlanet(){
	Planet ** arr = new Planet*[this -> current_planets + 1];
	for(int i = 0; i < this -> current_planets; i++){
		arr[i] = this -> planets[i];
	}
	Planet *p = new Planet(rand()%3001);
	arr[this -> current_planets] = p;
	this -> current_planets++;
	delete[] this -> planets;
	this -> planets = arr;
	return p->getID();
}

bool Starvector::removePlanet(long id){//changed implementation from lab, may not work
	int index = -1;
	for(int i = 0; i < this -> current_planets; i++){
		if(this -> planets[i] -> getID() == id){
			index = i;
		}
	}
	if(index == -1){return false;}
	Planet ** arr = new Planet*[this -> current_planets - 1];
	for(int j = 0; j < this -> current_planets-1; j++){
		if(j < index){arr[j] = this -> planets[j];}
		else if (j > index){arr[j] = this -> planets[j+1];}
	}
	delete planets[index];
	delete[] this -> planets;
	this -> planets = arr;
	this -> current_planets--;
	return true;
}

Planet * Starvector::getPlanet(long id){
	for(int i = 0; i < this -> current_planets; i++){
		if(this -> planets[i] -> getID() == id){
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
