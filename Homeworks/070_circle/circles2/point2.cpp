#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "point2.hpp"

using namespace std;

Point::Point() : x(0), y(0){

}

void Point::move(double dx, double dy){
	x+=dx;
	y+=dy;
}

double Point::distanceFrom(const Point & p){
	return sqrt(pow((x-p.x),2)+pow((y-p.y),2));
}
