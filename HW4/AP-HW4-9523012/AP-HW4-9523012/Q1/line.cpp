#include<math.h>
#include "line.h"

line::line(point *p1, point *p2) //y=mx+c
{
	if (p1->getX() == p2->getX())
	{
		if (p1->getY() == p2->getY())
			std::cout << "Error! : Same points, Can't make line";
		else
		{
			//std::cout << "vertical\n";
			vertical = true;
			c = p1->getX();
		}
	}
	else
	{
		vertical = false;
		m = static_cast<double>(p1->getY() - p2->getY())
			/ (p1->getX() - p2->getX());
		c = p1->getY() - m*p1->getX();
	}
	p = new point{ 0,0 };
	lpointer = new line{ 0.,0. };
}

line::line(const double &m, const double &c)
{
	this->m = m;
	this->c = c;
}

line::line(const line *l)
{
	if (l->vertical)
	{
		vertical = true;
		c = l->c;
	}
	else
	{
		m = l->m;
		c = l->c;
	}
}

line::line()
{
	m = 1;
	c = 0;
	vertical = false;
	p = new point{ 0,0 };
	lpointer = new line{ 0.,0. }; //Might be a Problem!!
}


line::~line() //second method
{
	//delete p;
	//delete lpointer;
}

bool line::isParallel(line * l)
{
	if (vertical & l->vertical)
		return true;
	else if (!(vertical | l->vertical))
		return m == l->m;
	else
		return false;
}

bool line::isPrependicular(line * l)
{
	if (vertical & l->vertical)
		return false;
	else if (!(vertical | l->vertical))
		return m == l->m;
	else
	{
		if (vertical)
			return (l->m == 0);
		else
			return (m == 0);
	}
}

point * line::intersection(line *l)
{
	if (vertical & l->vertical)
	{
		std::cout << "Error!! : Intersection between lines!\n";
		return nullptr;
	}
	else if (!(vertical | l->vertical))
		if (m == l->m)
		{
			std::cout << "Error!! : Intersection between lines!\n";
			return nullptr;
		}
		else
		{
			int x{ static_cast<int>((c - l->c) / (l->m - m)) };
			//m1*x+c1=m2*x+c2
			int y{ static_cast<int>(m*x + c) }; //y=m1*x+c1
			delete p;
			p = new point{ x,y };
			return p;
		}
	else
	{
		if (vertical)
		{
			int x{ static_cast<int>(c) };
			int y{ static_cast<int>((l->m)*x + (l->c)) }; //y=m1*x+c1
			delete p;
			p = new point{ x,y };
			return p;
		}
		else
		{
			int x{ static_cast<int>(l->c) };
			int y{ static_cast<int>(m*x + c) }; //y=m1*x+c1
			delete p;
			p = new point{ x,y };
			return p;
		}
	}
}

line * line::parallel(point *p)
{
	if (vertical)
	{
		point pnew{ p->getX(), p->getY() - 1 };//x=c
		delete lpointer;
		line* lpointer = new line
		{ p, &pnew }; 
		return lpointer;
	}
	else
	{
		delete lpointer;
		line* lpointer = new line
		{ m, p->getY() - m*p->getX() }; //c=y-mx
		return lpointer;
	}
}

double line::angle(const line & l)
{
	double pi{ acos(-1) };
	if (vertical & l.vertical)
	{
		return 0.;
	}
	else if (!(vertical | l.vertical))
	{
		double mr{ atan(m) - atan(l.m) };
		if (mr < 0)
		{
			mr += pi;
		}
		return mr;
	}
	else
	{
		if (vertical)
		{
			double mr{ pi / 2 - atan(l.m) };
			if (mr < 0)
			{
				mr += pi;
			}
			return mr;
		}
		else
		{
			double mr{ atan(m) - pi / 2 };
			if (mr < 0)
			{
				mr += pi;
			}
			return mr;
		}
	}
}
