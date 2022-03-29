#include <stdio.h>
#include <ctype.h>

typedef struct Pieces{
	int pawns;
	int rooks;
	int bishops;
	int queens;
	int knights;
	int kings;
}pieces;

void countPieces(const char * fen, pieces * white, pieces * black){
	int p=0, r=0, b=0, q=0, n=0, k=0;
	int P=0, R=0, B=0, Q=0, N=0, K=0;
	while(*fen!=' '&&*fen!='\0'){
		if(isdigit(*fen)||*fen=='/'){
			fen++;
		}
		if(*fen=='p'){
			p++;
		}
		if(*fen=='r'){
			r++;
		}
		if(*fen=='b'){
			b++;
		}
		if(*fen=='q'){
			q++;
		}
		if(*fen=='n'){
			n++;
		}
		if(*fen=='k'){
			k++;
		}
		if(*fen=='P'){
			P++;
		}
		if(*fen=='R'){
			R++;
		}
		if(*fen=='B'){
			B++;
		}
		if(*fen=='Q'){
			Q++;
		}
		if(*fen=='N'){
			N++;
		}
		if(*fen=='K'){
			K++;
		}
		fen++;
	}
	black->pawns = p;
	black->rooks = r;
	black->bishops = b;
	black->queens = q;
	black->knights = n;
	black->kings = k;
	white->pawns = P;
	white->rooks = R;
	white->bishops = B;
	white->queens = Q;
	white->knights = N;
	white->kings = K;
}

int main(){
	const char FEN[]="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
	pieces  white;
	pieces  black;
	countPieces(FEN, &white, &black);
	return 0;
}
