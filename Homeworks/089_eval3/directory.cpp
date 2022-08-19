#include "directory.h"
#include <sstream>

void Direct::readDirect(char * pathname){
	unsigned num = 1;
	while(1){
		Page page;
		string filename(pathname);
		stringstream ss;
		ss<<num;
		string suffix(ss.str());
		suffix+=".txt";
		filename+="/page";
		filename+=suffix;
		const char * input = filename.c_str();
		if(!page.readPage((char*)input)){
			break;	
		}
		page.setPageNum(num);//Set the page number
		pages.push_back(page);
		//page.printPage();
		num++;
	}
}


void Direct::printDirect(){
	for(size_t i=0;i<pages.size();i++){
		pages[i].printPage();
	}
}

void Direct::checkEnter(){
	size_t i = 0;
	while(i<pages.size()){
		bool find = 0;
		pages[i].printPage();
		if(pages[i].getFlag()!=0){
			exit(EXIT_SUCCESS);
		}
		else{	
			string input;
			while(getline(cin, input)){
				stringstream ss(input);
				unsigned x;
				if(!(ss>>x)){
					cerr<<"The input number is invalid, try again!"<<endl;
					continue;
				}
				for(size_t j=0;j<pages[i].choices.size();j++){
					if(pages[i].choices[j].index==x){
						i = pages[i].choices[j].jump;
						find = 1;
						break;
					}
				}
				if(find){
					break;
				}
				cout<<"The number is out of bound, try again!"<<endl;
			}
		}
	}
}

