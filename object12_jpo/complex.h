#pragma once
#include "wartosc_liczbowa.h"
#include <ostream>


class Complex : public Wartosc_Liczbowa
{
protected:
	double re;
	double im; //czesc urojona
public:
	~Complex();
	Complex(double re = 0, double im = 0);
	Complex operator+ (Complex &);
	friend std::ostream & operator<< (std::ostream &out, Complex &l);
	double modul();
	void wypisz(std::ostream &out)
	{
		out << *this;
	}
};

