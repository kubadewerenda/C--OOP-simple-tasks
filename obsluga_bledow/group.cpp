#include "group.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void Grupa::dodajStudenta(const Student& student) 
{
    for (size_t i = 0; i < studenci.size(); ++i) 
	{
        if (studenci[i].pobierzNumerIndeksu() == student.pobierzNumerIndeksu()) 
		{
            throw invalid_argument("Student o tym samym numerze indeksu ju¿ istnieje w grupie.");
        }
    }
    studenci.push_back(student);
}

void Grupa::usunStudenta(int numerIndeksu) 
{
    vector<Student>::iterator it = studenci.begin();
    while (it != studenci.end()) 
	{
        if(it->pobierzNumerIndeksu() == numerIndeksu) 
		{
            it = studenci.erase(it);
        } else 
		{
            ++it;
        }
    }
}

void Grupa::wyswietlInformacjeGrupy() const 
{
    cout<<"----Dane Grupa----\n";
    for(size_t i = 0; i < studenci.size(); ++i) 
	{
        studenci[i].wyswietlInformacje();
    }
}

