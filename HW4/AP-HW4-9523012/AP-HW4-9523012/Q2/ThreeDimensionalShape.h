#pragma once
#include"Shape.h"

class ThreeDimensionalShape : public Shape //child
{
public:
	ThreeDimensionalShape();
	~ThreeDimensionalShape();
	virtual void print(); // cout
	virtual double area() = 0;
	virtual double volume() = 0;
};

