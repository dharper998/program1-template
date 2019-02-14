#ifndef VECTORH_DH
#define VECTORH_DH
#include "Planet.h"

class Vector {
private:
	Planet ** array;
	int vectSize;
public:
	Vector();
	~Vector();
	void insert(int index, Planet * p);
	Planet * read(int index);
	bool remove(int index);
	int size(){return this->vectSize;};
};



#endif
