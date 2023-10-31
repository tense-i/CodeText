#include <iostream>
using namespace std;
class Mystring
{
  friend ostream &operator<<(ostream &out, const Mystring &str);
  friend istream &operator>>(istream &in, Mystring &str);
public:
  Mystring();
  Mystring(int n, char ch);
  Mystring(const Mystring &str);
  // Mystring Mystring::operator+(const char *s);
  Mystring &operator=(const Mystring &str);
  // Mystring operator+(const Mystring &str);
  Mystring operator+(const Mystring &str);
  Mystring operator+(const char *s);
  Mystring &operator+=(const Mystring &str);
  // int getsize();
  char &operator[](int index);
  Mystring(const char *string);
  ~Mystring();

private:
  char *pstr;
  int len;
};