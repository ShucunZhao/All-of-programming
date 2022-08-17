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
	Page page1;
	page1.readPage(argv[1]);
	page1.printPage();
	return EXIT_SUCCESS;
}
