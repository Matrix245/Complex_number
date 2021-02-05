#include <iostream>
#include <cmath>
#include "Komplexe_Zahlen_head.hpp"

int main()
{
  Komplex a;
  Komplex b(2.0, 5.26);
  Komplex c;
  double r;



  std::cout << "Komplex Zahl a: " << a << std::endl;
  std::cout << "Komplex Zahl b: " << b << std::endl;
  std::cout << "Komplex Zahl c: " << c << std::endl;
  b.Polardarstellung();
  return 0;
}
