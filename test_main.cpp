#include <iostream>
#include "Komplexe_Zahlen_head.hpp"
#include <vector>
#include <cmath>

class KomplexND
{
  private:
    std::vector<Komplex> Vektor;
  public:
    KomplexND(std::vector<Komplex> add);
    ~KomplexND();
    Komplex atVK(unsigned long int i);
    unsigned long int sizeVK();
};

KomplexND::KomplexND(std::vector<Komplex>add)
{
  Vektor = add;
}

KomplexND::~KomplexND(){}

Komplex KomplexND::atVK(unsigned long int i)
{
  //Fehlermeldung beachten
  return Vektor[i];
}

unsigned long int KomplexND::sizeVK()
{
  unsigned long int count = 0;

  for(Komplex x: Vektor)
    count++;
  return count;
}

int main()
{

  std::vector<Komplex> VE = {Komplex(1,1),Komplex(2,2),Komplex(3,3)};
  KomplexND h(VE);

  std::cout << h.atVK(1) << std::endl;


  return 0;
}
