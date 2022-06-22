#include <cstdio>
#include <cstdlib>
#include "Q15.7.hpp"

Example::Example():data(0){
	printf("Example defalult constructor\n");
}

Example::Example(int x) : data(x){
	printf("Example constructor (%d)\n", data);
}

Example::Example(const Example & e) : data(e.data){
	printf("Example copy constructor (%d)\n", data);
}

Example & Example::operator=(const Example & rhs){
	data = rhs.data;
	printf("Example assign operator\n");
	return *this;
}

Example::~Example(){
	printf("Example destructor [with %d]\n", data);//The destructor function is called by reverse order of the creation.
}

void Example::add(int x){
	data+=x;
}

void f(Example & a, Example b){//When use the object not the reference 								//of object, the complier will invoke the 							  //copy constructor to make the formal-parameter be the actual-parameter.  
	printf("Inside f\n");
	a.add(10);
	b.add(20);
}

int main(void){
	printf("e1:\n");
	Example e1;//e1.data=0
	printf("e2:\n");
	Example e2(4);//e2.data=4
	printf("e3:\n");
	Example e3 = e2;//e3.data=4
	e3.add(5);//e3.data=9
	printf("e1 = e2:\n");
	e1 = e2;//e1.data=4
	printf("f(e1,e2):\n");
	//Example & ex = e1;
	//Example & ey = e2;
	//f(ex,ey);//e1.data=14;e2.data=24
	f(e1,e2);//e1.data=14;e2.data=4
	printf("back in main\n");
	return EXIT_SUCCESS;
}
/*Output:
 * e1:
 * Example default constructor
 * e2:
 * Example constructor (4)
 * e3:
 * Example copy constructor (4)
 * e1 = e2:
 * Example assign operator
 * f(e1,e2):
 * Example copy constructor (4)
 * Inside f
 * Example destructor [with 24]
 * back in main
 * Example destructor [with 9]
 * Example destructor [with 4]
 * Example destructor [with 14]
 */







