#include <stdio.h>
#include <math.h>

double mySqrt(double d){
	double lo=0;
	double hi=d;
	double guess = d/2;
	while(fabs(guess*guess-d)>0.000001){
		if(guess*guess>d){
			double temp = (guess-lo)/2 + lo;
			hi =guess;
			guess=temp;
		}
		else{
			double temp = (hi-guess)/2 + guess;
			lo = guess;
			guess = temp;
		}
	}
	return guess;
}

//double mySqrt_tailRecur(double d){
//	double lo = 0;
//	double hi = d;
//	double guess = d/2;
//	return helper(lo, hi, guess, d);
//}

double helper(double lo, double hi, double guess, double d){//This is the prototype function, it should be defined before the function which will call it.
	if(fabs(guess*guess-d)<=0.000001){
		return guess;
	}
	if(guess*guess>d){
		double temp = (guess-lo)/2 + lo;
		hi = guess;
		guess = temp;
	}
	else{
		double temp = (hi-guess)/2 + guess;
		lo = guess;
		guess = temp;
	}
	return helper(lo, hi, guess, d);
}

double mySqrt_tailRecur(double d){
	double lo=0;
	double hi=d;
	double guess=d/2;
	return helper(lo,hi,guess,d);
}

int main(){
	double d;
	printf("Enter test case:\n");
	scanf("%lf", &d);
	//scanf("%lf\n", &d);If u use newline like this your programe would need to enter input twice.
	printf("The mySqrt result of %lf is %lf.\n", d, mySqrt(d));
	printf("The mySqrt_tailRecur result of %lf is %lf.\n", d, mySqrt_tailRecur(d));
	return 0;
}
