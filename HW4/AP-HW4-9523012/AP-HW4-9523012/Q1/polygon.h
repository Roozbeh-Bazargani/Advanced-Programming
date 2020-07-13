#pragma once

#ifndef _POLYGON_H_
#define _POLYGON_H_

#include"point.h"
#include"line.h"

class point;
class line;

class polygon
{
public:
	polygon(point* arr, int size); //constructor for point
	polygon(line* arr, int size); //constructor for line
	bool isTriangle(); // Is triangle?
	bool isSquare(); // Is square?
	bool isEqual(polygon p); // Is Equal?
	~polygon();
private:
	point* poly;
	int s; // number of points in poly
};

#endif