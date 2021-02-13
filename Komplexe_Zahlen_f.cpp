#include <iostream>
#include <cmath>
#include <vector>
#include "Komplexe_Zahlen_head.hpp"

Komplex::Komplex()
{
  realT = 0.0;
  imagT = 0.0;
}

Komplex::Komplex(const double& r,const double& i)
{
  realT = r;
  imagT = i;
}



double Komplex::getRealT() const
{
  return realT;
}

double Komplex::getImagT() const
{
  return imagT;
}

void Komplex::setKomplex(const double& r, const double& i)
{
  realT = r;
  imagT = i;
}

Komplex Komplex::operator+(const Komplex& rhs)
{

  return Komplex(realT + rhs.getRealT(),imagT + rhs.getImagT());
}

Komplex Komplex::operator*(const Komplex& rhs)
{
  double realErg = (realT*rhs.getRealT()) - (imagT*rhs.getImagT());
  double imagErg = (realT*rhs.getImagT()) + (rhs.getRealT()*imagT);
  return Komplex(realErg,imagErg);
}

Komplex Komplex::operator*(const double& rhs)
{
  return Komplex(realT*rhs,imagT*rhs);
}

Komplex Komplex::operator*(const int& rhs)
{
  return Komplex(realT*rhs,imagT*rhs);
}


std::ostream& operator<< (std::ostream& stream, const Komplex& output )
{

  stream <<"( " << output.getRealT() << " " << output.getImagT() << " )";
  return stream;
}

std::istream& operator>> (std::istream& stream, Komplex& input )
{
  //Fehlermeldung wenn es keine Double zahl ist (buchstaben Sonderzeichen Steuerzeichen Satzzeichen ungültig)
  //ich habe hier keine Fehlermeldung gemacht weil mein System nicht abstürtzt
  //PS: wollte es versuchen aber konnte ich leider nicht umsetzen weil ich nicht wusste wie ich die
  //Datentypen vergleich soll.
  stream >>input.realT >> input.imagT;
  return stream;
}

void Komplex::Polardarstellung()
{
  double Betrag = std::sqrt(std::pow(realT,2) + std::pow(imagT,2));
  double Winkel_Bogenm = 0.0;

  if(realT > 0 && imagT > 0)
  {
      Winkel_Bogenm = atan(imagT/realT);
  }

  else if(realT < 0 && imagT > 0)
  {
    Winkel_Bogenm = M_PI + atan(imagT/realT);
  }

  else if(realT < 0 && imagT < 0)
  {
    Winkel_Bogenm = M_PI - atan(imagT/realT);
  }

  else if(realT > 0 && imagT < 0)
  {
    Winkel_Bogenm = (2*M_PI) + atan(imagT/realT);
  }

  std::cout << Betrag << "(" << "cos(" << Winkel_Bogenm << ")" << " + "
  << "i" << "sin(" << Winkel_Bogenm << "))";
}

KomplexND::KomplexND(const unsigned long int& s)
{
  //Fehlermeldung wenn s eine negative Zahl ist
  try
  {
    size = s;
    std::vector<Komplex>v(s,Komplex(0,0));
    vektorK = v;
  }

  catch(std::bad_alloc)
  {
    std::cout << "Initialisierung von KomplexND stimmt nicht. Bitte überprüfen"<<std::endl;
  }
}

KomplexND::KomplexND(const std::vector<Komplex>&v)
{
  size = v.size();
  vektorK = v;
}


Komplex KomplexND::atK(const unsigned long int& i)
{
  //Fehlermeldung wenn es außerhalb des index ist
  try{
    if(i > size-1 || i < (size-size))
    {
      throw out_of_rang();
    }

    else
    {
      return vektorK[i];
    }

  }
  catch(out_of_rang)
  {
    std::cout << "\nIndex außerhalb der Vektorgröße ";
  }
  return Komplex(0,0);
}

unsigned long int KomplexND::Size() const
{
  return size;
}

KomplexND KomplexND::operator+(KomplexND rhs)
{
  //Fehlermeldung wenn size nicht übereinstimmt mit rhs.Size() und siz
  try
  {
    if(rhs.Size() != size)
    {
      throw out_of_rang();
    }
    std::vector<Komplex> Erg(size);
    for(unsigned long int i = 0; i < size;i++)
    {
      Erg.at(i) = vektorK[i] + rhs.atK(i);
    }

    return KomplexND(Erg);
  }

  catch(out_of_rang)
  {
    std::cout << "\nDie Vektorgröße der Vektoren stimmen nicht überein ";
  }
  return KomplexND(1);
}
