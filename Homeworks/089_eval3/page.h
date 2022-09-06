#include <iostream>
#include <vector>

using namespace std;

class Choice{
public://The choices can set to public here.
	unsigned index;//Save the index in page
	unsigned jump;//Save the real jump number
	string option;
	Choice():index(0),jump(0),option(){};
	~Choice(){};
};

class Page{
private:
	unsigned pageNum;
	unsigned naviNum;
	unsigned choiceNum;
	pair<int, vector<string> > content;
	//first: 0-normal; 1-lose; 2-win
	//second: content of page
public:
	vector<Choice> choices;
	Page():pageNum(0),naviNum(0),choiceNum(0),content(0,0){};
	~Page(){};
	bool readPage(char * filename);
	void printPage()const;
	void printChoice()const;
	void setPageNum(unsigned num);
	int getFlag() const;
	unsigned getPageNum()const;
	bool isEndpage()const;
	bool operator < (const Page & rhs)const;
	void setNaviNum(unsigned num);
	unsigned getNaviNum()const;
	void setChoiceNum(unsigned num);
	unsigned getChoiceNum()const;
};
