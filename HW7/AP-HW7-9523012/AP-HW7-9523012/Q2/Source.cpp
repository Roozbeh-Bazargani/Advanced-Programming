#include<iostream>
#include<chrono>
#include<fstream>
#include<string>

// import dll
extern "C" {
	__declspec(dllimport) char* Fibonacci(int);
}

int main()
{
	std::ifstream ifile{};
	std::ofstream of{};
	// read file
	ifile.open("Q2.txt");
	// open file for writing
	of.open("Fibonacci_C++_runtime.txt");

	int s{};
	// find time and run Fibonacci
	while (ifile >> s)
	{
		std::cout << s << ": ";
		auto t1{ std::chrono::high_resolution_clock::now() };
		std::cout << Fibonacci(s) << "\n";
		auto t2{ std::chrono::high_resolution_clock::now() };
		of << "Took(" << s << "): " << std::chrono::duration_cast<std::chrono::microseconds> (t2 - t1).count() << " microseconds\n";
	}

	ifile.close();
	of.close();
	return 0;
}