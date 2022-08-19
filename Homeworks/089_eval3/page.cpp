#include "page.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;
/*
Page::Page(vector<string> & rhs){
	
}*/
/*
Page::Page(){
	content.first = 0;
	content.second(0)
}
*/
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

void Page::printPage(){
	vector<string>::iterator it = content.second.begin();
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

void Page::printChoice(){
	cout<<endl;//blank line
	vector<Choice>::iterator it = choices.begin();
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
