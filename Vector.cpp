#include "vector.h"

Vector::Vector() {
	this->array = NULL;
	this->size = 0;
}

Vector::~Vector() {
	delete[] this->array;
}

void Vector::insert(int index, Planet * p) {
	if(this->array = NULL) {
		this->array = new Planet *[index+1];
		this->size = index+1;
		this->array[index] = p;
		return;
	}
	if(this->size <= index) {
		this->size++;
		Planet ** temp = new Planet *[this->size];
		for(int i=0;i<index;i++) {
			temp[i] = this->array[i];
		}
		temp[index] = p;
		for(int i=index+1;i<this->size;i++) {
			temp[i] = this->array[i-1];
		}
		this->array = temp;
	} else {
		Planet ** temp = new Planet *[index+1];
		for(int i=0;i<this->size;i++) {
			temp[i] = this->array[i];
		}
		temp[index] = p;
		this->array = temp;
		this->size = index+1;
	}
}

Planet * Vector::read(int index) {
	if(index <= this->size) {
		return this->array[index];
	}
	return NULL;
}

bool Vector::remove(int index) {
	if(this->array = NULL || this->size <= index) {
		return false;
	}
	Planet ** temp = new Planet *[this->size-1];
	for(int i=0; i<this->index;i++) {
		temp[i] = this->array[i];
	}
	for(int i=index+1; i<this->size;i++) {
		temp[i-1] = this->array[i];
	}
	this->array = temp;
	this->size++;
	return true;
}
