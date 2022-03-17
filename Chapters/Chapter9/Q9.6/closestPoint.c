#include<stdio.h>
#include "head.h"
struct point *closestPoint(struct point *s, size_t n, struct point t){
	if(n==0){
		return NULL;
	}
	double bestDist = computeDist(&s[0], t);
	struct point *bestChoice = &s[0];
	for(int i=1;i<n;i++){
		double currDist = computeDist(&s[i],t);
		if(currDist < bestDist){
			bestChoice = &s[i];
			bestDist = currDist;
		}
	}
	return bestChoice;
}
