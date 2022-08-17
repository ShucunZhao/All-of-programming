#include "page.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;
/*
Page::Page(vector<string> & rhs){
	
}*/

void Page::readPage(char * filename){
	bool check = 0;
	bool lose = 0;
	bool win = 0;
	bool find = 1;
	string loseFlag("LOSE");
	string winFlag("WIN");
	//string blank("\n");
	ifstream f(filename);
	if(!f){
		cerr<<"The file "<<filename<<" is invalid!\n";
		exit(EXIT_FAILURE);
	}
	string str;
	vector<string> text;
	string temp;
	int i = 1;
	while(getline(f,str)){
		if(find){
			if(str==loseFlag){
				lose=1;
			}
			if(str==winFlag){
				win=1;
			}
			find = 0;
		}
		if(str[0]!='#'&&!check){
			if(!lose&&!win){
				stringstream ss;
				ss<<i;
				string index = " "+ss.str()+". ";
				//cout<<str.substr(str.find(":"));
				index.insert(index.size(), str.substr(str.find(":")+1));
				text.push_back(index);
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
			content.push_back(str);
		}
	}
	content.push_back(" ");
	if(lose){
		content.push_back("Sorry, you have lost. Better luck next time!");
	}
	else if(win){
		content.push_back("Congratulations! You have won. Hooray!");
	}
	else{
		content.push_back("What would you like to do?\n");
		content.insert(content.end(), text.begin(), text.end());
	}
	f.close();
}

void Page::printPage(){
	vector<string>::iterator it = content.begin();
	while(it!=content.end()){
		cout<<*it<<endl;
		++it;
	}
}
