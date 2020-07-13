#pragma once

#include"ThreeDimensionalShape.h"
class Sphere : public ThreeDimensionalShape
{
public:
	Sphere(const double&, const double& a = 0
		, const double& b = 0, const double& c = 0); // constructor
	Sphere(const Sphere&); //copy constructor
	Sphere(); //default constructor
	~Sphere(); //destructor
	virtual void print(); //cout
	virtual Sphere operator+(point&); // moving center
	virtual double area();
	virtual double volume();
private:
	double sp_r; //radius
};

