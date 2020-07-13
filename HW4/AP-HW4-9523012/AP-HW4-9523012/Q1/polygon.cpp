#include "polygon.h"
#include<iostream>


polygon::polygon(point * arr, int size)
{
	s = size;
	poly = new point[s]; // storing points
	for (size_t i{}; i < s; i++)
	{
		poly[i] = arr[i];
	}
}

polygon::polygon(line * arr, int size)
{
	s = size;
	poly = new point[s]; // storing points
	for (size_t i{}; i < s; i++)
	{
		poly[i] = arr[i].intersection(&arr[(i + 1) % s]);
	}
}

bool polygon::isTriangle()
{
	if (s != 3) //  Triangle should have 3 points
		return false;
	else
	{
		// checking if they're not parallel
		line l1{ &poly[0],&poly[1] };
		line l2{ &poly[0],&poly[2] };
		return !(l1.isParallel(&l2));
	}
}

bool polygon::isSquare()
{
	if (s == 4) //Square should have 4 points
	{
		//checking if it's square or not
		line l1{ &poly[0],&poly[1] };
		line l2{ &poly[0],&poly[3] };
		if (poly[0].distance(&poly[1])
			== poly[1].distance(&poly[2]))
			if (poly[2].distance(&poly[3])
				== poly[1].distance(&poly[2]))
				if (poly[2].distance(&poly[3])
					== poly[3].distance(&poly[0]))
					return (l1.isPrependicular(&l2));
		return false;
	}
	else
		return false;
}

bool polygon::isEqual(polygon p)
{
	if (s != p.s) // they should have same size
		return false;
	else
	{
		bool br{ false };
		line* l{ new line[s] }; //lines of first poly
		line* lp{ new line[s] }; // lines of second poly
		// making lines
		for (int i{}; i < s; i++)
		{
			l[i] = line{ &poly[i],&poly[(i + 1) % s] };
			lp[i] = line{ &p.poly[i],&p.poly[(i + 1) % s] };
		}
		// put all of the points of first poly on one of second poly's point
		for (int i{}; i < s; i++)
		{
			br = true;
			// checking the distance of points in order
			for (int j{}; j < s; j++)
			{
				if (!(poly[(i + j) % s].distance(&poly[(i + j + 1) % s])
					== p.poly[j].distance(&p.poly[(j + 1) % s])))
				{
					br = false;
					break;
				}
			}
			if (br)
			{
				// checking the angles of poly in order
				for (int j{}; j < s; j++)
				{
					if ((l[(i + j) % s].angle(l[(i + j + 1) % s])
						- lp[j].angle(lp[(j + 1) % s])))
					{
						br = false;
						break;
					}
				}
				if (br)
					return true;
			}
		}
	}
	return false;


	// second method just for moving the poly

	/*if (s != p.s)
		return false;
	else
	{
		bool br{ false };
		for (int i{}; i < s; i++)
		{
			point d{ p.poly[0] - poly[i] };
			//clockwise
			br = true;
			for (int j{}; j < s; j++)
			{
				std::cout << (poly[(i + j) % s] + d).getX()
					<< ", " << (poly[(i + j) % s] + d).getY()
					<< ", " << p.poly[j].getX() << ", "
					<< p.poly[j].getY() << "\n";
				if (!(poly[(i + j) % s] + d == p.poly[j]))
				{
					std::cout << i << ", " << j << " P\n";
					br = false;
					break;
				}
			}
			if (br)
				return true;
			//counter clockwise
			br = true;
			for (int j{}; j < s; j++)
			{
				std::cout << (poly[(i - j) % s] + d).getX()
					<< ", " << (poly[(i - j) % s] + d).getY()
					<< ", " << p.poly[j].getX() << ", "
					<< p.poly[j].getY() << "\n";
				if (!(poly[(i - j) % s] + d == p.poly[j]))
				{
					std::cout << i << ", " << j << " M\n";
					br = false;
					break;
				}
			}
			if (br)
				return true;
		}
		return false;
	}*/
}

polygon::~polygon()
{
}
