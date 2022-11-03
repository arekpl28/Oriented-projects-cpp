#include <iostream>
#include <conio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.1415926535897932384626433
#endif

using namespace std;

class Punkt
{
  float x, y;
  string nazwa;

public:
  void wyswietl()
  {
    cout << nazwa << "(" << x << ", " << y << ")" << endl;
  }

  Punkt(string n = "s", float a = 0, float b = 0)
  {
    nazwa = n;
    x = a;
    y = b;
  }
};

class Kolo : public Punkt
{
  float r;
  string nazwa;

public:
  void wyswietl()
  {
    cout << "Kolo o nazwie: " << nazwa << endl;
    cout << "Srodek kola: " << endl;
    Punkt::wyswietl();
    cout << "Promien: " << r << endl;
    cout << "Pole kola: " << M_PI * r * r << endl;
  }

  Kolo(string nk = "Kolko", string np = "S", float a = 0, float b = 0, float pr = 1)
      : Punkt(np, a, b)
  {
    nazwa = nk;
    r = pr;
  }
};

int main()
{
  Kolo k1;
  k1.wyswietl();

  return 0;
}