#include <bits/stdc++.h>
using namespace std;
const int N(1e8 + 3);
int n;
int a[N];
// 低端筛法；
bool is_prime(int x)
{
  for (int i = 3; i * i <= x; i += 2)
  {
    if (x % i == 0)
    {
      return false;
    }
  }
  return true;
}
void prime1()
{
  memset(a, false, sizeof(a));
  a[2] = true;
  for (int i = 3; i <= n; i++)
  {
    if (is_prime(i))
    {
      a[i] = true;
    }
  }
}

// Eratosthenes(朴素)
// 易超时间，1e9;
void prime2()
{
  memset(a, true, sizeof(a));
  a[1] = a[0] = false;
  int p = 2;
  while (p * p <= n)
  {
    if (a[p])
    {
      for (int i = p * p; i <= n; i += p)
      {
        a[i] = false;
      }
    }
    p++;
  }
}

// 欧拉筛法
// 使用动态数组较好，欧拉筛法容易超内存,1e8；
vector<int> pri;
vector<int> arr;
void prime3()
{
  arr.resize(n + 1, true);
  arr[0] = arr[1] = false;
  for (int i = 2; i <= n; i++)
  {
    // 将2加入素数表；
    if (arr[i])
    {
      pri.push_back(i);
    }
    // 将现在素数表中那个数为最小因子的数排除；
    for (int j = 0; j < pri.size() && i * pri[j] <= n; j++)
    {
      arr[i * pri[j]] = false;
      if (i % pri[j] == 0)
        break;
    }
  }
}
int main()
{
  cin >> n;
  prime3();
  for (auto i : pri)
    cout << i << ' ';
  return 0;
}