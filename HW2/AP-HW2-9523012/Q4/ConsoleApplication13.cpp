#include "stdafx.h"

#include<iostream>
#include<vector>

void sort(std::vector<double> &);
void show(const std::vector<double> &);
void swap(std::vector<double> &, size_t, size_t);

int main()
{
	double x{ 1 };
	std::vector<double> v{};
	std::cout << "Enter numbers for sorting: ";
	while (1)
	{
		std::cin >> x;
		if (x == 0)
			break;
		v.push_back(x);
	}

	sort(v);
	show(v);
    return 0;
}

void sort(std::vector<double> &v)
{
	size_t min{};
	for (size_t i{}; i < v.size(); i++)
	{
		min = i;
		for (size_t j{ i + 1 }; j < v.size(); j++)
		{
			if (v[j] < v[min])
				min = j;
		}
		swap(v, i, min);
	}
}

void show(const std::vector<double> &v)
{
	for (double x : v)
		std::cout << x << " ";
	std::cout << "\n";
}

void swap(std::vector<double> &v, size_t a, size_t b)
{
	double c{ v[a] };
	v[a] = v[b];
	v[b] = c;
}