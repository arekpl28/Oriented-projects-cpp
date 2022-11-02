#include <iostream>
#include "friend.h"

using namespace std;

Point::Point(string n, float xx, float yy)
{
  name = n;
  x = xx;
  y = yy;
}

void Point::write()
{
  cout << "Enter x: ";
  cin >> x;
  cout << "Enter y: ";
  cin >> y;
  cout << "Point name: ";
  cin >> name;
}

Rectangle::Rectangle(string n, float xx, float yy, float w, float h)
{
  name = n;
  x = xx;
  y = yy;
  width = w;
  height = h;
}

void Rectangle::write()
{
  cout << "Enter x of the left lower corner: ";
  cin >> x;
  cout << "Enter y of the left lower corner: ";
  cin >> y;
  cout << "Enter width: ";
  cin >> width;
  cout << "Enter height: ";
  cin >> height;
  cout << "Enter the name of the rectangle";
  cin >> name;
}