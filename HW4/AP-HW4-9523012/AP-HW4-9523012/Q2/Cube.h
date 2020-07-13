#pragma once
#include"ThreeDimensionalShape.h"

class Cube : public ThreeDimensionalShape
{
public:
	Cube(const double& a, const double& b = 0,
		const double& c = 0, const double& d = 0); //constructor
	Cube(const Cube&); //copy constructor
	Cube(); //default constructor
	~Cube(); //destructor
	virtual Cube operator+(point&); // moving center
	virtual void print(); //cout
	virtual double area();
	virtual double volume();
private:
	double c_a; //side length
};

