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
	this -> size = 0;
}

List::~List(){
	for(Node *temp = this -> head; temp != NULL; temp = temp -> next){
		delete temp;
	}
	delete this;
}

void List::insert(int index, Planet *p){//NOT DONE
	Node *to_insert = new Node(p);
	if(this == NULL){return;}
	if(this -> size == 0){
		this -> head = to_insert;
		this -> tail = to_insert;
		this -> size++;
		return;
	}
	if(index == 0){
		to_insert -> next = this -> head;
		this -> head = to_insert;
		this -> size++;
	}
	if(index >= this -> size){
		
	}
	node *temp = this -> head;
	for(int i = 0; i < index; i++){
		if(temp == NULL)
	}
}
