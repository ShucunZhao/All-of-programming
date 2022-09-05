#include "directory.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char ** argv){
	if(argc!=2){
		cerr<<"The command line arguments are invalid!"<<endl;
		return EXIT_FAILURE;
	}
	Direct D1;
	D1.readDirect(argv[1]);
	D1.checkRefer();
	set<Page> reachSet = D1.getReachable();
	D1.checkWin(reachSet);
	D1.writeNaviNum(reachSet);
	D1.printWinpath(reachSet);
	return EXIT_SUCCESS;
}
