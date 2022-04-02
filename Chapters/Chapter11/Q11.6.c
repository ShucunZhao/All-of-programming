#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char ** argv){
	struct stat st;
	if(stat(argv[argc-1],&st)==0){
		if(!(S_IFDIR & st.st_mode)){
			printf("The last argument %s is not a directory.\n", argv[argc-1]);
			return EXIT_FAILURE;
		}
	}
	else{
		printf("Stat error.\n");
		return EXIT_FAILURE;
	}
	char * folder = argv[argc-1];
	char file[30];
	for(int i=1;i<argc-1;i++){
		if(stat(argv[i], &st)==0){
			if(!(S_IFREG & st.st_mode)){
				printf("The No.%d argument %s is not a file.\n", i, argv[i]);
				return EXIT_FAILURE;
			}
		}
		else{
			printf("Stat error.\n");
			return EXIT_FAILURE;
		}	
		sprintf(file,"%s/%s", folder,argv[i]);
		FILE * f1 = fopen(argv[i], "r");
		FILE * f2 = fopen(file, "w+");
		if(f1==NULL){
			printf("Couldn't track the file %s.\n", argv[1]);
			return EXIT_FAILURE;
		}
		int c;
		while((c=fgetc(f1))!=EOF){
			fprintf(f2, "%c", c);
		}
		if(fclose(f1)!=0){
			printf("file %s couldn't close.\n", argv[1]);
		}
		if(fclose(f2)!=0){
			printf("file %s couldn't close.\n", file);
		}
	}
	return EXIT_SUCCESS;
}
