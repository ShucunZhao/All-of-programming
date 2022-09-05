#include <vector>
#include <set>
#include "page.h"

class Direct{
private:
	vector<Page> pages;
public:
	Direct():pages(){};
	~Direct(){};
	void readDirect(char * pathname);
	void printDirect();
	void checkEnter();
	void checkRefer();//Refer means jump to a specific page.
	int getPagesize() const;
	set<Page> getReachable();
	void printSet(set<Page> & input)const;
	void unReachable(set<Page> & input)const;
	void checkWin(set<Page> & input)const;
	void writeNaviNum(set<Page> & input);
	void printWinpath(set<Page> & input)const;
};
