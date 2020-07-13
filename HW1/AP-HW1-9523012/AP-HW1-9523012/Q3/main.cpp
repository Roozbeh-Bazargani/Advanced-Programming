#include<iostream>

int main()
{
  //objects for getting numbers
  int n{};
  std::cout << "Enter n: ";
  std::cin >> n;
  std::cout << "Enter n numbers: ";
  long double sum{}, x{};
  for (int i{}; i < n; i++)
    {
      //getting numbers
      std::cin >> x;
      //calculating answer by mathematic formulas
      sum += x * (n - i) * (i + 1);
    }
  //print answer
  std::cout << "Ans = " << sum << std::endl;
  return 0;
}
