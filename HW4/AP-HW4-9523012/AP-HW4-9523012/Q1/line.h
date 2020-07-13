#ifndef _LINE_H_
#define _LINE_H_

#include"point.h"
#include<iostream>

class line
{
public:
	line(point*, point*); //constructor
	line(const double&, const double&); //constructor
	line(const line*); // * copy constructor
	line(); // copy constructor
	~line(); //destructor
	bool isParallel(line*l);
	bool isPrependicular(line*l);
	point* intersection(line*);
	line* parallel(point*); //making new parallel line
	double angle(const line& l); // angle between 2 lines
private:
	double m, c;
	bool vertical;
	point* p;
	line* lpointer;
};

#endif
