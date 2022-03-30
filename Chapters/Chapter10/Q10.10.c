#include <stdio.h>

//double approximate(double val){}

double derivative(double (*f)(double), double x){
	const int h = 0.000000000001;
	double y1 = f(x);
	double y2 = f(x+h);
	return (y1-y2)/h;
}
