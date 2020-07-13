#include"line.h"

#include<iostream>

int main() //Sample code
{
	point p1{ 0,-1 };
	point p2{ 1,0 };
	point p3{ 0,2 };
	point p4{ 4,0 };
	point p5{ 2,3 };
	std::cout << p1.getX() << p1.getY() << "\n";
	std::cout << p1.distance(&p1) << std::endl;
	line l1{ &p2,&p1 };
	line* l2{ p3.Line(&p4) };
	line l3{ l2->parallel(&p1) };
	if (l2->isParallel(&l3))
		std::cout << "It's parallel 1\n";
	if (l1.isPrependicular(l2))
		std::cout << "It's prependicular\n";
	point p6{ l1.intersection(l2) };
	std::cout << p6.getX() << "\n";
	std::cout << p6.getY() << "\n";
	line l4{ &p4,l1.intersection(l2) };
	if (l4.isParallel(l2))
		std::cout << "It's parallel 2\n";
	return 0;
}