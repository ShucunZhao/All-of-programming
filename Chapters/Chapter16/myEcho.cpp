#include <iostream>
#include <cstdlib>

int main(int argc, char ** argv){
	if(argc > 1){
		for(int i=1;i<argc;i++ ){
			std::cout<<argv[i];
			std::cout<<" ";
		}
		std::cout<<std::endl;
	}
	else{
		//std::cout<<argv[0];
		std::cout<<std::endl;
	}
	return EXIT_SUCCESS;
}
