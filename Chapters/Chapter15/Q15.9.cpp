#include <cstdlib>
#include "Q15.9.hpp"

IntArray::IntArray(){
	size=0;
	array  = new int[size]();
}

IntArray::IntArray(size_t x): size(x){
	array  = new int[size]();
	/*	
	for(size_t i=0;i<size;i++){
		//array[i]=0;
		printf("array[%ld]:%d\n",i,array[i]);
	}
	*/
}

IntArray::IntArray(const IntArray & rhs) : size(rhs.size){
	printf("run the copy constructor.\n");
	array  = new int[size]();//The () is used to initial the elements to 0.
	for(size_t j=0;j<size;j++){
		array[j]=rhs.array[j];
	}
}

IntArray & IntArray::operator=(IntArray & rhs){
	if(this!=&rhs){
		int * temp = new int[rhs.size];//If u do the initialization with for loop then u don't need to use () to initalize.
		for(size_t k=0;k<rhs.size;k++){
			temp[k] = rhs.array[k]; 
		}
		delete[] array;
		size = rhs.size;
		array = temp;
	}	
	return *this;
}

int & IntArray::operator[](size_t index){
	//int & ans = array[index];
	printf("call the operator[].\n");
	return array[index];
}

const int & IntArray::operator[](size_t index) const{
	printf("call the const operator[].\n");
	return array[index];
}

size_t IntArray::getSize() const{
	return sizeof(this->array);
}


void IntArray::printArray()const{
	for(size_t i=0;i<size;i++){
		printf("array[%ld]:%d\n",i,this->array[i]);
	}
}

IntArray::~IntArray(){
	printf("call destructor.\n");
	delete[] array;
	//free(array);
}

int main(void){
	/*
	size_t n = 2;
	//int * a1 = new int[n]();
	int * a1 = new int[n];
	//a1();
	for(size_t i=0;i<n;i++){
		a1[i]=0;
		//printf("%d\n", a1[i]);
	}
	for(size_t j=0;j<n;j++){
		printf("%d\n", a1[j]);
	}
	delete[] a1;
	*/
	size_t index = 0;
	printf("a1:\n");
	IntArray a1;
	a1.printArray();
	printf("Size of a1:%ld\n", a1.getSize());
	//printf("array[%ld]:%d\n", 2, a1[index]);
	printf("a2:\n");
	IntArray a2(3);
	int a2x = a2[index];
	printf("Overload[]: a2[%ld]:%d\n", index, a2x);
	const int & a2y = a2[index];
	printf("Overload const[]: a2[%ld]:%d\n", index, a2y);
	a2.printArray();
	printf("Size of a2:%ld\n", a2.getSize());
	printf("a3:\n");
	IntArray a3 = a2;
	a3.printArray();
	printf("Size of a3:%ld\n", a3.getSize());
	printf("a1 = a2:\n");
	a1 = a2;
	a1.printArray();
	printf("Size of a1:%ld\n", a1.getSize());	
	return EXIT_SUCCESS;
}






