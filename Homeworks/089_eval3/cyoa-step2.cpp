#include "directory.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char ** argv){
	if(argc!=2){
		cerr<<"Input arguments invalid!\n"<<endl;
		return EXIT_FAILURE;
	}
	//cout<<argv[1];
	
	Direct directory;
	directory.readDirect(argv[1]);
	//directory.printDirect();
	directory.checkEnter();	
	return EXIT_SUCCESS;
}
