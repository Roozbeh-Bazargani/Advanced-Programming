#pragma once

#include<string>


class Test
{
	std::string s;
public:
	Test(const std::string& ss) { s = ss; } // constructor
	~Test() = default; // destructor
	friend std::ostream & operator<<(std::ostream & os, Test & s); // operator <<
	void display(); // show
};