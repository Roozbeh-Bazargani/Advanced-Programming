#include "point.h"


point::point(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

point::point(const point *p)
{
	x = p->x;
	y = p->y;
	z = p->z;
}

point::~point() //second method
{
	//delete lp;
}

double point::distance(point * p) //sqrt(x^2-y^2)
{
	return sqrt((x - (*p).x)*(x - (*p).x)
		+ (y - (*p).y)*(y - (*p).y));
}
