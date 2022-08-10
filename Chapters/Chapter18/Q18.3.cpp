#include <cstdlib>
#include <iostream>

using namespace std;

class Test{
	int x;
public: 
	virtual void someA(){
		cout<<"Some A."<<endl;
	}
};

class Sub : public Test{
	int y;
public:
	virtual void someA(){
		cout<<"Some B."<<endl;
	}
};

int main(int argc, char ** argv){
	Test T;
	Sub S;
	Test * ptr1 = &T;
	Test * ptr2 = &S;
	ptr1->someA();
	ptr2->someA();
	return EXIT_SUCCESS;
}
