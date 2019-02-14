#include "List.h"
#include <iostream>
#include <cstdlib>

Node::Node(Planet *p){
	this -> data = p;
	this -> next = NULL;
	this -> prev = NULL;
}

List::List(){
	this -> head = NULL;
	this -> tail = NULL;
	this -> length = 0;
}

List::~List(){
	for(Node *temp = this -> head; temp != NULL; temp = temp -> next){
		delete temp;
	}
	delete this;
}

void List::insert(int index, Planet *p){
	Node *to_insert = new Node(p);
	if(this == NULL){return;}
	if(this -> length == 0){//if there's nothing
		this -> head = to_insert;
		this -> tail = to_insert;
		this -> length++;
		return;
	}
	if(index == 0){//if it wants to add at beginning
		to_insert -> next = this -> head;
		this -> head = to_insert;
		this -> length++;
		return;
	}
	if(index >= this -> length){//if it wants to add at or past end
		to_insert -> prev = this -> tail;
		this -> tail = to_insert;
		this -> length++;
		return;
		
	}
	node *temp = this -> head;
	for(int i = 0; i < index; i++){//if it wants to add in the middle
		temp = temp -> next;
	}
	node *add_next = temp -> next;
	node *add_prev = temp -> prev;
	temp -> next -> prev = to_insert;
	temp -> prev -> next = to_insert;
	to_insert -> next = add_next;
	to_insert -> prev = add_prev;
	this -> length++;
	return;
}

Planet *List::read(int index){
	if(this == NULL || index >= this -> length){
		return NULL;
	}
	node *temp = this -> head;
	for(int i = 0; i < index; i++){
		temp = temp -> next;
	}
	return temp -> data;
}

bool List::remove(int index){//NOT DONE
	if(index >= this -> length){return false;}
	if(index == 0){
		node *to_delete = this -> head;
		this -> head = this -> head -> next;
		delete to_delete;
		this -> length--;
		return true;
	}
	if(index == this -> length - 1){
		node *to_delete = this -> tail;
		this -> tail = this -> tail -> prev;
		delete to_delete;
		this -> length--;
		return true;
	}
	//TO ADD: DELETE IN MIDDLE
}
