#include <iostream>
#include <cmath>
#include "Komplexe_Zahlen_head.hpp"

int main()
{
  Komplex a;
  std::cout << "a: " << a << std::endl;

  double r = 12.51;
  double i = 4.132;
  a.setKomplex(r,i);
  std::cout << "\na.setKomplex: "<< a << std::endl;

  Komplex b(28,19);
  std::cout << "\nb: " << b << std::endl;
  std::cout << "\n\na + b: " << a + b << std::endl;
  std::cout << "\na * b: " << a * b << std::endl;
  std::cout << "\nb * 2: " << b * 2 << " (int)" << std::endl;
  std::cout << "\nb * 12.51" << b*r << " (double)"<< std::endl;
  std::cout << "\nPolardarstellung von b: ";
  b.Polardarstellung();

  std::cout << "\n\n\ndie a.getRealT() Funktion: " << a.getRealT() << std::endl;
  std::cout << "\ndie a.getImagT() Funktion: " << a.getImagT() << std::endl;

  Komplex c;
  std::cout << "\n\nBitte geben sie ein Realteil und ein Imaginaerteil " << "\nfür die Komplexe Zahl ein: " ;
  std::cin >> c;
  std::cout << "\nIhre Eingabe: " << c << std::endl;

  return 0;
}
