#include "Mathfuncs.h"


mathfunc::mathfunc(int n)
{
	this->n = n;
}

char* mathfunc::Fibonacci(){ // calculating Fibonacci
	if (n < 2)
	{
		char* ch{ new char{'1'} };
		return ch;
	}
	std::string f1{ "0" }, f2{ "1" }, f3{ "0" };
	for (int i = 2; i <= n; i++) { // equation
		f3 = add(f1, f2);
		f1 = f2;
		f2 = f3;
	}
	char* ch{ new char[f3.size() + 1] };
	for (size_t i{}; i < f3.size(); i++)
	{
		ch[i] = f3[i];
	}
	ch[f3.size()] = NULL;
	return ch;
}

char* Fibonacci(int a)
{
	mathfunc x{ a };
	return x.Fibonacci();
}

std::string mathfunc::add(std::string str1, std::string str2)
{
	// find longer number
	if (str1.length() > str2.length())
		swap(str1, str2);

	std::string str = "";

	int n1 = str1.length(), n2 = str2.length();
	int diff = n2 - n1;

	int carry = 0; // carry number

	for (int i = n1 - 1; i >= 0; i--)
	{
		int sum = ((str1[i] - '0') +
			(str2[i + diff] - '0') +
			carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}
	for (int i = n2 - n1 - 1; i >= 0; i--)
	{
		int sum = ((str2[i] - '0') + carry);
		str.push_back(sum % 10 + '0');
		carry = sum / 10;
	}
	if (carry) // last number
		str.push_back(carry + '0');
	reverse(str.begin(), str.end());

	return str;
}