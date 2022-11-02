#include <iostream>
#include "friend.h"

using namespace std;

void judge(Point pkt, Rectangle rec)
{
  if (pkt.x >= rec.x && (pkt.x <= rec.x + rec.width) && (pkt.y >= rec.y) && (pkt.y <= rec.height))
  {
    cout << endl
         << "Point " << pkt.name << " belongs to the rectangle: " << rec.name << endl;
  }
  else
  {
    cout << endl
         << "Point " << pkt.name << " lies outside the rectangle: " << rec.name << endl;
  }
}

int main()
{
  Point p1("A", 3, 17);

  Rectangle r1("Prostokat", 0, 0, 6, 4);

  judge(p1, r1);

  return 0;
}