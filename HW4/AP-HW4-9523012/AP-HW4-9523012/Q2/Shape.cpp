#include "Shape.h"


Shape::Shape() // no need to anything
{
}

void Shape::print() // no need to anything
{
}


Shape::~Shape() // no need to anything
{
}

std::ostream & operator<<(std::ostream & os, Shape & s)
{
	s.print();
	return os;
}
