#ifndef _POINT_H_
#define _POINT_H_


#include<math.h>

class line;

class point
{
public:
	point(int x, int y); //constructor
	point(const point*); // * copy constructor
	point(const point&); //copy constructor
	point(); //defualt constructor
	~point(); //destructor
	int getX() { return x; } // x of point
	int getY() { return y; } // y of point
	int distance(point*); // distance of two points
	line* Line(point*); // new line by two points
	bool operator==(const point&) const;
	void operator=(const point&);
	point operator+(const point&) const;
	point operator-(const point&) const;
private:
	int x, y;
	line* lp;
};

#endif 
