#include <stdio.h>

struct point2d_tag{
	double x;
	double y;
};
typedef struct point2d_tag point2d;

double f_xy(double x, double y){
	return x*x+4*y*y;
} 

vect2d gradient(double (*f)(double, double), double x, double y){
	const h = 0.00000000001;
	vect2d.dx=f(x+h,y)/h;
	vect2d.dy=f(x,y+h)/h;
}

gradientAscent(double (*f)(double, double), point2d startPoint, double gamma, double convergedDistance){
	double x_cur = startPoint.x;
	double y_cur = startPoint.y;
	double x_nex = x_cur + gamma*gradient(x_cur,y_cur);
	double x_nex = x_cur + gamma*gradient(x_cur,y_cur);
	while(sqrt(pow(x_nex-x_cur,2)+pow(y_nex-y_cur,2)!=convergedDistance)){
		double x_nex = x_cur + gamma*gradient(x_cur,y_cur);
		double x_nex = x_cur + gamma*gradient(x_cur,y_cur);
	}
	return x_cur,y_cur;
}
