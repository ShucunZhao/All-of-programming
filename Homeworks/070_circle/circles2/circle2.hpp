#include "point2.hpp"
//class Point;

class Circle{
/*
private:
	Point center;
	const double radius;
	*/
public:
	Point center;
	const double radius;
	Circle(Point p, const double r);
	void move(double dx, double dy);
	double intersectionArea(Circle & otherCircle);
	double MonteCarloArea(Circle & otherCircle);
	

};
