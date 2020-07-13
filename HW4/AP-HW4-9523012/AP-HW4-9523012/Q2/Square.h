#pragma once
#include"TwoDimensionalShape.h"

class Square : public TwoDimensionalShape
{
public:
	Square(const double&, const double&, const double&); //constructor
	Square(const Square&); //copy constructor
	Square(); //default constructor
	~Square(); //destructor
	virtual void print(); //cout
	virtual Square operator+(point&); // moving center
	virtual double area();
private:
	double sq_a; //side length
};

