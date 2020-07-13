#include "Sphere.h"

Sphere::Sphere(const double& r, const double& a,
	const double& b, const double& c)
{
	sp_r = r;
	x = a;
	y = b;
	z = c;
}

Sphere::Sphere(const Sphere & s)
{
	x = s.x;
	y = s.y;
	z = s.z;
	sp_r = s.sp_r;
}

Sphere::Sphere()
{
	// deafault = 0
	x = 0;
	y = 0;
	z = 0;
	sp_r = 0;
}

Sphere::~Sphere()
{
}

void Sphere::print()
{
	std::cout << "Sphere radius = " << sp_r
		<< "\ncenter --> (" << x << ", " << y << ", "
		<< z << ")\narea of " << area() << " & volume of "
		<< volume() << "\n\n";

	/*Sphere radius = 5
	center --> (1.5, 4.5, 0)
	area of 314.159 & volume of 523.598*/
}

Sphere Sphere::operator+(point & p)
{
	Sphere sum{};
	// just moving center
	sum.x = x + p.getX();
	sum.y = y + p.getY();
	sum.z = z + p.getZ();

	sum.sp_r = sp_r;
	return sum;
}

double Sphere::area()
{
	double pi{ acos(-1) };
	return pi * sp_r * sp_r * 4; // S = 4pir^2
}

double Sphere::volume()
{
	double pi{ acos(-1) };
	return pi * sp_r * sp_r * sp_r * 4 / 3; // 4/3 * pi * r^3
}

