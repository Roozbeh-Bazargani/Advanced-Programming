#include "line.h"

line::line(point *p1, point *p2) //y=mx+c
{
	m = static_cast<double>(p1->getY() - p2->getY())
		/ (p1->getX() - p2->getX());
	c = p1->getY() - m*p1->getX();
	p = new point{ 0,0};
	lpointer = new line{ 0.,0.};
}

line::line(const double &m, const double &c)
{
	this->m = m;
	this->c = c;
}

line::line(const line *l)
{
	m = l->m;
	c = l->c;
}

line::~line() //second method
{
  //delete p;
  //delete lpointer;
}

point * line::intersection(line *l) 
{
	int x{ static_cast<int>((c - l->c) / (l->m - m)) };
	//m1*x+c1=m2*x+c2
	int y{ static_cast<int>(m*x + c) }; //y=m1*x+c1
	delete p;
	p = new point{ x,y };
	return p;
}

line * line::parallel(point *p)
{
  delete lpointer;
	line* lpointer = new line
	{ m, p->getY() - m*p->getX() }; //c=y-mx
	return lpointer;
}

