#include"RationalNumber.h"

using std::cout;
using std::endl;

int main()
{
	RationalNumber a{ 7, 3 }, b{ 3, 9 }, x;
	RationalNumber c = a;
	c.show();
	cout << '\n';
	a.show();
	cout << " + ";
	b.show();
	cout << " = ";
	//x = a + b;
	//x = a - b;
	//x = a * b;
	x = a / b;
	x.show();
	cout << '\n';
	a.show();
	cout << " is:\n";
	cout << ((a > b) ? " > " : " <= ");
	b.show();
	cout << " according to the overloaded > operator\n";
	cout << ((a != b) ? " != " : " == ");
	b.show();
	cout << " according to the overloaded != operator" << endl;
	return 0;
}
