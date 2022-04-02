#include <stdio.h>

#define LINE_SIZE 512

int main(int argc, char ** argv){
	if(argc>1){
		for(int i=1;i<argc;i++){
			FILE * f = fopen(argv[i], "r");
			if(f==NULL){
				printf("Not %s file name exit.\n", argv[i]);
				continue;
			}
			else{
				int c;
				while((c=fgetc(f))!=EOF){
					printf("%c",c);
				}
			}
			if(fclose(f)!=0){
				printf("file %s couldn't close.\n", argv[i]);
			}
		}
	}
	else{
		char line[LINE_SIZE];
		while(fgets(line,LINE_SIZE,stdin)!=NULL){
			printf("%s", line);
			//if(fputs(line,stdout)<0){
			//	perror("fputs failed\n");
			//}
			//fputs(line,stdout);
		}
	}
	return 0;
}
