#include "student.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Student::Student(const string& imie, const string& nazwisko, int numerIndeksu)
    : imie(imie), nazwisko(nazwisko), numerIndeksu(numerIndeksu) {}

void Student::dodajOcene(double ocena) 
{
    if (ocena >= 2.0 && ocena <= 5.0) 
	{
        oceny.push_back(ocena);
    } else 
	{
        throw invalid_argument("Nieprawidlowa wartosc oceny. (2.0-5.0)");
    }
}

double Student::obliczSrednia() const
{
    double suma = 0.0;
    for (size_t i = 0; i < oceny.size(); ++i) 
	{
        suma += oceny[i];
    }
    return (oceny.empty()) ? 0.0 : suma / oceny.size();
}

void Student::wyswietlInformacje() const 
{
    cout << "Student: " << imie << " " << nazwisko << " (Numer indeksu: " << numerIndeksu << ")\n";
    cout << "Oceny:";
    for (size_t i = 0; i < oceny.size(); ++i) 
	{
        cout << " " << oceny[i];
    }
    cout << "\n";
}

int Student::pobierzNumerIndeksu() const 
{
    return numerIndeksu;
}

