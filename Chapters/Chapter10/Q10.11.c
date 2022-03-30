#include <stdio.h>

double f_x(double t){
	return t*(8-t);
}

double integrate(double a, double b, double (*f)(double)){
	const double dx = 0.000000000001;
	//const double dx = 0.000000001;
	double sum = 0;
	for(double i=a;i<=b;i+=dx){
		sum=sum+f(i)*dx;
	}
	return sum;
}

//int main(){
//	printf("The result is:%lf\n", integrate(0.0,8.0,f_x));
//	return 0;
//}
