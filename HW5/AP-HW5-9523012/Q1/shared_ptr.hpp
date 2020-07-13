#pragma once


template<class T>
inline shared_ptr<T>::shared_ptr()
{ // default constructor
	cnt = new size_t{ 1 };
	pt = new size_t{};
}

template<class T>
inline shared_ptr<T>::shared_ptr(T * t)
{ // constructor
	cnt = new size_t{ 1 };
	pt = t;
	std::cout << "Constructor " << *pt << std::endl;
}

template<class T>
inline shared_ptr<T>::shared_ptr(shared_ptr & s)
{ // copy constructor
	pt = s.pt;
	cnt = s.cnt;
	(*cnt)++;
}

template<class T>
inline shared_ptr<T>::~shared_ptr()
{ // destructor
	(*cnt)--;
	if (!(*cnt))
	{
		std::cout << "Destructor " << *pt << std::endl;
		delete cnt;
		delete pt;
	}
}

template<class T>
inline size_t shared_ptr<T>::use_count()
{ // How many arguments
	return *cnt;
}

template<class T>
inline T * shared_ptr<T>::operator->()
{ // operator returning T*
	return pt;
}