#include <iostream>
#include "wartosc_liczbowa.h"
#include "complex.h"

using namespace std;

int main()
{
	Wartosc_Liczbowa * liczby[3];
	liczby[0] = new Liczba(10);
	liczby[1] = new Complex(11, -10);
	liczby[2] = new Complex(-10, 12.4);

	for (int i = 0; i < 3; i++)
	{
		liczby[i]->modul();
		(*liczby[i]).wypisz(cout);
	}

	/*
		Liczba liczba1(1.3);
		Liczba liczba2(3.4);
		Liczba liczba3(-5.6);

		cout << "liczba 1 modulo: " << liczba1.modul() << endl;
		cout << "liczba 3 modulo: " << liczba3.modul() << endl;

		Liczba liczba4 = liczba1 + liczba2;
		cout << "liczba 4 modulo: " << liczba4.modul() << endl;

		Complex c1(2, 2);
		Complex c2(3, 1);
		Complex c3 = Complex();

		Complex c4 = c2 + c1;

		cout << "main c4: " << c4 << "c1: " << c1;
		*/
	return 0;
}