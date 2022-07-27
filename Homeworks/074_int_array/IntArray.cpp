#include <cstring>
#include <cassert>
#include "IntArray.h"

IntArray::IntArray():data(NULL),numElements(0){
	
}

IntArray::IntArray(int n):data(new int[n]),numElements(n){

}

IntArray::IntArray(const IntArray & rhs):numElements(rhs.numElements){
	data = new int[numElements+1];
	for(int i=0;i<numElements;i++){
		data[i] = rhs[i];
	}
	//memcpy(data, rhs.data, numElements);
	data[numElements] = '\0';
}

IntArray & IntArray::operator=(const IntArray & rhs){
	if(this!=&rhs){
		/*
		//Have a more accurate metho to do this:
		for(int i=0;i<numElements;i++){
			data[i] = rhs[i];
		}
		*/
		
		//Truly way: Because the original memory of data is allocated by 
		//heap automatically, if you assign the new value to it we cannot 
		//determine the new size of memory, so you shoule delete it first
		//and new a new memory address and let data handle the new memory.
		int * temp = new int[numElements];
		for(int i=0;i<numElements;i++){
			temp[i] = rhs[i];
		}
		delete[] data;
		data = NULL;
		numElements = rhs.numElements;
		data = temp;//This way can determine new size of the assigment because we 
		//may assign it to the different size new value.
		
	}
	return *this;
}

int & IntArray::operator[](int index){
	assert(index>=0||index<=numElements);
	int & result = data[index];
	return result;
}

const int & IntArray::operator[](int index)const{
	assert(index>=0||index<=numElements);
	const int & result = data[index];
	return result;
}

int IntArray::size()const{
	//return sizeof(*data)/sizeof(data[0]);
	return numElements;
}

bool IntArray::operator==(const IntArray & rhs) const{
	if(numElements!=rhs.numElements){
		return 0;
	}
	for(int i=0;i<numElements;i++){
		if(data[i]!=rhs.data[i]){
			return 0;
		}
	}
	return 1;
}


bool IntArray::operator!=(const IntArray & rhs) const{
	if(numElements!=rhs.numElements){
		return 1;
	}
	for(int i=0;i<numElements;i++){
		if(data[i]!=rhs.data[i]){
			return 1;
		}
	}
	return 0;
}

std::ostream & operator<<(std::ostream & s, const IntArray & rhs){
	s<<"{";
	for(int j=0;j<rhs.size();j++){
		s<<rhs[j];
		if(j!=rhs.size()-1){
			s<<", ";
		}
	}
	s<<"}";
	return s;
}

IntArray::~IntArray(){
	delete[] data;
}
