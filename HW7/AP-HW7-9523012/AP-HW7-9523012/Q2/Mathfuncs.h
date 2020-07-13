#pragma once
#include<string>

// export dll
extern "C" {
	__declspec(dllexport) char* Fibonacci(int);
}



class mathfunc
{
public:
	mathfunc(int);
	char* Fibonacci(); 
	std::string add(std::string , std::string); // add large numbers
private:
	int n;
};