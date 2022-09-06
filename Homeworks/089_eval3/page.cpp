#include "page.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

/*
 * @param filename: the input argument that represent the file name.
 * return bool: 1 when successful, 2 when fail.
 * This func is used for reading each input file into a Page format.
 */
bool Page::readPage(char * filename){
	bool check = 0;
	bool begin = 1;//Check to read the beginning of file.
	string loseFlag("LOSE");
	string winFlag("WIN");
	ifstream f(filename);//Open file.
	if(!f){//if file cannot open return false.
		return 0;
	}
	string str;//Store all content in whole page.
	int i = 1;//The choices index.
	while(getline(f,str)){//Read all content.
		if(begin){//When read the begin, check
				//if there win or lose exits.
			if(str==loseFlag){
				content.first = 1;
			}
			if(str==winFlag){
				content.first = 2;
			}
			begin = 0;
		}
		//If isn't win or lose page at beginning, parsing the choices.
		if(str[0]!='#'&&!check){
			if(content.first==0){
				//Generate the options of chices with index 'i'.
				stringstream ss;
				ss<<i;
				string opt = " "+ss.str()+". ";
				opt.insert(opt.size(), str.substr(str.find(":")+1));
				ss.str("");
				//Write the option into the Choice vecotr.
				Choice c;
				c.jump = stoi(str.substr(0,str.find(":")));
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
			content.second.push_back(str);//Write the parsed content into vector. 
		}
	}
	f.close();
	return 1;
}

/*
 * return void
 * This func is print the Page following the selection content.
 */
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

/*
 * return void
 * This func is print the options of Choice.
 */
void Page::printChoice()const{
	cout<<endl;//blank line
	vector<Choice>::const_iterator it = choices.begin();
	while(it!=choices.end()){
		cout<<it->option<<endl;
		++it;
	}
}

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
	return this->pageNum<rhs.pageNum;//Key point for sorting in Set when inserting new element in it.(Because the STL set didn't overload the custom variable like the class we declared, so u need overload the "<" by yourself.)
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
