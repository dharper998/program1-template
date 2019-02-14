#ifndef VECTORH_DH
#define VECTORH_DH

class Vector {
private:
	Planet ** array;
	unsigned int size;
public:
	~Vector();
	void insert(int, Planet);
	Planet * read(int);
	bool remove(int index);
	unsigned int size(){return this->size()};
}



#endif
