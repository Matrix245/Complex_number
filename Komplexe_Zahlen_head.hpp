#pragma once
#include <vector>

class Komplex
{
  private:
    double realT;
    double imagT;

  public:
    //Konstruktor ohne parametern
    Komplex();
    //Konstruktor überladen mit parametern
    Komplex(double r, double i);


    //@brief: gibt Realteil aus / @return Realteil(realT)
    double getRealT() const;

    //@brief: gibt Imaginaerteil aus / @return Imaginaerteil(imagT)
    double getImagT() const;

    //@brief: Setzt neue Zahlen für den Imaginaerteil und Realteil ein
    //@parameter: double r ist der Realteil und double i ist der Imaginaerteil
    void setKomplex(double r, double i);

    //@brief: ueberlaede den + operator um damit Komplexe Zahlen zu addieren
    //@paramert: Komplex rhs = nimmt die zu addierende Komplexe Zahl
    //@return: gibt das Ergebnis der Addition vom Realteil und Imaginaerteil als Komplexe
    //Zahl zurueck
    Komplex operator+(Komplex rhs);

    //@brief: ueberladen des * operator um damit mit Komplexen Zahlen zu Multiplizieren
    //@paramert: Komplex rhs = nimmt die zu multiplizierende Komplexe Zahl
    //@return: gibt das Ergebnis der Multiplikation als Realteil und Imaginaerteil der Komplexen
    // Zahl zurueck
    Komplex operator*(Komplex rhs);

    //@brief: überladen des * operator um damit eine Komplexe Zahl mit einem Skalaren zu multiplizieren
    //@parameter: nimmt den zu Multiplizierenden Skalaren als Fließkommerzahl
    //@return: gibt das Ergebnis des Realteils und Imaginaerteils als Komplexe Zahl zurück
    Komplex operator*(double& rhs);

    friend std::ostream& operator<< (std::ostream& stream, const Komplex& output );
    friend std::istream& operator>> (std::istream& stream, Komplex& input );

    void Polardarstellung();

};

class KomplexND
{
  private:
    unsigned long int size;
    std::vector<Komplex> vektorK;

  public:
    KomplexND(unsigned long int s);

    KomplexND(std::vector<Komplex>v);

    Komplex atK(unsigned long int i);

    unsigned long int Size();

    KomplexND operator+(KomplexND rhs);
};

class out_of_rang{};
