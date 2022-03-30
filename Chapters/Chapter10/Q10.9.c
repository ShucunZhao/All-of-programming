#include <stdio.h>

enum color_t{
	RED,
	BLUE,
	GREEN,
	YELLOW,
	ORANGE,
	PURPLE,
};

int containsMatch(const int board[4][4]){
	for(int i=0;i<4;i++){
		for(int j=0;j<(4-2);j++){
			if(board[i][j]==board[i][j+1]&&board[i][j+1]==board[i][j+2]){
				return 1;
			}
		}
	}
	for(int j=0;j<4;j++){
		for(int i=0;i<(4-2);i++){
			if(board[i][j]==board[i+1][j]&&board[i+1][j]==board[i+2][j]){
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	enum color_t t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16;
	t1=RED;t2=GREEN;t3=GREEN;t4=GREEN;
	t5=RED;t6=PURPLE;t7=RED;t8=ORANGE;
	t9=BLUE;t10=BLUE;t11=GREEN;t12=ORANGE;
	t13=RED;t14=BLUE;t15=GREEN;t16=GREEN;
	const int board[4][4]={{t1,t2,t3,t4},
					 {t5,t6,t7,t8},
					 {t9,t10,t11,t12},
					 {t13,t14,t15,t16}};
	if(containsMatch(board)){
		printf("Matched.\n");
	}
	else{
		printf("Not match.\n");
	}
	return 0;
}
