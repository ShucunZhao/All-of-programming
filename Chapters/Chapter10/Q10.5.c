#include <stdio.h>
#include <ctype.h>

void printFENBoard(const char * fen){
	while(*fen!=' '&&*fen!='\0'){//We only use the first part of the FEN string os that when we meet space means we get the end of the first part.
		if(*fen=='/'){
			printf("\n");
		}
		else if(isdigit(*fen)){//isdigit() function is inside the ctype.h
			int n = *fen - '0';
			for(int i=0;i<n;i++){
				printf(" ");
			}
		}
		else{
			printf("%c", *fen);
		}
		fen++;
	}
	printf("\n");
}
