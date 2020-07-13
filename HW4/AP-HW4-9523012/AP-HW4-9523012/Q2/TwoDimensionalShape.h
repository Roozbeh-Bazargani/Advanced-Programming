#pragma once

#include"Shape.h"

class TwoDimensionalShape : public Shape // child
{
public:
	TwoDimensionalShape();
	~TwoDimensionalShape();
	virtual void print(); // cout
	virtual double area() = 0;
};

