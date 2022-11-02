#include <iostream>
#include "question.h"
#include <string>
using namespace std;

int main()
{
  Question p[5];
  int suma = 0;
  for (int i = 0; i <= 4; i++)
  {
    p[i].nr_question = i + 1;
    p[i].load();
    p[i].ask();
    p[i].check();
    suma += p[i].point;
  }

  cout << "End of the quiz! Points = " << suma;

  return 0;
}