#include <stdio.h>
#include <string.h>

#define LINE_SIZE 512

int main(int argc, char ** argv){
	const char * str = "-n";
	int flag = 0;
	int n=0;
	if(argc>1){
		for(int i=1;i<argc;i++){
			if(strcmp(argv[i],str)==0){
				flag = 1;
				continue;
			}
			FILE * f = fopen(argv[i], "r");
			if(f==NULL){
				printf("Not %s file name exit.\n", argv[i]);
				continue;
			}
			int c;
			while((c=fgetc(f))!=EOF){
				if(c=='\n'){
					n++;
				}
				printf("%c",c);
			}
			if(flag){
				printf("The number of output line is: %d\n", n);
			}
			n=0;
			fclose(f);
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
