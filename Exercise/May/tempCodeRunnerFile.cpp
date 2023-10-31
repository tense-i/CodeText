#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N(1e5 + 10);
int a[N];
int main()
{
  cin >> n >> m;
  int sum;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  a[0] = -2e9;
  a[n + 1] = 2e9;
  while (m--)
  {
    int x;
    cin >> x;
    int t = lower_bound(a + 1, a + n + 1, x) - a;
    if (a[t] - x <= x - a[t - 1])
    {
      sum += a[t] - x;
      cout << a[t] - x << endl;
    }
    else
    {
      sum += x - a[t - 1];
      cout << x - a[t - 1] << endl;
    }
  }
  cout << sum << endl;
  return 0;
}