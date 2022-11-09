#include "complex.h"
#include <iostream>

using namespace std;

Complex::~Complex()
{
	cout << "Destruktor realis: " << this->re << ", imaginalis: " << this->im << endl;
}
Complex::Complex(double re, double im) 
{
	this->re = re;
	this->im = im;
}

Complex Complex::operator +(Complex & right) 
{
	return Complex(this->re + right.re, this->im + right.im);
}

double Complex::modul()
{
	return sqrt(im * im + re * re);
}

std::ostream & operator<< (std::ostream & out, Complex & num)
{
	out << "realis: " << num.re << ", imaginalis: " << num.im << endl;
	return out;
}