#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "provided.h"
#include "rand_story.h"

int main(int argc, char ** argv){
	int mode = 0;
	if(argc==4){
		if(strcmp(argv[1], "-n")==0){
			mode=1;
		}
		else{
			fprintf(stderr, "The selective argument %s is invalid!\n", argv[1]);
			return EXIT_FAILURE;
		}
		//readStory(argv[1]);
		catarray_t * cats = readWord(argv[2]);
		if(cats==NULL){
			fprintf(stderr, "The cats is invalid!\n");
			return EXIT_FAILURE;
		}
		replaceWord(argv[3], cats, mode);
	//	freeWordMem(cats);
	}
	else if(argc==3){
		//readStory(argv[1]);
		catarray_t * cats = readWord(argv[1]);
		if(cats==NULL){
			fprintf(stderr, "The cats is invalid!\n");
			return EXIT_FAILURE;
		}
		replaceWord(argv[2], cats, mode);
		freeWordMem(cats);
	}
	else{
		fprintf(stderr, "Input command line arguments are invalid!\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
