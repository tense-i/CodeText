#include <bits/stdc++.h>
using namespace std;

// 高精度乘以高精度
typedef array<int, 500> arr; // 将一个500位的静态数组封装为arr，相当于vector<int> arr(500);
arr mul(arr &a, arr &b)
{
  arr c{1};
  for (int i = 0; i < 500; i++)
  {
    for (int j = 0; j < 500; j++)
    {
      if (i + j >= 500)
        continue;
      c[i + j] += a[i] * b[j];
    }
  }
  for (int i = 0; i < 500; i++)
  {
    c[i + 1] += c[i] / 10;
    c[i] %= 10;
  }
  return c;
}

// 乘法
vector<int> mul(vector<int> &a, vector<int> &b)
{
  vector<int> c(a.size() + b.size() + 4, 0);
  for (int i = 0; i < a.size(); i++)
  {
    for (int j = 0; j < b.size(); j++)
    {
      c[i + j] += a[i] * b[j];
    }
  }
  for (int i = 0; i < c.size(); i++)
  {
    c[i + 1] += c[i] / 10;
    c[i] %= 10;
  }
  while (c.back() == 0 && c.size() > 1)
    c.pop_back();
  return c;
}
/*
 加法；
vector<int> Add(vector<int> &a, vector<int> &b)
{
  vector<int> c;
  int t = 0;
  for (int i = 0; i < a.size() || i < b.size(); i++)
  {
    if (i < a.size())
      t += a[i];
    if (i < b.size())
      t += b[i];
    // c.push_back(t % 10);
    t /= 10;
  }
  if (t)
    c.push_back(1);
  return c;
}

/*


 */

/**
  // ! 红色的高亮注释
  // ? 蓝色的高亮注释
  // * 绿色的高亮注释
  // todo 橙色的高亮注释
  // //  灰色带删除线的注释
*/

vector<int> sub(vector<int> &a, vector<int> &b)
{
  int t = 0;
  vector<int> c;
  for (int i = 0; i < a.size(); i++)
  {
    t = a[i] - t;
    if (i < b.size())
      t -= b[i]; // t=t-b[i];即t=a[i]-b[i]-t
    c.push_back((t + 10) % 10);
    if (t < 0)
      t = 1;
    else
      t = 0;
  }
  while (c.back() && c.size() >= 1)
    c.pop_back();
  return c;
}
bool cmp(vector<int> &a, vector<int> &b)
{
  if (a.size() != b.size())
    return a.size() > b.size();
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] != b[i])
      return a[i] > b[i];
  }
  return true;
}

// 乘法；
vector<int> mul(vector<int> &a, int b)
{
  int t = 0;
  vector<int> c;
  for (int i = 0; i < a.size(); i++)
  {
    if (i < a.size())
      t += a[i] * b;
    c.push_back(t % 10);
    t /= 10;
  }
  // 判断最后的进位
  while (t)
  {
    c.push_back(t % 10);
    t /= 10;
  }
  return c;
}

/* vector<int> div(vector<int> &a, int b,int &r ){
  vector<int> c;
  r = 0;
  for (int i = a.size() - 1; i >=0;i++){
    r = r * 10 + a[i];
    c.push_back(r / b);
    r %= b;
  }
  reverse(c.end(), c.begin());
  while (c.size() > 1&&c.back()==0)
    c.pop_back();
  return c;
} */

// 也要逆序存储；

vector<int> div(vector<int> &a, long long b, int &r)
{
  vector<int> c;
  bool is_first = true;
  for (int i = a.size() - 1; i >= 0; i--)
  {
    r = r * 10 + a[i];
    int x = r / b;
    if (!is_first || x)
    {
      is_first = false;
      c.push_back(x);
    }
    r %= b;
  }
  reverse(c.begin(), c.end());
  while (c.size() > 1 && c.back() == 0)
    c.pop_back();
  return c;
}

//
int main()
{
  string s1, s2;
  vector<int> a, b, c;
  int k;
  cin >> s1;
  cin >> k;
  // cin >> s1 >> s2;
  for (int i = 0; i < s1.size(); i++)
  {
    a.push_back(s1[i] - '0');
  }
  /* for (int i = s1.size() - 1; i >= 0; i--)
  {
    a.push_back(s1[i] - '0');
  } */
  /* for (int i = s2.size() - 1; i >= 0; i--)
  {
  b.push_back(s2[i] - '0');
} */
  /* if (cmp(a, b))
    c = sub(a, b);
  else
    c = sub(b, a); */
  // c = mul(a, k);
  int r = 0;
  c = div(a, k, r);
  // vector<int> c = Add(a, b);
  /* for (int i = c.size() - 1; i >= 0; i--)
  {
    cout << c[i];
  } */
  // cout << r << endl;
  for (int i = 0; i < c.size(); i++)
  {
    cout << c[i];
  }
  cout << endl;
  return 0;
}