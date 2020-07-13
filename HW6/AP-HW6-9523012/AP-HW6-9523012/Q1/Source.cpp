#include<iostream>
#include<vector>

int main()
{
	// Adding elements
	std::vector<int> v;
	for (int i{}; i < 1000; i++)
	{
		v.push_back(i);
		std::cout << "Capacity : " << v.capacity() << " ,  Size : " << v.size() << std::endl;
	}

	// erasing elements
	for (int i{}; i < 1000; i++)
	{
		v.erase(v.begin());
		std::cout << "Capacity : " << v.capacity() << " ,  Size : " << v.size() << std::endl;
	}
	return 0;
}
