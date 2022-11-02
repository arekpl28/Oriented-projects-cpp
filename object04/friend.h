#include <iostream>

using namespace std;

class Rectangle;

class Point
{
  string name;
  float x, y;

public:
  Point(string = "A", float = 0.0, float = 0.0);
  void write();
  friend void judge(Point pkt, Rectangle rec);
};

class Rectangle
{
  float x, y, width, height;
  string name;

public:
  Rectangle(string = "none", float = 0, float = 0, float = 1, float = 1);
  void write();
  friend void judge(Point pkt, Rectangle rec);
};