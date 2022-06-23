#include <cstdio>
#include <cstdlib>

class IntArray{
private:
	size_t size;
	int * array;//Just define a pointer here and let it point to the new 'new' one behind.
	//int * array = (int*)malloc(size*sizeof(int));
public:
	IntArray();
	IntArray(size_t x);
	IntArray(const IntArray & rhs);
   	//IntArray & operator=(IntArray & rhs);//Test the automatically provided 
	void printArray()const;
	size_t getSize()const;

	~IntArray();
};

