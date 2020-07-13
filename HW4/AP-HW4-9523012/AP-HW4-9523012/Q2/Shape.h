#pragma once

#include<iostream>
#include<math.h>

#include"point.h"


class Shape
{
public:
	Shape();
	virtual void print(); // cout
	~Shape();
	friend std::ostream & operator<<(std::ostream & os, Shape & s);

protected:
	double x, y, z; // of center
};

