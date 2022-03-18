#include <stdio.h>

int main(){
	typedef struct _xx {
		int x;
		int y;
	}xx;
	struct xx;
	xx={.x=3,.y=4};
	printf("%d", xx.x);
	return 0;
}
