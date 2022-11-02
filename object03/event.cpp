#include <iostream>
#include "event.h"

using namespace std;

void Event::load()
{
  cout << "Nazwa wydarzenia: ";
  cin >> name;
  cout << "Dzien: ";
  cin >> day;
  cout << "Miesiac: ";
  cin >> mounth;
  cout << "Rok: ";
  cin >> year;
  cout << "Godzina: ";
  cin >> hour;
  cout << "Minuta: ";
  cin >> minutes;
}

void Event::show()
{
  cout << endl
       << name << " " << day << "." << mounth << "." << year << " " << hour << ":" << minutes << endl;
}

Event::Event(string n, int d, int m, int y, int h, int mins)
{
  name = n;
  day = d;
  mounth = m;
  year = y;
  hour = h;
  minutes = mins;
}

Event::~Event()
{
  cout << endl
       << "Destructor" << endl;
}