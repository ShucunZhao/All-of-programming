#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void printElements(T & container){
	typename T::iterator it = container.begin();
	while(it!=container.end()){
		cout<<*it<<endl;
		++it;
	}
}

class Page{
private:
	vector<string> content;
public:
	Page(){};
	/*
	Page(vector<string> & rhs):content(rhs.content);
	Page & operator=(vector<string> & rhs){
		vector()
	}*/
	~Page(){};
	void readPage(char * filename);
	void printPage();
};
