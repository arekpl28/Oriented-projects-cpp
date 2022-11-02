#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "question.h"

using namespace std;

void Question::load()
{
  fstream plik;
  plik.open("guiz.txt", ios::in);

  if (plik.good() == false)
  {
    cout << "The file could not be opened";
    exit(0);
  }
  int line_number = (nr_question - 1) * 6 + 1;
  int current_number = 1;
  string line;

  while (getline(plik, line))
  {
    if (current_number == line_number)
      content = line;
    if (current_number == line_number + 1)
      a = line;
    if (current_number == line_number + 2)
      b = line;
    if (current_number == line_number + 3)
      c = line;
    if (current_number == line_number + 4)
      d = line;
    if (current_number == line_number + 5)
      correct = line;
    current_number++;
  }
  plik.close();
}

void Question::ask()
{
  cout << endl
       << content << endl;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << d << endl;
  cout << "------------------------" << endl;
  cout << endl
       << "Answer: ";
  cin >> answer;
}

void Question::check()
{
  if (answer == correct)
  {
    point = 1;
  }
  else
    point = 0;
}