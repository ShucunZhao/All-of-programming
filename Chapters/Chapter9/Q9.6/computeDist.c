#include <math.h>
#include "head.h"

double computeDist(struct point *s, struct point t){//s is an pointer store address so we need to use s-> to get the fields of the struct which s pointing to, it represent (*s).x here.
	double dist = sqrt(pow((s->x-t.x),2)+pow((s->y-t.y),2));
	return dist;
}
