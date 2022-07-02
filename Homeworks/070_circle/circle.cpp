#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <random>
#include "circle.hpp"
#define pi 3.141592654

using namespace std;

Circle::Circle(Point p, const double r) : center(p), radius(r){
	
}

void Circle::move(double dx, double dy){
	/*Cause x and y is private in class Point, therefor u can't access them here
	center.x += dx;
	center.y += dy;
	*/
	//You should implement move here with:
	center.move(dx, dy);//Cause the move method in Point is public.
}
/*
//Intersection area by the mathmatical formula:
double Circle::intersectionArea(const Circle & otherCircle){
	double dist = center.distanceFrom(otherCircle.center);
	double sumR = radius+otherCircle.radius;
	double diffR = fabs(radius-otherCircle.radius);
	if(sumR<=dist){//Circumcircle
		return 0;
	}
	else if(diffR>=dist){
		if(radius<=otherCircle.radius){
			return pi*pow(radius, 2);
		}
		else{
			return pi*pow(otherCircle.radius, 2);
		}
	}
	else{
		double alpha = acos((pow(radius,2)+pow(dist,2)-pow(otherCircle.radius,2))/(2*radius*dist));
		double beta = acos((pow(otherCircle.radius,2)+pow(dist,2)-pow(radius,2))/(2*otherCircle.radius*dist));
		double S1 = 0.5*alpha*pow(radius,2);
		double S2 = 0.5*beta*pow(otherCircle.radius,2);
		double triangle = 0.5*radius*dist*sin(alpha);
		//printf("2*(S1+S2-triangle):%.f\n", 2*(S1+S2-triangle));
		return 2*(S1+S2-triangle);
	}
}
*/

double Circle::intersectionArea(Circle & otherCircle){//Intersection area by the MonteCarlo method:
	double counter = 0;
	double check = 0;
	int num = 50000;
	double x1min = center.x-radius;
	double x1max = center.x+radius;
	double y1min = center.y-radius;
	double y1max = center.y+radius;
	////
	default_random_engine e(time(0));
	uniform_real_distribution<double> u1x(x1min, x1max);
	uniform_real_distribution<double> u1y(y1min, y1max);
	while(counter<num){
		Point * ran1 = new Point;
		ran1->x = u1x(e);
		ran1->y = u1y(e);
		//const Point & yy = ran1; 
		if(center.distanceFrom(*ran1)>radius){
			delete ran1;
			continue;
		}
		counter++;
		if(center.distanceFrom(*ran1)<=radius&&otherCircle.center.distanceFrom(*ran1)<=otherCircle.radius){
			check++;
		}
		//printf("dist:%f\n", p->distanceFrom(*ans));
		delete ran1;
		//delete ran2;
	}
	double ratio = check/counter;
	double S1 = pi*pow(radius,2);
	//double S2 = 4*4;
	double inteS = ratio*S1;

	return inteS;
}

