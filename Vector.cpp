#include "vector.h"

Vector::Vector() {
	this->array = NULL;
	this->vectSize = 0;
}

Vector::~Vector() {
	delete[] this->array;
}

void Vector::insert(int index, Planet * p) {
	if(this == NULL) {return;}

	//if array is null, create new array of size index+1 and insert the element
	if(this->array = NULL) { 
		this->array = new Planet *[index+1];
		this->vectSize = index+1;
		this->array[index] = p;
		return;
	}

	//if the array is big enough, increase the array size by 1 and insert the element at index
	if(this->vectSize >= index) {
		this->vectSize++;
		Planet ** temp = new Planet *[this->vectSize];
		for(int i=0;i<index;i++) {
			temp[i] = this->array[i];
		}
		temp[index] = p;
		for(int i=index+1;i<this->vectSize;i++) {
			temp[i] = this->array[i-1];
		}
		this->array = temp;

	//if the array is not big enough, extend the array to be size index+1
	} else {
		Planet ** temp = new Planet *[index+1];
		for(int i=0;i<this->vectSize;i++) {
			temp[i] = this->array[i];
		}
		temp[index] = p;
		this->array = temp;
		this->vectSize = index+1;
	}
}

Planet * Vector::read(int index) {
	//if index is outside of the array, return null
	if(this == NULL || this->array == NULL || index > vectSize) {return NULL;}

	//if index is within the array, return the element at index
	if(index <= this->vectSize) {
		return this->array[index];
	}
}

bool Vector::remove(int index) {
	//if the vector size is less than index, return null
	if(this == NULL || this->array = NULL || this->vectSize <= index) {return false;}

	//create a new array, copy elements up to index
	Planet ** temp = new Planet *[this->vectSize-1];
	for(int i=0; i<this->index;i++) {
		temp[i] = this->array[i];
	}

	//copy elements from index+1 to vectSize
	for(int i=index+1; i<this->vectSize;i++) {
		temp[i-1] = this->array[i];
	}

	//delete the planet at index, set array to new array, increment vectSize
	delete this->array[index];
	this->array = temp;
	this->vectSize++;
	return true;
}
