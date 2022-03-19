#include <stdio.h>

struct point{
	int x;
	int y;
};

void print_pointset(struct point *s, size_t n){
	for(int i=0;i<n;i++){
		printf("point%d is: (%d,%d)\n", i, s->x, s->y);
		s++;
	}
}

int main(){
	struct point p_set[7] = {{10,5},{2,7},{-5,6},{-8,0},{-3,-5},{8,-2},{7,-6}};
	print_pointset(p_set, 7);
	return 0;
}
