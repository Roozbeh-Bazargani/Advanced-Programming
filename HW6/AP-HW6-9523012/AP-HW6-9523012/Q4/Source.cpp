#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
#include<functional>

void print(const std::vector<size_t>& v);

int main()
{
	std::string s{};
	std::vector<size_t> v{};
	std::cout << "binary array for coding:\n";
	std::getline(std::cin, s); // reading binary array
	for (size_t i{}; i < s.size(); i++)
		v.push_back(s[i] - '0'); // transfer from string to vector
	
	// Start Coding

	std::vector<size_t> ones{ 1,1,1,1,1 };
	if (v.size() > 4) // could there be a flag?
	{
		for (auto i{ v.begin() }; i < v.end() - 4; i++)
		{
			if (!(std::inner_product(i, i + 5, ones.begin(), -5))) // sum of products
			{
				i = v.insert(i + 5, 0); // insert 0
			}
		}
	}
	v.insert(v.end(), { 1, 1, 1, 1, 1, 1 }); // end flag

	std::cout << "code :\n";
	print(v);
	return 0;
}

void print(const std::vector<size_t>& v) // show
{
	for (double i : v)
		std::cout << i;
	std::cout << "\n";
}