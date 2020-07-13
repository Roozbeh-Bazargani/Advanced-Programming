#include "point.h"
#include"line.h"


point::point(int x, int y)
{
	this->x = x;
	this->y = y;
	lp = new line{ 0.,0. };
}

point::point(const point *p)
{
	x = p->x;
	y = p->y;
}

point::point(const point & p)
{
	x = p.x;
	y = p.y;
	lp = new line{ 0.,0. };
}

point::point()
{
	x = 0;
	y = 0;
}

point::~point() //second method
{
	//delete lp;
}

int point::distance(point * p)
{
	return static_cast<int>(sqrt((x - (*p).x)*(x - (*p).x)
		+ (y - (*p).y)*(y - (*p).y)));
}

line * point::Line(point *p)
{
	delete lp;
	line* lp = new line{ p,this };
	//use two point* constructor
	return lp;
}

bool point::operator==(const point& p) const
{
	return ((x == p.x) & (y == p.y));
}

void point::operator=(const point & p)
{
	x = p.x;
	y = p.y;
	lp = new line{ 0.,0. };
}

point point::operator+(const point &p) const
{
	point sum{};
	sum.x = x + p.x;
	sum.y = y + p.y;
	return sum;
}

point point::operator-(const point &p) const
{
	point sum{};
	sum.x = x - p.x;
	sum.y = y - p.y;
	return sum;
}
