#pragma once
#include"TwoDimensionalShape.h"

class Circle : public TwoDimensionalShape
{
public:
	Circle(const double&, const double&, const double&); //constructor
	Circle(const Circle&); //copy constructor
	Circle(); //default constructor
	~Circle(); //destructor
	virtual void print(); //cout
	virtual Circle operator+(point&) const; // moving center
	virtual double area();
private:
	double c_r; //radius
};

