#ifndef VECTORH_DH
#define VECTORH_DH

class Vector {
private:
	Planet ** array;
	unsigned int vectSize;
public:
	~Vector();
	void insert(int, Planet);
	Planet * read(int);
	bool remove(int index);
	unsigned int size(){return this->vectSize;};
};



#endif
