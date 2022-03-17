#include <stdio.h>
struct point{
	int x;
	int y;
};

double computeDist(struct point*s, struct point t);

struct point*closestPoint(struct point*s, size_t n, struct point t);
