#include "RationalNumber.h"


RationalNumber::RationalNumber(const int& a, const int& b)
{
	if (b <= 0) // Wrong Denominator
		std::cout << "Wrong Denominator!";
	else
	{
		int bmmx{}; // using this function to make it simple
		if (a > b)
			bmmx = bmm(a, b);
		else
			bmmx = bmm(b, a);
		
		this->a = a / bmmx;
		this->b = b / bmmx;
	}
}

RationalNumber::RationalNumber()
{
	//default number is 0
	a = 0;
	b = 1;
}

void RationalNumber::show()
{
	int bmmx{}; // using this function to make it simple
	if (a > b)
		bmmx = bmm(a, b);
	else
		bmmx = bmm(b, a);
	a /= bmmx;
	b /= bmmx;
	std::cout << a << "/" << b;
}

RationalNumber RationalNumber::operator+(const RationalNumber &x) const
{
	RationalNumber s{};
	s.a = a*x.b + x.a*b;
	s.b = b*x.b;
	return s;
}

RationalNumber RationalNumber::operator-(const RationalNumber &x) const
{
	RationalNumber s{};
	s.a = a*x.b - x.a*b;
	s.b = b*x.b;
	return s;
}

RationalNumber RationalNumber::operator*(const RationalNumber &x) const
{
	RationalNumber s{};
	s.a = a*x.a;
	s.b = b*x.b;
	return s;
}

RationalNumber RationalNumber::operator/(const RationalNumber &x) const
{
	RationalNumber s{};
	s.a = a*x.b;
	s.b = b*x.a;
	return s;
}

bool RationalNumber::operator>(const RationalNumber &x) const
{
	return (static_cast<double>(a) / b) > (static_cast<double>(x.a) / x.b);
}

bool RationalNumber::operator==(const RationalNumber &x) const
{
	return (static_cast<double>(a) / b) == (static_cast<double>(x.a) / x.b);
}

int bmm(int x, int y)
{
	while (y) // math method
	{
		int t{ x%y };
		x = y;
		y = t;
	}
	return x;
}