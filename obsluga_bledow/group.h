#ifndef GROUP_H
#define GROUP_H

#include "student.h"
#include <vector>

class Grupa {
	public:
	    void dodajStudenta(const Student& student);
	    void usunStudenta(int numerIndeksu);
	    void wyswietlInformacjeGrupy() const;
	
	private:
	    std::vector<Student> studenci;
};

#endif

