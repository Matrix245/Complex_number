#include <iostream>
#include "Komplexe_Zahlen_head.hpp"
#include <vector>
#include <array>
#include <cmath>

class KomplexND
{
  private:
    unsigned long int size = 0;
    std::vector<Komplex> vektorK;

  public:
    KomplexND(unsigned long int s)
    {
      //Fehlermeldung bei size "s < 0 ?"
      size = s;
      std::vector<Komplex>v(s,Komplex(0,0));
      vektorK = v;
    }

    KomplexND(unsigned long int s, std::vector<Komplex> v)
    {
      //Fehlermeldung wenn es kein std::vector ist
      //Fehlermeldung wenn die size nicht mit v.size() übereinstimmt
      size = s;
      vektorK = v;
    }

    Komplex atK(unsigned long int i)
    {
      //Fehlermeldung "out of range"
      return vektorK[i];
    }

    unsigned long int Size()
    {
      return size;
    }

    KomplexND add(KomplexND lhs, KomplexND rhs)
    {
      std::vector<Komplex> Erg(size);
      for(unsigned long int i = 0; i < size;i++)
      {
        Erg.at(i) = lhs.atK(i) + rhs.atK(i);
      }

      return KomplexND(size,Erg);
    }
};

int main()
{
  KomplexND a(3,{Komplex(1,1),Komplex(2,2),Komplex(3,3)});
  KomplexND b(3,{Komplex(4,4),Komplex(5,5),Komplex(6,6)});
  KomplexND c(3);
  c = c.add(a,b);

  std::cout << c.atK(1) << std::endl;


  return 0;
}
