#include <bits/stdc++.h>
using namespace std;
const int N(1e8);
int a[N];

bool check(int m)
{
  return true; // 按照需求写
}

// 模板一
// 与STL中的Lower_bound效果相同--向左找：大于结果的最小值
int bsearch(int l, int r, int x)
{
  while (l < r)
  {
    int m = r + l >> 1;
    // check包含等于的情况
    if (check(m))
      r = m;
    else
      l = m + 1;
  }
  return l;
}
// 模板二
// 与STL库中的upper_bound效果相同，向右找，小于结果的最大值；
int bsearch(int l, int r, int x)
{
  while (l < r)
  {
    int m = l + r + 1 >> 1;
    // check包含等于的情况
    if (check(m))
      l = m;
    else
      r = m - 1;
  }
  return l;
}

// 模板三、实数二分
int bs(int l, int r)
{
  // 保证精度
  while (r - l >= 1e-5)
  {
    int m = l + r >> 1;
    if (check(m))
      r = m;
    else
      l = m;
  }
  return l;
}

// 左关闭右关闭
int bs(int x, int l, int r)
{
  int m = 0;
  while (l <= r)
  {
    if (x < a[m])
      r = m - 1;
    else if (x > a[m])
      l = m + 1;
    else
      return m;
  }
  return m;
}

// 左闭右开
int bs(int x, int l, int r)
{
  int m = 0;
  while (l < r)
  {
    if (x < a[m])
      r = m;
    else if (x > a[m])
      l = m + 1;
    else
      return m;
  }
  return m;
}

// 二分答案
// 数组从1开始；
int n;
int colc(int x)
{
  int l = 0, r = n + 1;
  while (l + 1 < r)
  {
    int m = (l + r) >> 1;
    if (x < a[m])
      r = m;
    else
      l = m;
  }
  return l;
}