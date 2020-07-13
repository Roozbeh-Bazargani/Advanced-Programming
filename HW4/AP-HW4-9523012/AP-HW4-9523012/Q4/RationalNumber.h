#include<iostream>

#include<utility>
// making all other operators
using namespace std::rel_ops;

int bmm(int, int); // greatest common divisor

class RationalNumber
{
public:
	RationalNumber(const int&, const int&); //constructor
	RationalNumber(); //default constructor
	void show(); // show
	RationalNumber operator+(const RationalNumber&) const;
	RationalNumber operator-(const RationalNumber&) const;
	RationalNumber operator*(const RationalNumber&) const;
	RationalNumber operator/(const RationalNumber&) const;
	bool operator>(const RationalNumber&) const;
	bool operator==(const RationalNumber&) const;
	
private:
	int a, b;
};
