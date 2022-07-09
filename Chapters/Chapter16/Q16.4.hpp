#include <iostream>
class Myatoi{
private:
	const std::string & str;
	int result=0;
	
public:
	/*
	const std::string & str;
	int x;
	*/
	Myatoi();
	Myatoi(const std::string & s);
	int myatoi();
	int atoiFromsstream();	
};
