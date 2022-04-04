#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_SIZE 1024

int main(int argc, char ** argv){
	if(argc==1){
	//stdin
		char line[LINE_SIZE]={0};
		int sum=0;
		int n=0;
		int flag=0;
		//while(fgets(line, LINE_SIZE, stdin)!=NULL){
			//printf("The enter command line is: %s\n", line);
		//}
		fgets(line,LINE_SIZE,stdin);
		for(int i=0;i<LINE_SIZE;i++){
			if(line[i]==' '&&flag==0){
				continue;
			}
			else if(line[i]==' '&&flag==1){
				sum+=n;
				flag=0;
			}
			else if(isdigit(line[i])){
				if(flag){
					n=n*10+(line[i]-'0');
				}
				else{
					n=line[i]-'0';
				}
				flag=1;
			}
			else if(line[i]=='\n'){
				if(flag){
					sum+=n;
				}
			}
			else if(line[i]=='\0'){
				continue;
			}
			else{
				printf("The command argument %s has invalid number '%c' exist.\n", line, line[i]);
				exit(EXIT_FAILURE);
			}
		}
		printf("The result of sum is: %d\n", sum);
	}
	else if(argc==2){
	//file
		FILE * f = fopen(argv[1], "r");
		if(f==NULL){
			printf("Not %s file exist.\n", argv[1]);
			return EXIT_FAILURE;
		}
		char c;
		int sum = 0;
		int n=0;
		int flag=0;
		while((c=fgetc(f))!=EOF){
			//printf("The integer form of c is: %d\n", c);
			//printf("The char form of c is: %c\n", c);
			if(c==' '&&flag==0){
				continue;
			}
			else if(c==' '&&flag==1){
				sum+=n;
				flag=0;
			}
			else if(isdigit(c)){
				if(flag){
					n=n*10+(c-'0');
				}
				else{
					n=c-'0';
				}
				flag=1;
			}
			else if(c=='\n'){
				if(flag){
					sum+=n;
				}
			}
			else{
				printf("The file %s has invalid number '%c' exist.\n", argv[1], c);
				return EXIT_FAILURE;
			}
		}
		if(fclose(f)!=0){
			printf("file %s couldn't close.\n", argv[1]);
		}
		printf("The result of sum is: %d\n", sum);
	}
	else{
		printf("It only allow 0 or 1 command line arguments.\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
