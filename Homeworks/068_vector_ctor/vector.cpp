#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "vector.hpp"
using namespace std;

/*
void Vector2D::initVector(double init_x, double init_y){
	x = init_x;
	y = init_y;
}
*/

Vector2D::Vector2D() : x(0), y(0){

}

Vector2D::Vector2D(double xIn, double yIn) : x(xIn), y(yIn){

}

double Vector2D::getMagnitude() const{
	return sqrt(pow(x,2)+pow(y,2));
}

Vector2D Vector2D::operator+(const Vector2D & rhs) const{
	Vector2D ans;
	ans.x = this->x + rhs.x;
	ans.y = this->y + rhs.y;
	return ans;
}

Vector2D & Vector2D::operator+=(const Vector2D & rhs){
	this->x = x+rhs.x;//U can use x directly here, no need to use this->
	this->y = y+rhs.y;
	return *this;
}

double Vector2D::dot(const Vector2D & rhs) const{
	return this->x*rhs.x + this->y*rhs.y;
}

void Vector2D::print() const{
	printf("<%.2f, %.2f>", x, y);
}
