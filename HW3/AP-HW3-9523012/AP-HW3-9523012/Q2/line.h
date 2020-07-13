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
	~line(); //destructor
	bool isParallel(line*l) { return m == l->m; }
	bool isPrependicular(line*l) { return (m*l->m) == -1; }
	point* intersection(line*);
	line* parallel(point*); //making new parallel line
private:
	double m, c;
	point* p;
	line* lpointer;
};

#endif
