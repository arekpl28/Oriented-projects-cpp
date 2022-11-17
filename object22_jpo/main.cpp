#include <iostream>
#include <fstream>

using namespace std;

class VektorNd
{
  double *_liczby = nullptr; // pole ze wskaźnikiem liczb
  int _wymiar;               // wymiar wektora
public:
  VektorNd()
  {
    double liczby[] = {0};
    VektorNd(liczby, 1);
  }

  VektorNd(const double liczby[], int wymiar)
  { // konstruktor
    _liczby = new double[wymiar];
    _wymiar = wymiar;
    for (int i = 0; i < _wymiar; i++)
      _liczby[i] = liczby[i];
  }

  VektorNd(const VektorNd &oryginal)
  { // konstruktor kopiujący
    cout << "Wywołanie konstruktora kopjującego" << endl;
    _liczby = new double[oryginal._wymiar];
    _wymiar = oryginal._wymiar;
    for (int i = 0; i < _wymiar; i++)
      _liczby[i] = oryginal._liczby[i];
  }

  VektorNd &operator=(const VektorNd &right)
  { // implementacja operatora przypisania
    if (_wymiar != right._wymiar)
    { // gdy zgodne wymiary nie potrzeba realokować pamięci
      if (_liczby != nullptr)
        delete[] _liczby;
      _liczby = new double[right._wymiar]; // alokacja pamięci dla nowego wymiaru
      _wymiar = right._wymiar;
    }
    for (int i = 0; i < _wymiar; i++)
      _liczby[i] = right._liczby[i];
    return *this;
  }

  ~VektorNd()
  {
    cout << "zwalniam pamiec pod adresem: " << this << endl;
    delete[] _liczby;
  }

  void getCoefs(double liczby[])
  { // metoda publiczna
    for (int i = 0; i < _wymiar; i++)
      liczby[i] = _liczby[i];
  }

  double getCoef(int index)
  { // pomocznicza metoda
    return _liczby[index];
  }

  void setCoef(double wartosc, int index)
  {
    _liczby[index] = wartosc;
  }

  int getDim()
  { // pomocznicza metoda
    return _wymiar;
  }
  void wypisz(ostream &out = cout)
  {
    out << "|-------------------------BEGIN------------------------------ | " << endl;
    out << "Jestem wektorem pod adresem: " << this << endl;
    out << "Mój wymiar to: " << _wymiar << endl;
    out << "A elementy:" << endl;
    for (int i = 0; i < _wymiar; i++)
      out << "[" << i << "] = \t" << _liczby[i] << endl;
    out << "|--------------------------END------------------------------- | " << endl;
  }
  friend ostream &operator<<(ostream &left, VektorNd &right);
  // koniec VektorNd
};

ostream &operator<<(ostream &left, VektorNd &right)
{
  right.wypisz(left); // wolno wywołać gdyż operator jest friend
  return left;
}

class VectorOfVectors
{
private:
  VektorNd *_vektory;
  int size;

public:
  VectorOfVectors(VektorNd vektory[], int size)
  {
    _vektory = new VektorNd[size]; // tworzenie tablicy VektorNd
    (*this).size = size;
    for (int i = 0; i < size; i++)
    {
      _vektory[i] = vektory[i];
    }
  }

  VectorOfVectors(VectorOfVectors &vec)
  { // konstruktor kopiujący
    _vektory = new VektorNd[vec.size];
    this->size = vec.size;
    for (int i = 0; i < size; i++)
      _vektory[i] = vec._vektory[i];
  }

  VectorOfVectors &operator=(VectorOfVectors &vec)
  { // implementacja operatora przypisania
    if (size != vec.size)
    { // gdy zgodne wymiary nie potrzeba realokować pamięci
      delete[] _vektory;
      _vektory = new VektorNd[vec.size]; // alokacja pamięci dla nowego wymiaru
      size = vec.size;
    }
    for (int i = 0; i < size; i++)
      _vektory[i] = vec._vektory[i];
    return *this;
  }
  ~VectorOfVectors()
  {
    delete[] _vektory;
  }
  friend ostream &operator<<(ostream &out, VectorOfVectors &right);
};

ostream &operator<<(ostream &out, VectorOfVectors &right)
{
  for (int i = 0; i < right.size; i++)
  {
    out << right._vektory[i];
  }
  return out;
}
//////////////////////////////////////////////
// const int SIZE = 3;

// class VectorOfVectors
// {
// private:
//   VektorNd _wektory[SIZE];
//   int _size;

// public:
//   VectorOfVectors(VektorNd *tablica, int size = SIZE)
//   {
//     _size = size;
//     for (int i = 0; i < SIZE; i++)
//     {
//       _wektory[i] = tablica[i];
//     }
//   }

//   VectorOfVectors(VectorOfVectors &right)
//   //: VectorOfVectors(right._wektory, right._size)
//   {
//     _size = right._size;
//     for (int i = 0; i < SIZE; i++)
//     {
//       _wektory[i] = right._wektory[i];
//     }
//   }

//   VectorOfVectors &operator=(VectorOfVectors &right)
//   {
//     _size = right._size;
//     for (int i = 0; i < SIZE; i++)
//     {
//       _wektory[i] = right._wektory[i];
//     }

//     return *this;
//   }

//   ~VectorOfVectors()
//   {
//     cout << "Destruktor";
//   }

//   friend ostream &operator<<(ostream &out, VectorOfVectors &right);
// };
// ostream &operator<<(ostream &out, VectorOfVectors &right)
// {
//   for (int i = 0; i < SIZE; i++)
//   {
//     out << right._wektory[i];
//   }
//   return out;
// }
//////////////////////////////////////////////
/*
void wypisz(double tab[], int rozmiar) {
  for (int i = 0; i < rozmiar; i++)
    cout << tab[i] << '\t';
  cout << endl;
}

void wypiszV1(VektorNd v) {
  cout << "|----------BEGIN------------------------------|" << endl;
  cout << "Jestem wektorem pod adresem: " << &v << endl;
  int wymiar = v.getDim();
  cout << "Mój wymiar to: " << wymiar << endl;
  cout << "A elementy:" << endl;
  for (int i = 0; i < wymiar; i++)
    cout << "[" << i << "] = \t" << v.getCoef(i) << endl;
  cout << "|-----------END-------------------------------|" << endl;
}

void wypiszV2(VektorNd& v) {
  cout << "|----------BEGIN------------------------------|" << endl;
  cout << "Jestem wektorem pod adresem: " << &v << endl;
  int wymiar = v.getDim();
  cout << "Mój wymiar to: " << wymiar << endl;
  cout << "A elementy:" << endl;
  for (int i = 0; i < wymiar; i++)
    cout << "[" << i << "] = \t" << v.getCoef(i) << endl;
  cout << "|-----------END-------------------------------|" << endl;
}
*/
int main()
{
  const double wartosci[] = {1, 2, 3};
  const double wartosci2[] = {4, 5, 6};
  VektorNd v1(wartosci, 3);
  VektorNd v2(wartosci2, 3);

  VektorNd vektory[2] = {v1, v2};

  VectorOfVectors vov1(vektory, 2);
  VectorOfVectors vov2(vov1);
  cout << vov1;
  vov1 = vov2;
  cout << vov1;
}