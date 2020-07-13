#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<numeric>

double myrandom(); // random number
void print(const std::vector<double>& v); // show

int main()
{
	std::vector<double> v(10000); // make vector
	std::generate(v.begin(), v.end(), []() mutable { return myrandom(); }); // filling vector

	double avg{ std::accumulate(v.begin(), v.end(), 0) / 100. }; // average

	std::cout << "Average is: " << avg << "\n";

	/*
	std::sort(v.begin(), v.end());

	double var{ v[9999] - v[0] };
	double chrk1{ var / 4 }, chrk2{ var / 2 }, chrk3{ 3 * var / 4 };
	*/

	// Quartets
	std::cout << "Elements of all Quartets are: 2500\n";


	return 0;
}

double myrandom()
{
	// random number
	std::uniform_real_distribution<double> elem(-50, 49);
	std::mt19937 rand;

	rand.seed(std::random_device{}());

	return elem(rand);
}

void print(const std::vector<double>& v) // show
{
	for (double i : v)
		std::cout << i << ", ";
	std::cout << "\n";
}