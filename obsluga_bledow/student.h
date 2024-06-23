#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
	public:
	    Student(const std::string& imie, const std::string& nazwisko, int numerIndeksu);
	    void dodajOcene(double ocena);
	    double obliczSrednia() const;
	    void wyswietlInformacje() const;
	    int pobierzNumerIndeksu() const; 
	
	private:
	    std::string imie;
	    std::string nazwisko;
	    int numerIndeksu;
	    std::vector<double> oceny;
};

#endif

