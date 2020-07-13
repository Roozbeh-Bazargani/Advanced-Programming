#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<numeric>

double myrandom(); // random numbers
struct Avg //functor
{
	Avg(double avg) : a{ avg } {}
	bool operator() (const double& x, const double& y) { return std::abs(x - a) < std::abs(y - a); }
	double a;
};

void print(const std::vector<double>&); // show

int main()
{
	std::vector<double> v(100); // making vector
	std::generate(v.begin(), v.end(), []() mutable { return myrandom(); }); // filling vector
	std::cout << "Raw vector:\n";
	print(v);

	std::random_shuffle(v.begin(), v.end()); // random shuffle
	std::cout << "Shuffled vector:\n";
	print(v);

	double avg{ std::accumulate(v.begin(), v.end(), 0.) / 100 }; // average
	Avg davg{ avg };

	std::sort(v.begin(), v.end(), davg); // sort by avg
	std::cout << "Sorted vector:\n";
	print(v);

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