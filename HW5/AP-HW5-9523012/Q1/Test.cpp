#include "Test.h"
#include<iostream>



void Test::display()
{ // show
	std::cout << s << " DISPLAY\n";
}

std::ostream & operator<<(std::ostream & os, Test & t)
{ // operator << for cout
	// TODO: insert return statement here
	std::cout << t.s;
	return os;
}
