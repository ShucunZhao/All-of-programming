#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define row 10
#define col 10
#define LINE_SIZE 12//This minimun size must larger than 11(Because in the end of each 
					//line of input file it should keep an bit for the terminate '\0', so plus the '\n' it totally has 12 bits). 

void printRotate(FILE * f){
	char matrix[row][col];
	char tmp[col][row];
	int dst=row-1;
	char line[LINE_SIZE];
	int i = 0;
	while(fgets(line, LINE_SIZE, f)!=NULL){
		if(i>9){
			fprintf(stderr, "The line input file is out of 10 lines!\n");
			exit(EXIT_FAILURE);
		}
		char * newLine = strchr(line,'\n');
		if(newLine==NULL){
			fprintf(stderr, "The line %d of input file is invalid!\n", i);
			exit(EXIT_FAILURE);
		}
		char * head = line;
		if((newLine-head)!=10){
			fprintf(stderr, "The line %d of input file is invalid!\n", i);
			exit(EXIT_FAILURE);	
		}
		for(int j=0;j<col;j++){
			//printf("The %d line of line[%d]:%c\n",i,j,line[j]);
			matrix[i][j]=line[j];
		}
		i++;
	}
	printf("The origin input matrix is:\n");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}
	for(int k=0;k<row;k++){
		for(int l=0;l<col;l++){
			tmp[l][dst]=matrix[k][l];
		}
		dst-=1;
	}
	printf("The convet result is:\n");
	for(int m=0;m<col;m++){
		for(int n=0;n<row;n++){
			printf("%c", tmp[m][n]);
		}
		printf("\n");
	}
}

int main(int argc, char ** argv){
	if(argc!=2){
		fprintf(stderr, "You should take one command line argument!\n");
		return EXIT_FAILURE;
	}
	FILE * f = fopen(argv[1], "r");
	if(f==NULL){
		fprintf(stderr, "Failed to open file:%s!\n", argv[1]);
		return EXIT_FAILURE;
	}
	printRotate(f);

	return EXIT_SUCCESS;
}
