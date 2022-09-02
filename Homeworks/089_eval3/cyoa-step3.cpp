#include <cstdlib>
#include <iostream>
#include "directory.h"

using namespace std;

int main(int argc, char ** argv){
	if(argc!=2){
		cerr<<"The input argument is invalid!\n"<<endl;
		return EXIT_FAILURE;
	}
	Direct D1;
	D1.readDirect(argv[1]);
	D1.checkRefer();
	set<Page> reachSet = D1.getReachable();
	//const set<Page> & xx = reachSet;
	//D1.printSet(reachSet);
	D1.unReachable(reachSet);
	return EXIT_SUCCESS;
}
