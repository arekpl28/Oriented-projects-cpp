#include <iostream>

using namespace std;

class Event
{
private:
  int day, mounth, year;
  int hour, minutes;
  string name;

public:
  Event(string = "none", int = 1, int = 1, int = 2022, int = 12, int = 0);
  ~Event();

  void load();
  void show();
};