#include <iostream>

#include "circle.h"
#include "square.h"
#include "sphere.h"
#include "cube.h"

using std::cout;


int main()
{
	// Given main

	Square sqr(12, 2, 2);
	Sphere sph(5, 1.5, 4.5);
	Cube cub(2.2);
	Circle cir(3.5, 6, 9);
	Shape *ptr[4] = { &cir, &sqr, &sph, &cub };
	
	for (int x = 0; x < 4; ++x)
		cout << *(ptr[x]) << '\n';


	// My main
	std::cout << "My main:\n\n";
	point p1{ -4,-3,-5 };
	point p2{ -2,3,0 };
	point p3{ -3,7,-7 };
	point p4{ 4,-5,3 };


	// Square + Point
	std::cout << "\nsqr + p1:\n";
	Square temp1{ sqr + p1 };
	std::cout << temp1;

	// Sphere + Point
	std::cout << "\nsph + p2:\n";
	Sphere temp2{ sph + p2 };
	std::cout << temp2;


	// Cube + Point
	std::cout << "\ncub + p3:\n";
	Cube temp3{ cub + p3 };
	std::cout << temp3;



	// Circle + Point
	std::cout << "\ncir + p4:\n";
	Circle temp4{ cir + p4 };
	std::cout << temp4;

	return 0;
}

