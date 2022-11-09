#include "wartosc_liczbowa.h"
#include <iostream>


using namespace std;
Liczba::Liczba(double re)
{
	cout << "Konstruktor Liczba = " << re << "\n";
	this->re = re;
}
Liczba::~Liczba(void)
{
	cout << this->re << endl;
	// TODO 1
}
double Liczba::modul()
{
	if (re > 0)
	{
		return re;
	}
	return -re;
	//return re > 0 ?re : -re;
	//TODO 2
}
std::ostream & operator<<(std::ostream &out, Liczba &l)
{
	out << "Liczba rzeczywista: " << l.re << "\n";
	return out;
}