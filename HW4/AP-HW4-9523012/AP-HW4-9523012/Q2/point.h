#ifndef _POINT_H_
#define _POINT_H_


#include<math.h>


class point
{
public:
	point(double x = 0, double y = 0, double z = 0); //constructor
	point(const point*); //copy constructor
	~point(); //destructor
	double getX() { return x; } // x of point
	double getY() { return y; } // y of point
	double getZ() { return z; } // z of point
	double distance(point*); // distance of two points
private:
	double x, y, z;
};

#endif 
