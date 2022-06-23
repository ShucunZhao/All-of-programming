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
   	IntArray & operator=(IntArray & rhs);
	int & operator[](size_t index);//The C++ will omit the return type,so please don't use the same name of the operator though they have different return type.
	const int & operator[](size_t index)const;
	void printArray()const;
	size_t getSize()const;

	~IntArray();
};

