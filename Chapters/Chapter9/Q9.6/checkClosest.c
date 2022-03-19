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
	 struct point p_set[7] = {{10,5},{2,7},{-5,6},{-8,0},{-3,-5},{8,-2},{7,-6}};//Define an struct array and the name of this array is the first address of it.
	 struct point *p = NULL;//Method1: Define a NULL pointer and point it to the first element of the struct array.(The first element address represent the whole array)
	 p = &p_set[0];//Let p point to first element.
	 printf("Address of p_set[0]: %p\n", p);
	 struct point *p2 = p_set;//Method2: let p2 point to the name 'p_set' which represent the first address of whole array directly.
	 printf("Address of p_set: %p\n", p2);
	 struct point t = {1,-1};
	 //point *p = NULL;
	 //p = &p_set[0];
	 //struct point *q = test(p); 
	// test(p);
	//for(int i=0;i<7;i++){
//	printf("x:%d,y:%d\n", q->x, q->y);
	// }
	 struct point *ans = closestPoint(p, 7, t);//ans is a pointer so closestPoint function would return an address.
	 printf("Ans: The closest point is: (%d,%d)\n", ans->x, ans->y);
	 struct point *ans2 = closestPoint(p2, 7, t);
	 printf("Ans2: The closet point is (%d,%d)\n", ans2->x, ans2->y);
	 return 0;
}
