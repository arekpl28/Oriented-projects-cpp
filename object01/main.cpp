#include <iostream>

using namespace std;

class Animal
{
  // atrybutu
public:
  string species;
  string name;
  int age;

  // metody

  void add_animal()
  {
    cout << "ADDING A NEW ANIMAL TO THE BASE" << endl;
    cout << "Enter the species: ";
    cin >> species;
    cout << "Give the name to animal: ";
    cin >> name;
    cout << "Give animal age: ";
    cin >> age;
  }

  void give_voice()
  {
    if (species == "cat")
    {
      cout << name << " age " << age << ": Miau!";
    }
    else if (species == "dog")
    {
      cout << name << " age " << age << ": HouHou!";
    }
    else if (species == "cow")
    {
      cout << name << " age " << age << ": Muuu!";
    }
    else
    {
      cout << "Unknown species";
    }
  }
};

int main()
{

  Animal anml1;
  anml1.add_animal();
  anml1.give_voice();

  Animal anml2;
  anml2.add_animal();
  anml2.give_voice();
  return 0;
}