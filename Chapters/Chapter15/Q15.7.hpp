#include <cstdio>
#include <cstdlib>

class Example {
private:
	int data;
public:
	/*//The initial list should occur in the 
	 //declaration of the class so u will get 	  //error if initial list set here.
	Example():data(0);
	Example(int x):data(x);
	Example(const Example & e):data(e.data);
	*/
	Example();
	Example(int x);
	Example(const Example & e);
	Example & operator=(const Example & rhs);
	~Example();
	void add(int x);
};

void f(Example & a, Example  b);

