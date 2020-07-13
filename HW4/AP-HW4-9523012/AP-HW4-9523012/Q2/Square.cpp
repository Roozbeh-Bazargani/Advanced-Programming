#include "Square.h"



Square::Square(const double& a, const double& x,
	const double& y)
{
	sq_a = a;
	this->x = x;
	this->y = y;
}

Square::Square(const Square & s)
{
	x = s.x;
	y = s.y;
	sq_a = s.sq_a;
}

Square::Square()
{
	// deafault = 0
	x = 0;
	y = 0;
	sq_a = 0;
}

Square::~Square()
{
}

void Square::print()
{
	std::cout << "Square side length = " << sq_a
		<< "\ncenter --> (" << x << ", " << y
		<< ")\narea of " << area() << "\n\n";

	/*Square side length = 12
	center --> (2, 2)
	area of 144*/
}

Square Square::operator+(point & p)
{
	Square sum{};
	// just moving center
	sum.x = x + p.getX();
	sum.y = y + p.getY();
	
	sum.sq_a = sq_a;
	return sum;
}

double Square::area()
{
	return sq_a * sq_a; //a^2

}


