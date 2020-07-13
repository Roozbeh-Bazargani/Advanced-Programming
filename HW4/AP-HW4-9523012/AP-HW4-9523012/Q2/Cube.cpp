#include "Cube.h"



Cube::Cube(const double& a, const double& b,
	const double& c, const double& d)
{
	c_a = a;
	x = b;
	y = c;
	z = d;
}

Cube::Cube(const Cube & c)
{
	x = c.x;
	y = c.y;
	z = c.z;
	c_a = c.c_a;
	
}

Cube::Cube()
{
	// deafault = 0
	x = 0;
	y = 0;
	z = 0;
	c_a = 0;
	
}

Cube::~Cube()
{
}

Cube Cube::operator+(point & p)
{
	Cube sum{};
	// just moving center
	sum.x = x + p.getX();
	sum.y = y + p.getY();
	sum.z = z + p.getZ();

	
	sum.c_a = c_a;
	return sum;
}

void Cube::print()
{
	std::cout << "Cude side length = " << c_a
		<< "\ncenter --> (" << x << ", " << y << ", "
		<< z << ")\narea of " << area() << " & volume of "
		<< volume() << "\n\n";

	/*Cube side length = 2.2
	center --> (0, 0, 0)
	area of 29.04 & volume of 10.648*/
}

double Cube::area()
{
	return 6 * c_a * c_a; // 6a^2
}

double Cube::volume()
{
	return c_a * c_a * c_a; //a^3
}

