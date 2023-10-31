#define _CRT_SECURE_NO_WARNINGS
#include "Mystring.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
Mystring::Mystring()
{
  this->pstr = new char[1];
  this->pstr[0] = '\0';
  this->len = 0;
}
Mystring::~Mystring()
{
  if (this->pstr != nullptr)
  {
    delete[] this->pstr;
    this->pstr = nullptr;
  }
}
Mystring::Mystring(int n, char ch)
{
  this->pstr = new char[n + 1];
  for (int i = 0; i < n; i++)
    this->pstr[i] = ch;
  this->pstr[n] = '\0';
  this->len = n;
}
Mystring::Mystring(const Mystring &str)
{
  this->pstr = new char[strlen(str.pstr) + 1];
  strcpy(this->pstr, str.pstr);
  this->len = str.len;
}
Mystring &Mystring::operator=(const Mystring &str)
{
  if (this->pstr != nullptr)
  {
    delete[] this->pstr;
    this->pstr = nullptr;
  }
  this->pstr = new char[strlen(str.pstr) + 1];
  strcpy(this->pstr, str.pstr);
  this->len = str.len;
  return *this;
}
Mystring Mystring::operator+(const Mystring &str)
{
  //
  int newlen = this->len + str.len + 1;
  Mystring temp;
  if (temp.pstr != nullptr)
  {
    delete[] temp.pstr;
    temp.pstr = nullptr;
  }
  temp.pstr = new char[newlen];
  temp.len = newlen;
  // 必要的！！！
   memset(temp.pstr, 0, newlen);
  strcat(temp.pstr, this->pstr);
  strcat(temp.pstr, str.pstr);
  return temp;
}
Mystring Mystring::operator+(const char *s)
{
  int newlen = this->len + strlen(s);
  char *newspace = new char[newlen + 1];
  memset(newspace, 0, newlen + 1);
  strcat(newspace, this->pstr);
  strcat(newspace, s);
  Mystring temp;
  if (temp.pstr != nullptr)
  {
    delete[] temp.pstr;
    temp.pstr = nullptr;
  }
  temp.pstr = newspace;
  temp.len = newlen;
  return temp;
}
char &Mystring::operator[](int index)
{
  return this->pstr[index];
}
ostream &operator<<(ostream &out, const Mystring &str)
{
  out << str.pstr;
  return out;
}
Mystring &Mystring::operator+=(const Mystring &str)
{
  int newlen = this->len + str.len + 1;
  char *newspace = new char[newlen + 1];
  memset(newspace, 0, newlen + 1);
  strcat(newspace, this->pstr);
  strcat(newspace, str.pstr);
  if (this->pstr != nullptr)
  {
    delete[] this->pstr;
    this->pstr = nullptr;
  }
  this->pstr = newspace;
  this->len = newlen;
  return *this;
}
 istream &operator>>(istream&in, Mystring&str){
  cin >> str.pstr;
  //1.定义一个临时空间
  char temp[1024] = {0};
  in >> temp;
  if(str.pstr!=nullptr){
    delete[] str.pstr;
    str.pstr = nullptr;
  }
  memset(str.pstr, 0, str.len);
  strcat(str.pstr, temp);
  return in;
  str.len = strlen(temp);
}
void test()
{
  Mystring s1(10, 'a');
  cout << s1 << endl;
  Mystring s2(3, 'b');
  cout << s2 << endl;
  Mystring s3 = s1 + s2;
  cout << s3 << endl;
  Mystring s4 = s2 + "hehe";
  cout << s4 << endl;
  s4 += s3;
  cout << s4 << endl;
}
int main()
{
  test();
  return 0;
}