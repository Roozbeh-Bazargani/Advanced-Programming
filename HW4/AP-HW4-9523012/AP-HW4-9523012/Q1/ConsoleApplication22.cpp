#include"line.h"
#include"polygon.h"

#include<iostream>

int main()
{
	point p1{ 8,0 };
	point p2{ 0,0 };
	point p3{ 0,8 };
	point p4{ 8,8 };
	point p5{ 11,4 };

	point p6{ 0,0 };
	point p7{ 3,-4 };
	point p8{ 0,-8 };
	point p9{ -8,-8 };
	point p10{ -8,0 };


		//HW4
	point p[5];
	p[0] = p1;
	p[1] = p2;
	p[2] = p3;
	p[3] = p4;
	p[4] = p5;
	polygon po1{ p, 5 };
	point pr[5];
	pr[4] = p6;
	pr[0] = p7;
	pr[1] = p8;
	pr[2] = p9;
	pr[3] = p10;
	polygon po2{ pr, 5 };
	if (po1.isEqual(po2))
		std::cout << "isEqual\n";


	point pr1[3];
	pr1[0] = p1;
	pr1[1] = p2;
	pr1[2] = p3;
	polygon tr1{ pr1,3 };
	if (tr1.isTriangle())
		std::cout << "Triangle!\n";


	point pr2[4];
	pr2[0] = p1;
	pr2[1] = p2;
	pr2[2] = p3;
	pr2[3] = p4;
	polygon sq1{ pr2,4 };
	if (sq1.isSquare())
		std::cout << "Square!\n";

	return 0;
}