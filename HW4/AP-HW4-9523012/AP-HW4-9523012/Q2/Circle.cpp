#include "Circle.h"


Circle::Circle(const double& r, const double& a, const double& b)
{
	c_r = r;
	x = a;
	y = b;
}

Circle::Circle(const Circle & c)
{
	x = c.x;
	y = c.y;
	c_r = c.c_r;
}

Circle::Circle()
{
	// deafault = 0
	x = 0;
	y = 0;
	c_r = 0;
}

Circle::~Circle()
{
}

void Circle::print()
{
	std::cout << "Circul radius = " << c_r
		<< "\ncenter --> (" << x << ", " << y
		<< ")\narea of " << area() << "\n\n";

	/*Circle radius = 3.5
	center--> (6, 9)
	area of 38.4845*/
}

Circle Circle::operator+(point& p) const
{
	Circle sum{};
	//just moving center
	sum.x = x + p.getX();
	sum.y = y + p.getY();

	sum.c_r = c_r;
	return sum;
}

double Circle::area()
{
	double pi{ acos(-1) };
	return c_r * c_r * pi; // pi*r^2
}

