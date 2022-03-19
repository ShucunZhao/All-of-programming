#include<stdio.h>
#include "head.h"
struct point *closestPoint(struct point *s, size_t n, struct point t){//s is always an address parameter represent the whole array which was defined in main().
	//printf("s_p:%p\n", &s[0]);
	if(n==0){
		return NULL;
	}
	double bestDist = computeDist(&s[0], t);//The parameter '&s[0]' in this step means getting the first element's address from the whole array address.
	struct point *bestChoice = &s[0];//bestChoice is the address of the first elemet of the array.
	for(int i=1;i<n;i++){
		double currDist = computeDist(&s[i],t);
		if(currDist < bestDist){
			bestChoice = &s[i];
			bestDist = currDist;
		}
	}
	return bestChoice;//return an address(or a pointer point to the element we need.)
}
