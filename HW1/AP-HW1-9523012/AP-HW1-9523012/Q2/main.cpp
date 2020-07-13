#include<iostream>
#include<iomanip>
#include<cmath>

double f1(double x); //x^3+x^2+x+1
double f2(double x); //coth(x)+log(x)

int main()
{
  //declaring objects
  double x1{ 0 }, x2{ 1 }, xnew{}, e{ 1 }, d{ 1e-4 };

  //For showing only 6 digits
  std::cout.precision(6);
  //secant for x^3+x^2+x+1
  std::cout << "1) f=x^3+x^2+x+1\nIter\t\t xold\t\t xnew\t\t f(xnew)\t\t e\n";
  for (int i{}; e > d ; i++)
    {
      xnew = x2 - f1(x2)*(x2 - x1) / (f1(x2) - f1(x1));
      e = fabs((xnew - x2) / x2);
      std::cout  << std::setw(3) << i + 1 << std::setw(20) 
		 << x2 << std::setw(16)  << xnew
		 << std::setw(18)  << f1(xnew)
		 << std::setw(20)  << e << std::endl;
      x1 = x2;
      x2 = xnew;
    }
  std::cout << "Root of x^3+x^2+x+1 is: " << xnew << std::endl;

  //secant for coth(x)+log(x)
  std::cout << "\nEnter first and second starting numbers and precision: ";
  std::cin >> x1 >> x2 >> d;
  //error for new variables
  e = fabs((xnew - x2) / x2);
  
  std::cout << "1) f=coth(x)+log(x)\nIter\t\t xold\t\t xnew\t\t f(xnew)\t\t e\n";
  for (int i{}; e > d ; i++)
    {
      xnew = x2 - f2(x2)*(x2 - x1) / (f2(x2) - f2(x1));
      e = fabs((xnew - x2) / x2);
       std::cout  << std::setw(3) << i + 1 << std::setw(20) << x2 << std::setw(16)
		 << xnew << std::setw(18) << f2(xnew)
		 << std::setw(20) << e << std::endl;
      x1 = x2;
      x2 = xnew;
    }
  std::cout << "Root of coth(x)+log(x) is: " << xnew << std::endl;
  return 0;
}

double f1(double x) //x^3+x^2+x+1
{
  return (pow(x,3) + pow(x,2) + x + 1);
}

double f2(double x) //coth(x)+log(x)
{
  return 1./tanh(x) - log10(x);
}
