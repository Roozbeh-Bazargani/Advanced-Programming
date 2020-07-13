#include<iostream>
#include"shared_ptr.h"
#include"Test.h"

using PT = shared_ptr<Test>;
void check(PT);

int main()
{
	PT p1{ new Test{"p1"} };
	std::cout << p1.use_count() << std::endl;
	PT p2{ p1 };
	std::cout << p1.use_count() << ", " <<
		p2.use_count() << std::endl;
	PT p3{ p2 };
	std::cout << p1.use_count() << ", " << 
		p2.use_count() << ", " << 
		p3.use_count() << std::endl;
	check(p3);
	std::cout << p1.use_count() << ", " <<
		p2.use_count() << ", " << 
		p3.use_count() << std::endl;
	PT p4{ new Test{"p4"} };
	std::cout << p1.use_count() << ", " <<
		p2.use_count() << ", " <<
		p3.use_count() << ", " << 
		p4.use_count() << std::endl;
    return 0;
}

void check(PT p) {
	p->display();
	std::cout << p.use_count() << std::endl;
}

