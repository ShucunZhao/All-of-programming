#include <stdio.h>
#include <ctype.h>

void fenToBoard(const char * fen, char board[8][8]){
	int n=0;
	int flag=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
index:
			if(*fen==' '||*fen=='\0'){
				printf("Wrong FEN format.");
				break;
			}
			while(*fen=='/'){
				fen++;
			}
			if(isdigit(*fen)!=0&&flag==0){
				n = *fen-'0';
				flag=1;
			}
			if(n!=0){
				board[i][j]=' ';
				n--;
				continue;
			} 
			else if(n==0&&flag==1){
				fen++;
				flag=0;
				goto index;
			}
			else{
				board[i][j]=*fen;
				fen++;
			}
		} 
	}
}

int main(){
	const char FEN[]="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
	char board[8][8];
	fenToBoard(FEN, board);
	return 0;
}
