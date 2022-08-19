#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include "page.h"

using namespace std;

int main(int argc, char ** argv){
	if(argc!=2){
		cerr<<"The input command line arguments is invalid!"<<endl;
		return EXIT_FAILURE;
	}
	Page page;
	if(!page.readPage(argv[1])){
		cerr<<"The file "<<argv[1]<<" is invalid!\n";
		return EXIT_FAILURE;
	}
	page.printPage();
	return EXIT_SUCCESS;
}
