#include<iostream>

template <class T>
class shared_ptr
{
	size_t* cnt; // number of elements
	T* pt; // object
public:
	shared_ptr(); // default constructor
	shared_ptr(T*); // constructor
	shared_ptr(shared_ptr&); // copy constructor
	~shared_ptr(); // destructor
	size_t use_count(); // How many arguments
	T* operator->(); // operator returning T*
};

#include"shared_ptr.hpp"