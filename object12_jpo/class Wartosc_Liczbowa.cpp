#include <iostream>

using namespace std;
Liczba::Liczba(double re)
{
  cout << "Konstruktor Liczba = " << re << "\n";
  this->re = re;
}
Liczba::~Liczba(void)
{
  // TODO 1
}

double Liczba::modul()
{
  // TODO 2
}
std::ostream &operator<<(std::ostream &out, Liczba &l)
{
  out << "Liczba rzeczywista: " << l.re << "\n";
  return out;
}