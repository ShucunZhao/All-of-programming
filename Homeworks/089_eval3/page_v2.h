#include <iostream>
#include <vector>

using namespace std;

/*
template<typename T>
void printElements(T & container){
	typename T::iterator it = container.begin();
	while(it!=container.end()){
		cout<<*it<<endl;
		++it;
	}
}
*/

class Choice{
/*
private:
	unsigned index;
	unsigned jump;
	vector<string> option;
	*/
public:
	unsigned index;
	unsigned jump;
	string option;
	Choice():index(0),jump(0),option(){};
	//void printChoice();
	//void getIndex() const;
	//void getJump() const;
	~Choice(){};
};

class Page{
private:
	unsigned pageNum;
	//Choice choices;
	pair<int, vector<string> > content;
	//first: 0-normal; 1-lose; 2-win
	//second: content of page
public:
	vector<Choice> choices;
	Page():pageNum(0),content(0,0){};
	/*
	Page(vector<string> & rhs):content(rhs.content);
	Page & operator=(vector<string> & rhs){
		vector()
	}*/
	~Page(){};
	bool readPage(char * filename);
	void printPage();
	void printChoice();
	void setPageNum(unsigned num);
	int getFlag() const;
};
