#include <iostream>

#pragma once

class Wartosc_Liczbowa
{
public:
	virtual double modul() = 0; // wartość bezwzględna
	virtual void wypisz(std::ostream &out) = 0;
	virtual ~Wartosc_Liczbowa()
	{
	}
};

class Liczba : public Wartosc_Liczbowa
{
private:
	double re; // czesc rzeczywista
public:
	Liczba operator+(Liczba &right)
	{
		return Liczba(this->re + right.re);
	}
	double modul();
	Liczba(double re);
	~Liczba(void);
	friend std::ostream &operator<<(std::ostream &out, Liczba &l);
	void wypisz(std::ostream &out)
	{
		out << *this;
	}
};
