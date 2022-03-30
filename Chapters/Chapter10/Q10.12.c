#include <stdio.h>

struct vect2d_tag{
	double dx;
	double dy;
};
typedef struct vect2d_tag vect2d;

double f_xy(double x, double y){
	return x*x+4*y*y;
} 

vect2d gradient(double (*f)(double, double), double x, double y){
	const h = 0.00000000001;
	vect2d.dx=f(x+h,y)/h;
	vect2d.dy=f(x,y+h)/h;
}
