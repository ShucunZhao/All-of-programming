#include <math.h>
#include "head.h"

double computeDist(struct point *s, struct point t){
	double dist = sqrt(pow((s->x-t.x),2)+pow((s->y-t.y),2));
	return dist;
}
