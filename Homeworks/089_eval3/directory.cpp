#include "directory.h"
#include <set>
#include <sstream>

/*
 * @param pathname: The second command line argument which is the path of input files.
 * return void.
 * This func is used for reading all input files page information into a pages vector.
 */
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

/*
 * return void.
 * This func is used for printing all page information with the require of step1.
 */
void Direct::printDirect(){
	for(size_t i=0;i<pages.size();i++){
		pages[i].printPage();
	}
}

/*
 * return void.
 * This func is used for checking the input with the request of step2.
 */
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
						i = pages[i].choices[j].jump - 1;
						find = 1;
						break;
					}
				}
				if(find){
					break;
				}
				cerr<<"The number is out of bound, try again!"<<endl;
			}
		}
	}
}

/*
 * return void.
 * This func is used for checking if the the references of each pages is valid.
 * And use a validPageSet to check if the number of the all reference pages is corresponding to the number of pages.
 */
void Direct::checkRefer(){
	bool win=0;
	bool lose=0;
	unsigned pageSize = getPagesize();
	set<unsigned> validPageSet;
	validPageSet.insert(pages[0].getPageNum());//Add the first original page into the valid page set.
	for(size_t i=0;i<pageSize;i++){
		int flag = pages[i].getFlag();
		if(flag==2){
			win = 1;
		}
		if(flag==1){
			lose = 1;
		}
		for(size_t j=0;j<pages[i].choices.size();j++){
			unsigned referNum = pages[i].choices[j].jump;
			if(referNum==0||referNum>pageSize){
				cerr<<"The reference number "<<pages[i].choices[j].jump<<"is invalid!\n"<<endl;
				exit(EXIT_FAILURE);
			}
			validPageSet.insert(referNum);
		}
	}	
	if(!win&&!lose){
		cerr<<"Pages have no end page!"<<endl;
		exit(EXIT_SUCCESS);
	}
	if(validPageSet.size()!=pageSize){
		cerr<<"The number of pages is not corresponding to the reference number!"<<endl;
		exit(EXIT_SUCCESS);
	}
}

/*
 * return private member pageNum.
 */
int Direct::getPagesize() const {
	return pages.size();
}

/*
 * return a set to sore the reachable pages.
 * This func is used for checking the input with the request of step2.
 */
set<Page> Direct::getReachable(){
	set<Page> reachPages;
	set<Page> tempSet;
	reachPages.insert(pages[0]);
	//set<Page>::const_iterator itPage = reachPages.begin();
	while(tempSet.size()!=reachPages.size()){
		tempSet = reachPages;
		set<Page>::const_iterator itTemp = tempSet.begin();
		while(itTemp!=tempSet.end()){
			if((*itTemp).isEndpage()==0){
				vector<Choice>::const_iterator itChoice = (*itTemp).choices.begin();
				while(itChoice!=(*itTemp).choices.end()){
					reachPages.insert(pages[(*itChoice).jump - 1]);
					++itChoice;
				}
			}
			++itTemp;
		}
	}
	return reachPages;
} 

/*
 * @param intput: A set that stores reachable pages.
 * return void.
 * This func is used for printing all reachable pages.
 */
void Direct::printSet(set<Page> & input)const{
	set<Page>::const_iterator it = input.begin();
	int i =1;
	while(it!=input.end()){
		cout<<"The "<<i<<" reachable page is:"<<endl;
		(*it).printPage();
		++it;
		i++;
	}
}

/*
 * @param intput: A set that stores reachable pages.
 * return void.
 * This func is used for finding the unreachable pages.
 */
void Direct::unReachable(set<Page> & input)const{
	unsigned pageNum;
	int find = 0;
	for(size_t i=0;i<pages.size();i++){
		set<Page>::const_iterator it = input.begin();
		pageNum = pages[i].getPageNum();
		while(it!=input.end()){
			if(pageNum==(*it).getPageNum()){
				find = 1;
				break;
			}
			++it;
		}
		if(!find){
			cout<<"The page "<<pageNum<<" is unreachable!"<<endl;
		}
		find = 0;
	}		
}

void Direct::checkWin(set<Page> & input)const{
	set<Page>::const_iterator it = input.begin();
	bool findWin = 0;
	while(it!=input.end()){
		if((*it).getFlag()==2){
			findWin = 1;
		}
		++it;
	}
	if(!findWin){
		cerr<<"There is no way to win"<<endl;
		exit(EXIT_FAILURE);		
	}
}

void Direct::writeNaviNum(set<Page> & input){
	set<Page>::const_iterator setIt = input.begin();
	unsigned pageNum;
	unsigned jumpNum;
	unsigned choiceNum;
	while(setIt!=input.end()){
		pageNum = (*setIt).getPageNum();
		//vector<Choice>::const_iterator chIt = pages[pageNum-1].choices.begin();
		vector<Choice>::const_iterator chIt = pages[pageNum-1].choices.begin();
		while(chIt!=pages[pageNum-1].choices.end()){
			jumpNum = (*chIt).jump;
			choiceNum = (*chIt).index;
			pages[jumpNum-1].setNaviNum(pageNum);
			pages[jumpNum-1].setChoiceNum(choiceNum);
			++chIt;
		}
		++setIt;
	}
}

void Direct::printWinpath(set<Page> & input)const{
	vector<Page>::const_iterator pageIt = pages.begin();
	unsigned pageNum;
	unsigned naviNum;
	unsigned choiceNum;
	unsigned winNum;
	int flag;
	while(pageIt!=pages.end()){
		pageNum = (*pageIt).getPageNum();
		set<Page>::const_iterator setIt = input.begin();
		while(setIt!=input.end()){
			if(pageNum==(*setIt).getPageNum()){
				flag = (*pageIt).getFlag();
				if(flag==2){
					winNum = pageNum;
					naviNum = (*pageIt).getNaviNum();
					choiceNum = (*pageIt).getChoiceNum();
					//cout<<"Page "<<pageNum<<" WIN"<<endl;
					while(pageNum!=1){
						cout<<"Page "<<naviNum<<" Choice "<<choiceNum<<endl;
						pageNum = naviNum;
						naviNum = pages[pageNum-1].getNaviNum();
						choiceNum = pages[pageNum-1].getChoiceNum();
					}
					cout<<"Page "<<winNum<<" WIN"<<endl;
					return;
				}
				
			}
			++setIt;
		}
		++pageIt;
	}
}
