#include <vector>
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
};
