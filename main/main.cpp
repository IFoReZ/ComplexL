#include <iostream>
#include "Complex.h"

int main()
{

  Complex<double> c1(4, 4);
  Complex<double> c2(2, 0);

  Complex<double> res;

  res = c1 + c2;
  std::cout << "Sum: " << c1 << " + " << c2 << " = " << res << std::endl;

  res = c1 - c2;
  std::cout << "Sub: " << c1 << " - " << c2 << " = " << res << std::endl;

  res = c1 * c2;
  std::cout << "Mult: " << c1 << " * " << c2 << " = " << res << std::endl;

  res = c1 / c2;
  Complex<double> a(0, 0);

  if (c2 != a)
  {
    std::cout << "Div: " << c1 << " / " << c2 << " = " << res << std::endl;
  }



  return 0;
}