#ifndef LIST_AG
#define LIST_AG

class Node{
public:
	Planet *data;
	Node *next;
	Node *prev;
	Node();
};

class List{
private:
	unsigned int length;
public:
	Node *head, tail;
	List();
	~List();
	void insert(int, Planet *);
	Planet *read(int);
	bool remove(int);
	unsigned int size(){return this -> size;}
};

#endif
