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
  std::cout << "\n\na + b: " << a + Komplex(28,19) << std::endl;
  std::cout << "\na * b: " << a * Komplex(28,19) << std::endl;
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

  std::cout << "\n-----------------------------------------------------------------------------------\n\n"<< std::endl;

  std::vector<Komplex> v1 = {Komplex(1,1),Komplex(2,2),Komplex(3,3)};
  std::vector<Komplex> v2 = {Komplex(4.2,4.2),Komplex(3.1,3.1),Komplex(8,8)};

  KomplexND vektor1(v1);
  KomplexND vektor2(v2);

  std::cout << "Darstellung des Vektors \"vektor1\" und des Vektors \"vektor2\" mit Komplexen Zahlen\n" << std::endl;
  for(unsigned long int j = 0; j < vektor1.Size();j++)
  {
    std::cout << "Vektor Angabe mit Indexzugriff: " << vektor1.atK(j) << " |vektor1.atK( " << j << " )|" << std::endl;
  }
  std::cout << "\n"<<std::endl;

  for(unsigned long int j = 0; j < vektor2.Size();j++)
  {
    std::cout << "Vektor Angabe mit Indexzugriff: " << vektor2.atK(j) << " |vektor2.atK( " << j << " )|" << std::endl;
  }

  std::cout << "\nAngabe der vektor1.Size() Funktion: " << vektor1.Size() << std::endl;

  std::cout << "\nAddition der Vektoren \"vektor1\" und \"vektor2\" mit Angabe iherer einzelnen Elemente\n" << std::endl;
  KomplexND vektor3 = KomplexND(vektor1 + vektor2);

  for(unsigned long int j = 0; j < vektor3.Size();j++)
  {
    std::cout << "Element " << j+1 << ": " << vektor3.atK(j) << std::endl;
  }

  KomplexND d(2);

  std::cout << "\nZuweisung des Konstruktors mit einer Integer Zahl 2 (KomplexND d(2))\n" << std::endl;

  for(unsigned long int j = 0; j < d.Size();j++)
  {
    std::cout << "Element " << j+1 << ": " << d.atK(j) << std::endl;
  }

  std::cout << "\n\nFehlermeldung wenn man KomplexND mit einer negativen Zahl initialisiert |KomplexND fehler(-2)|\n"<< std::endl;
  KomplexND fehler(-2);

  std::cout << "\n\nFehlermeldung bei atK() wenn es außerhalb des Index ist" << std::endl;
  std::cout << vektor1.atK(3) << std::endl;

  vektor2 = KomplexND(4);

  std::cout << "\n\nFehlermeldung bei Addition wenn die Felder eine unterschiedliche size hat vektor1.Size() = 3 u. vektor2.Size() = 4" << std::endl;
  vektor1+vektor2;
  std::cout << "\n" ;

  return 0;
}
