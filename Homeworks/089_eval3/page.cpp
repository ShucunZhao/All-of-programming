#include "page.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

bool Page::readPage(char * filename){
	bool check = 0;
	//bool lose = 0;
	//bool win = 0;
	bool begin = 1;
	//cout<<filename<<endl;
	string loseFlag("LOSE");
	string winFlag("WIN");
	//string blank("\n");
	ifstream f(filename);
	if(!f){
		return 0;
		//exit(EXIT_FAILURE);
	}
	string str;
	//vector<string> text;
	//string temp;
	int i = 1;
	while(getline(f,str)){
		if(begin){
			if(str==loseFlag){
				content.first = 1;
			}
			if(str==winFlag){
				content.first = 2;
			}
			begin = 0;
		}
		if(str[0]!='#'&&!check){
			if(content.first==0){
				stringstream ss;
				ss<<i;
				string opt = " "+ss.str()+". ";
				//cout<<str.substr(str.find(":"));
				opt.insert(opt.size(), str.substr(str.find(":")+1));
				ss.str("");
				Choice c;
				//string jump = str.substr(0,str.find(":"));
				c.jump = stoi(str.substr(0,str.find(":")));
				/*
				cout<<"----------"<<endl;
				cout<<text.second.first<<endl;
				cout<<"----------"<<endl;
				*/
				c.option=opt;
				c.index = i;
				choices.push_back(c);
				i++;
			}
		}
		else{
			if(!check){
				check = 1;
				continue;
			}
		}
		if(check){
			content.second.push_back(str);
		}
	}
	f.close();
	return 1;
}

void Page::printPage()const{
	vector<string>::const_iterator it = content.second.begin();
	while(it!=content.second.end()){
		cout<<*it<<endl;
		++it;
	}
	cout<<endl;//blank line
	if(content.first==1){
		cout<<"Sorry, you have lost. Better luck next time!"<<endl;
	}
	else if(content.first==2){
		cout<<"Congratulations! You have won. Hooray!"<<endl;
	}
	else{
		cout<<"What would you like to do ?"<<endl;
		printChoice();
	}
}

void Page::printChoice()const{
	cout<<endl;//blank line
	vector<Choice>::const_iterator it = choices.begin();
	while(it!=choices.end()){
		cout<<it->option<<endl;
		++it;
	}
}

/*
void Choice::getIndex() const{
	return index;
}

void Choice::getJump() const{
	return jump;
}
*/

void Page::setPageNum(unsigned num){
	pageNum = num;
}

int Page::getFlag() const{
	int flag = content.first;
	return flag;
}

unsigned Page::getPageNum()const{
	return pageNum;
}

bool Page::isEndpage() const{
	if(content.first==0){
		return 0;
	}
	else{
		return 1;
	}
}

bool Page::operator<(const Page & rhs)const{
	return this->pageNum<rhs.pageNum;//Key point for sorting in Set when inserting new element in it.
}

void Page::setNaviNum(unsigned num){
	naviNum = num;
}

unsigned Page::getNaviNum()const{
	return naviNum;
}

void Page::setChoiceNum(unsigned num){
	choiceNum = num;
}

unsigned Page::getChoiceNum()const{
	return choiceNum;
}
