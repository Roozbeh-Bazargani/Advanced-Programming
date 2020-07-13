#include"Vector.h"


int main()
{
	Vector v{};
	Vector v1{};
	Vector v2{};
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.Subvec(1); // v.Subvec(1) = 2
	v1 = v;
	v.pop_back();
	v2 = v1 + v; // v2 = 1,2,3,1,2
	v2.display();
	std::cout << "size: " << v.size() << "\n";
	std::cout << "max_size: " << v1.max() << "\n";
	v.display();
	return 0;
}

