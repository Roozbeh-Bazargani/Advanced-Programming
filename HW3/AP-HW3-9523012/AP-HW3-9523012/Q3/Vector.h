#include<iostream>

class Vector
{
public:
	Vector(); //constructor
	~Vector(); //destructor
	Vector(const Vector&); //copy constructor
	void display();
	void push_back(int); //add new element at end 
	void pop_back(); //delete last element
	void Subvec(const size_t&); //returning v[x]
	void operator=(const Vector&); 
	Vector operator+(const Vector&) const;
	//return a vector with elements of two vectors
	size_t size() const { return N; }; //size of vector
	int max() const; //maximum element of vector
private:
	int* p;
	size_t N;
};