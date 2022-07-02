#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <random>
#include "circle2.hpp"
#define pi 3.141592654

using namespace std;

int main(void){
	/*
	//Verify the monte carlo by estimating value of pi:
	int circleP1 = 0;
	int circleP2 = 0;
	int squareP1 = 0;
	int squareP2 = 0;
	int num = 500000000;
	double ranX1,ranY1,dist1,Pi1,ranX2,ranY2,dist2,Pi2;
	default_random_engine e(time(0));
	uniform_real_distribution<double> u1x(0, 1);//The accuracy of this random method is better. 
	//uniform_real_distribution<double> u1y(y1min, y1max);
	for(int i=0;i<num;i++){
		//ranX1 = fmod(rand(),(num+1))/num;//The accuracy of this random method is worse. 
		//ranY1 = fmod(rand(),(num+1))/num;
		ranX2 = u1x(e);
		ranY2 = u1x(e);
		dist1 = pow(ranX1,2)+pow(ranY1,2);
		dist2 = pow(ranX2,2)+pow(ranY2,2);
		if(dist1 <=1 ){
			circleP1++;
		}
		if(dist2 <=1 ){
			circleP2++;
		}
		squareP1++;
		squareP2++;
		Pi1 = double(4*circleP1)/squareP1;
		Pi2 = double(4*circleP2)/squareP2;
	//	printf("The pi is:%f\n", Pi);
	}
	printf("The pi1 is:%f\n", Pi1);
	printf("The pi2 is:%f\n", Pi2);
	*/
	/*
	//Verify the monte carlo by estimating the intersection of two squares:
	Point * p1  = new Point;
	Point * p2  = new Point;
	p1->move(0, 0);
	p2->move(2, 2);
	const double r1 = 2;
	const double r2 = 2;
	Circle * c1 = new Circle(*p1, r1);
	Circle * c2 = new Circle(*p2, r2);
	
	//double counter1=0;
	//double counter2=0;
	double counter3=0;
	int n = 5000000;
	double x1min = c1->center.x-c1->radius;
	double x1max = c1->center.x+c1->radius;
	double y1min = c1->center.y-c1->radius;
	double y1max = c1->center.y+c1->radius;
	double x2min = c2->center.x-c2->radius;
	double x2max = c2->center.x+c2->radius;
	double y2min = c2->center.y-c2->radius;
	double y2max = c2->center.y+c2->radius;
	//Point * p = new Point;
	//default_random_engine e;
	default_random_engine e(time(0));
	uniform_real_distribution<double> u1x(x1min, x1max);
	uniform_real_distribution<double> u1y(y1min, y1max);
	//uniform_real_distribution<double> u2x(x2min, x2max);
	//uniform_real_distribution<double> u2y(y2min, y2max);
	
	for(int i=0;i<n;i++){
		Point * ran1 = new Point;
		//Point * ran2 = new Point;
		ran1->x = u1x(e);
		ran1->y = u1y(e);
		if(ran1->x>=x1min&&ran1->x<=x1max&&ran1->y>=y1min&&ran1->y<=y1max&&ran1->x>=x2min&&ran1->x<=x2max&&ran1->y>=y2min&&ran1->y<=y2max){
			counter3++;
		}	
		//printf("dist:%f\n", p->distanceFrom(*ans));
		delete ran1;
		//delete ran2;
	}
	double ratio = counter3/n;
	double S1 = pow(2*c1->radius,2);
	//double S2 = 4*4;
	double inteS = ratio*S1;
	printf("The rand intersection area:%f\n", inteS);
	*/
	/*
	//Verify the monte carlo by estimating the intersection of two circles:
	Point * p1  = new Point;
	Point * p2  = new Point;
	p1->move(0, 0);
	p2->move(1, 1);
	const double r1 = 1;
	const double r2 = 1;
	Circle * c1 = new Circle(*p1, r1);
	Circle * c2 = new Circle(*p2, r2);
	
	//double counter1=0;
	double counter2=0;
	double counter3=0;
	int n = 5000000;
	//int n = 5000000;
	double x1min = c1->center.x-c1->radius;
	double x1max = c1->center.x+c1->radius;
	double y1min = c1->center.y-c1->radius;
	double y1max = c1->center.y+c1->radius;

	//Point * p = new Point;
	//default_random_engine e;
	default_random_engine e(time(0));
	uniform_real_distribution<double> u1x(x1min, x1max);
	uniform_real_distribution<double> u1y(y1min, y1max);
	//uniform_real_distribution<double> u2x(x2min, x2max);
	//uniform_real_distribution<double> u2y(y2min, y2max);

	while(counter2<n){
		Point * ran1 = new Point;
		ran1->x = u1x(e);
		ran1->y = u1y(e);
		if(p1->distanceFrom(*ran1)>r1){
			delete ran1;
			continue;
		}
		counter2++;
		if(p1->distanceFrom(*ran1)<=r1&&p2->distanceFrom(*ran1)<=r2){
			counter3++;
		}
		//printf("dist:%f\n", p->distanceFrom(*ans));
		delete ran1;
		//delete ran2;
	}
	printf("counter3:%f\n", counter3);
	printf("counter2:%f\n", counter2);
	double ratio = counter3/counter2;
	double S1 = pi*pow(c1->radius,2);
	//double S2 = 4*4;
	double inteS = ratio*S1;
	Circle & xx = *c2;
	printf("The rand intersection area:%f\n", inteS);
	printf("The real rand intersection area:%f\n", c1->intersectionArea(xx));
	*/
	Point * p1  = new Point;
	Point * p2  = new Point;
	p1->move(0, 0);
	p2->move(1, 1);
	const double r1 = 1;
	const double r2 = 1;
	Circle * c1 = new Circle(*p1, r1);
	Circle * c2 = new Circle(*p2, r2);
	Circle & xx = *c2;
	printf("The rand intersection area:%f\n", c1->MonteCarloArea(xx));
	printf("The real rand intersection area:%f\n", c1->intersectionArea(xx));


	delete p1;
	delete p2;	
	delete c1;
	delete c2;
	

	return EXIT_SUCCESS;
}
