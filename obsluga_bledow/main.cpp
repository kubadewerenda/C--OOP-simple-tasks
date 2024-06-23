#include "student.h"
#include "group.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() 
{
    Grupa grupa;

    try 
	{
        Student student1("Jan", "Kowalski", 12345);
        student1.dodajOcene(4.0);
        student1.dodajOcene(3.5);
        grupa.dodajStudenta(student1);

        Student student2("Anna", "Markoni", 67890);
        student2.dodajOcene(3.8);
        student2.dodajOcene(4.2);
        grupa.dodajStudenta(student2);

        Student student3("Markos", "Stonoga", 12345);
        grupa.dodajStudenta(student3); 

        grupa.usunStudenta(55555); 
    } catch (const invalid_argument& e) 
	{
        cerr << "Blad: " << e.what() << endl;
    }

    grupa.wyswietlInformacjeGrupy();

    return 0;
}

