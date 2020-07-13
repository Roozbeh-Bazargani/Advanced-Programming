#include "Vector.h"


Vector::Vector()
{
	//std::cout << "constructor\n";
	N = 0;
	p = new int[N];
}


Vector::~Vector()
{
	//std::cout << "destructor\n";
	delete[] p;
}

Vector::Vector(const Vector &v)
{
	//std::cout << "copy constructor\n";
	N = v.N;
	p = new int[N];
	for (size_t i{}; i < N; i++)
	{
		p[i] = v.p[i];
	}
}

void Vector::display()
{
	if (N == 0) //check if the vector is empty or not
	{
		std::cout << "There is no element in this vector!\n";
	}
	else
	{
		std::cout << "Elements of the vector is: ";
		for (size_t i{}; i < N - 1; i++)
			std::cout << p[i] << ", ";
		{
			std::cout << p[N - 1] << "\n";
		}
	}
}

void Vector::push_back(int x)
{
	int* pnew{ new int[N + 1] }; //new pointer with 1 more size
	for (size_t i{}; i < N; i++)
		pnew[i] = p[i];
	pnew[N] = x;
	delete[] p; //delete formal pointer
	p = pnew;
	N += 1;
}

void Vector::operator=(const Vector& v)
{
	//std::cout << "operator =\n";
	N = v.N;
	delete[] p; //delete formal pointer
	p = new int[N]; //new pointer same size of v
	for (size_t i{}; i < N; i++) //adding elements of v in vector
	{
		p[i] = v.p[i];
	}
}

Vector Vector::operator+(const Vector& v) const
{
	//std::cout << "operator +\n";
	Vector ret{}; //new vector for return it
	ret.N = N + v.N;
	ret.p = new int[ret.N]; //new pointer with new size
	//adding elements of v in vector
	for (size_t i{}; i < N; i++)
	{
		ret.p[i] = p[i];
	}
	for (size_t i{ N }; i < ret.N; i++)
	{
		ret.p[i] = v.p[i - N];
	}
	return ret;
}

int Vector::max() const
{
	int max{ p[0] };
	for (size_t i{ 1 }; i < N; i++)
		if (max < p[i])
			max = p[i];
	return max;
}

void Vector::pop_back()
{
	int* pnew{ new int[N - 1] }; //new pointer with 1 less size
	for (size_t i{}; i < N - 1; i++)
		pnew[i] = p[i];
	delete[] p; //delete formal pointer
	p = pnew;
	N -= 1;
}

void Vector::Subvec(const size_t &x)
{
	std::cout << "Subvec(" << x << ")= " << p[x] << "\n";
}
