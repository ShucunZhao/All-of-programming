#include "point.hpp"
//class Point;

class Circle{
/*	
//Intersection area by the mathmatical formula:
private:
	Point center;
	const double radius;
public:
	Circle(Point p, double r);
	void move(double dx, double dy);
	double intersectionArea(const Circle & otherCircle);
*/

//Intersection area by the MonteCarlo method:
private:
	Point center;
	const double radius;
public:
	Circle(Point p, double r);
	void move(double dx, double dy);
	double intersectionArea(Circle & otherCircle);
};
