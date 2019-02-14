#ifndef LIST_AG
#define LIST_AG
#include "Planet.h"

class Node{
public:
	Planet *data;
	Node *next;
	Node *prev;
	Node();
	Node(Planet * p);
};

class List{
private:
	int length;
public:
	Node *head, *tail;
	List();
	~List();
	void insert(int, Planet *);
	Planet *read(int);
	bool remove(int);
	int size(){return this -> length;}
};

#endif
