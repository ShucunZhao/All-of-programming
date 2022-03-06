#include<stdio.h>
#include<stdlib.h>

struct _retire_info{
	int months;
	double contribution;
	double rate_of_return;
};

typedef struct _retire_info retire_info;

void retirement(int startAge, double initial, retire_info working, retire_info retired){
//retirement(in months, initial savings in dollars, info about working, info about being retired)
	int Age;
	int moonth;
	for(int i=1; i<=working.months; i++){
		Age = startAge/12;
		moonth = startAge%12;
		printf("While working: Age %3d moonth %2d you have $%.2lf\n", Age, moonth, initial);
		initial += (initial*working.rate_of_return + working.contribution);
		//printf("working.rate_of_return:%lf\n", working.rate_of_return);
		//printf("working.contribution:%lf\n",working.contribution);
		//printf("initial:%.2lf\n", initial);
		startAge++;
	}
	//double balance = initial;
	for(int j=1; j<=retired.months; j++){
		Age = startAge/12;
		moonth = startAge%12;
		printf("After retiring: Age %3d moonth %2d you have $%.2lf\n",Age, moonth, initial);
		initial += (initial*retired.rate_of_return + retired.contribution);
		startAge++;
	}
}

int main(){
	retire_info Working = {489, 1000, 0.045/12};
	retire_info Retired = {384, -4000, 0.01/12};
	int startAge = 327;
	int initial = 21345;
	retirement(startAge, initial, Working, Retired);
	return 0;
}
