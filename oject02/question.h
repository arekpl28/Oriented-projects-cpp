#include <iostream>

using namespace std;

class Question
{
public:
  string content;
  string a, b, c, d;
  int nr_question;
  string correct;
  string answer;
  int point; // 0 or 1

  void load(); // Load the question from the file

  void ask(); // shows the question, reads the answer

  void check(); // Checks the correctness of the answer.
};