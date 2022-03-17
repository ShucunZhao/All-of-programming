#include <stdio.h>
#include "head.h"

//point *test(point *s){
//void test(struct point *s){
//	for(int i=0;i<7;i++){
		//printf("x:%d,y:%d\n", s[i].x, s[i].y:);
//		s[i].x = i;
//		s[i].y = i;
//	}
//	return &s[6];
//}

int main(){
	 struct point p_set[7] = {{10,5},{2,7},{-5,6},{-8,0},{-3,-5},{8,-2},{7,-6}};
	 struct point *p = NULL;
	 p = &p_set[0];
	 struct point t = {1,-1};
	 //point *p = NULL;
	 //p = &p_set[0];
	 //struct point *q = test(p); 
	// test(p);
	//for(int i=0;i<7;i++){
//	printf("x:%d,y:%d\n", q->x, q->y);
	// }
	 struct point *ans = closestPoint(p, 7, t);
	 printf("The closest point is: (%d,%d)\n", ans->x, ans->y);
	 return 0;
}
