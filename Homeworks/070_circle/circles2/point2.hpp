class Point{
/*
private:
	double x;
	double y;
	*/
public:
	double x;
	double y;
	Point();
	void move(double dx, double dy);
	double distanceFrom(const Point & p);
};
