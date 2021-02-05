#include <iostream>
#include <cmath>
#include "Komplexe_Zahlen_head.hpp"

Komplex::Komplex()
{
  realT = 0.0;
  imagT = 0.0;
}

Komplex::Komplex(double r, double i)
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

void Komplex::setKomplex(double r, double i)
{
  realT = r;
  imagT = i;
}

Komplex Komplex::operator+(Komplex rhs)
{

  return Komplex(realT + rhs.getRealT(),imagT + rhs.getImagT());
}

Komplex Komplex::operator*(Komplex rhs)
{
  double realErg = (realT*rhs.getRealT()) - (imagT*rhs.getImagT());
  double imagErg = (realT*rhs.getImagT()) + (rhs.getRealT()*imagT);
  return Komplex(realErg,imagErg);
}

Komplex Komplex::operator*(double rhs)
{
  return Komplex(realT*rhs,imagT*rhs);
}

std::ostream& operator<< (std::ostream& stream, const Komplex& output )
{
  stream.precision(2);
  stream << std::showpoint <<"( " << output.getRealT() << " " << output.getImagT() << " )";
  return stream;
}

std::istream& operator>> (std::istream& stream, Komplex& input )
{
  return stream >> input.realT >> input.imagT;
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
  << "i" << "sin(" << Winkel_Bogenm << "))" << std::endl; 
}
