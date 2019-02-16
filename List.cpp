#include "List.h"
#include <iostream>
#include <cstdlib>

Node::Node(Planet *p){
	this -> data = p;
	this -> next = NULL;
	this -> prev = NULL;
}

Node::Node() {
	this->data = NULL;
	this->next = NULL;
	this->prev = NULL;
}

List::List(){
	this -> head = NULL;
	this -> tail = NULL;
	this -> length = 0;
}

List::~List(){
	Node * next;
	for(Node *temp = this -> head; temp != NULL; temp = next){
		next = temp->next;
		delete temp->data;
		delete temp;
	}
}

void List::insert(int index, Planet *p){
	Node *to_insert = new Node(p);
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
		to_insert -> prev -> next = to_insert;
		this -> tail = to_insert;
		this -> length++;
		return;

	}
	Node *temp = this -> head;
	for(int i = 0; i < index; i++){//if it wants to add in the middle
		temp = temp -> next;
	}
	Node *add_next = temp -> next;
	Node *add_prev = temp -> prev;
	temp -> next -> prev = to_insert;
	temp -> prev -> next = to_insert;
	to_insert -> next = add_next;
	to_insert -> prev = add_prev;
	this -> length++;
	return;
}

Planet *List::read(int index){
	if(index >= this -> length){
		return NULL;
	}
	Node *temp = this -> head;
	for(int i = 0; i < index; i++){
			temp = temp -> next;
	}
	return temp -> data;
}

bool List::remove(int index){//NOT WORKING
	if(index >= this -> length){return false;}
	if(index == 0){
		Node *to_delete = this -> head;
		this -> head = this -> head -> next;
		delete to_delete->data;
		delete to_delete;
		this -> length--;
		return true;
	}
	if(index == this -> length - 1){
		Node *to_delete = this -> tail;
		this -> tail = this -> tail -> prev;
		delete to_delete->data;
		delete to_delete;
		this -> length--;
		return true;
	}
	Node *temp = this -> head;
	for(int i = 0; i < index; i++){
		temp = temp -> next;
	}
	temp -> next -> prev = temp -> prev;
	temp -> prev -> next = temp -> next;
	delete temp->data;
	delete temp;
	this -> length--;
	return true;
}
