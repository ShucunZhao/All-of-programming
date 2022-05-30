#include <stdio.h>
#include <stdlib.h>
#include "rand_story.h"

int main(int argc, char ** argv){
	if(argc!=2){
		fprintf(stderr, "Input command line arguments are invalid!\n");
		return EXIT_FAILURE;
	}
	readStory(argv[1]);
}
