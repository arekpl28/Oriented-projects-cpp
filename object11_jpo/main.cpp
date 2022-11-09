#include <iostream>
using namespace std;
class Wartosc_Liczbowa
{
public:
  virtual double modul() = 0; // wartość bezwzględna
  virtual void wypisz(std::ostream &out) = 0;
  virtual ~Wartosc_Liczbowa() {}
};

class Liczba : public Wartosc_Liczbowa
{
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
Liczba::Liczba(double re)
{
  cout << "Konstruktor Liczba = " << re << "\n";
  this->re = re;
}
Liczba::~Liczba(void)
{
  cout << re << endl;
  // TODO 1
}
double Liczba::modul()
{
  if (re > 0)
  {
    return re;
  }
  return -re;
  // return re > 0 ? re : -re;
  //  TODO 2
}
std::ostream &operator<<(std::ostream &out, Liczba &l)
{
  out << "Liczba rzeczywista: " << l.re << "\n";
  return out;
}

int mian()
{
  Liczba liczba1(1.3);
  Liczba liczba2(3.4);
  Liczba liczba(-5.6);

  return 0;
}