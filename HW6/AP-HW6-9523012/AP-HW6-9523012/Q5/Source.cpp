#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>
#include<functional>

void print(const std::vector<size_t>& v); // show

int main()
{
	std::string s{};
	std::vector<size_t> v{};
	std::cout << "Coded binary array:\n";
	std::getline(std::cin, s); // reading binary array
	for (size_t i{}; i < s.size(); i++)
		v.push_back(s[i] - '0'); // filling vector

	// Start Decoding

	std::vector<size_t> ones{ 1,1,1,1,1 };
	if (v.size() > 4)
	{
		for (auto i{ v.begin() }; i < v.end() - 4; i++)
		{
			if (!(std::inner_product(i, i + 5, ones.begin(), -5))) // finding five 1
			{
				if (*(i + 5)) // 6th is 1?
				{ // flag
					v.erase(i, v.end());
					break;
				}
				else
				{ // not flag
					v.erase(i + 5);
					i += 4;
				}
			}
		}
	}

	std::cout << "Decode :\n";
	print(v);
	return 0;
}

void print(const std::vector<size_t>& v) // show
{
	for (double i : v)
		std::cout << i;
	std::cout << "\n";
}