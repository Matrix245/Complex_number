#pragma once
#include <vector>

/**
* |erstellen eines Datentyps Komplex das ermöglicht Komplexe Zahlen in der
*  Form von (Realteil Imaginärteil) zu speichern
*
*Mit Komplex kann man Realteil und Imaginärteil eingeben und diese zurückgeben
*oder auch neu setzen. Man kann Komplexe Zahlen miteinander addieren und multiplizieren
*und man kann auch mit einer Skalaren und Komplexen Zahl multiplizieren.
*Desweiteren kann man Komplexe Zahlen ausgeben oder auch eingeben.
*
*@author: Safeaulah Berhan
*/
class Komplex
{
  private:
    double realT; // ist der Realteil
    double imagT; // ist der Imaginärteil

  public:
    //@brief: (Konstruktor) erzeugt eine Komplexe Zahl mit den Werten 0 für realteil und imaginärteil
    //@parameter: keine | @return: keine
    Komplex();

    //@brief: (Konstruktor) durch eingabe des Realteil und Imaginärteil wird die Komplexe Zahl erzeugt
    //@parameter: r -> nimmt den Realteil | i -> nimmt den Imaginärteil
    //@return: keine
    Komplex(double r, double i);


    //@brief: gibt Realteil aus
    //@parameter: keine | @return: gibt den Realteil wieder (realT)
    double getRealT() const;

    //@brief: gibt Imaginaerteil aus
    //@parameter: keine | @return gibt den Imaginaerteil wieder (imagT)
    double getImagT() const;

    //@brief: Setzt neue Zahlen für den Imaginaerteil und Realteil ein
    //@parameter: double r ist der Realteil und double i ist der Imaginaerteil | @return: keine zurückgabe
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
    Komplex operator*(double rhs);
    Komplex operator* (long int& rhs);

    //@brief: überladen des << operator um eine Komplexe Zahl in der consol auszugeben
    //@parameter: stream ist der Ausgabestrom und output ist die zu darstellende Komplexe Zahl
    //@return: gibt die Komplexe Zahl in der Form ( Realteil Imaginaerteil ) an
    friend std::ostream& operator<< (std::ostream& stream, const Komplex& output );

    //@brief: überladen des >> operator um eine Komplexe Zahl ein zu geben in der Form Realteil Imaginaerteil
    //@parameter: stream ist der Eingabestrom und input enthält die eingegebene Komplex Zahl
    //@return: es wird das Eingegebene zurück gegeben (stream)
    friend std::istream& operator>> (std::istream& stream, Komplex& input );

    //@brief: die Komplexe Zahl wird in die Polarkoordinaten umgerechnet und in der Form r*(cos(alpha) + i*sin(alpha))
    //        angezeigt
    //@return: hat kein Rückgabewert
    void Polardarstellung();

};

/**
* |erstellen eines Datentyp KomplexND, der ein Vektor aus N Komplexen Zahlen
*  enthält
*Man kann auf die einzelen Felder von KomplexND zugreifen und die gespeicherte
*Komplexe Zahl zurückgeben. Weiterhin kann man die Anzahl der Element des
*Vektors zurück geben. Es ist auch möglich zwei Vektoren zu addieren.
*
*@author: Safeaulah Berhan
*/
class KomplexND
{
  private:
    unsigned long int size; // hält die anzahl der Element im Vektor
    std::vector<Komplex> vektorK; // ist der Vektor der Komplexe Zahlen enthält

  public:
    //@brief: (Konstruktor) Es wird die Größe des Vektors Eingegeben und der Nullvektor der Komplexen Zahlen erzeugt
    //        d.h. alle Element im Vektor ist die Komplex(0,0)
    //@parameter: s ist eine ganzzahl die für die größe des Vektors steht
    KomplexND(unsigned long int s);

    //@brief: (Konstruktor) Nimmt ein dynamisches Feld aus Komplexen Zahlen und initialisiert die size und vektorK
    //@parameter: v ist ein std::vector mit dem Datentyp Komplex (enthält nur Komplexe Zahlen) und stellt den Vektor dar
    KomplexND(std::vector<Komplex>v);

    //@brief: greift auf einen Index im Feld vektorK zu
    //@parameter: i -> ist der Index auf dem man zugreifen möchte
    //@return: gibt die Komplex Zahl zurück die indiesem index gespeichert ist
    Komplex atK(unsigned long int i);

    //@brief: gibt an wie viele Element der vektorK enthält
    //@parameter: keine
    //@return: gibt die size zurück -> enthält die anzahl an Elementen
    unsigned long int Size();

    //@brief: überladen des + operators um zwei KomplexND mit einander zu addieren
    //@parameter: rhs -> der rechte summand der addition und rhs ist ein KomplexND
    //@return: gibt das berechnete Ergebnis der beiden Vektoren als KomplexND zurück
    KomplexND operator+(KomplexND rhs);
};

/**
* |ist eine leere Klasse die nur für die Fehlerbehandlung benutzt wurde
*soll vorallem für fehler verwendet werden die außerhalb des definierten bereiches
*gelangen
*
*@author: Safeaulah Berhan
*/
class out_of_rang{};
