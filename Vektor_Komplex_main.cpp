#include <iostream>
#include "Komplexe_Zahlen_head.hpp"
#include <vector>
#include <cmath>

int main()
{
  std::vector<Komplex> v1 = {Komplex(1,1),Komplex(2,2),Komplex(3,3)};
  std::vector<Komplex> v2 = {Komplex(4.2,4.2),Komplex(3.1,3.1),Komplex(8,8)};

  KomplexND a(v1);
  KomplexND b(v2);

  std::cout << "Darstellung des Vektors a und des Vektors b mit Komplexen Zahlen\n" << std::endl;
  for(unsigned long int i = 0; i < a.Size();i++)
  {
    std::cout << "Vektor Angabe mit Indexzugriff: " << a.atK(i) << " |a.atK( " << i << " )|" << std::endl;
  }
  std::cout << "\n"<<std::endl;

  for(unsigned long int i = 0; i < b.Size();i++)
  {
    std::cout << "Vektor Angabe mit Indexzugriff: " << b.atK(i) << " |a.atK( " << i << " )|" << std::endl;
  }

  std::cout << "\nAngabe der a.Size() Funktion: " << a.Size() << std::endl;

  std::cout << "\nAddition der Vektoren a und b mit Angabe iherer einzelnen Elemente\n" << std::endl;
  KomplexND c = KomplexND(a + b);

  for(unsigned long int i = 0; i < c.Size();i++)
  {
    std::cout << "Element " << i+1 << ": " << c.atK(i) << std::endl;
  }

  KomplexND d(2);

  std::cout << "\nZuweisung des Konstruktors mit einer Integer Zahl 2 (KomplexND d(2))\n" << std::endl;

  for(unsigned long int i = 0; i < d.Size();i++)
  {
    std::cout << "Element " << i+1 << ": " << d.atK(i) << std::endl;
  }

  std::cout << "\n\nFehlermeldung wenn man KomplexND mit einer negativen Zahl initialisiert |KomplexND fehler(-2)|\n"<< std::endl;
  KomplexND fehler(-2);

  std::cout << "\n\nFehlermeldung bei atK() wenn es außerhalb des Index ist" << std::endl;
  std::cout << a.atK(3) << std::endl;

  b = KomplexND(4);

  std::cout << "\n\nFehlermeldung bei Addition wenn die Felder eine unterschiedliche size hat a.Size() = 3 u. b.Size() = 4" << std::endl;
  a+b;
  std::cout << "\n" ;
  return 0;
}
