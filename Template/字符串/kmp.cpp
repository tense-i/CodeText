#include <bits/stdc++.h>
using namespace std;
const int N(1e5);
int nxt[N];
char s[N], p[N];


void kmp(char *s, char *p)
{
  int n = strlen(s + 1);
  int m = strlen(p + 1);
  p[m + 1] = '#';
  for (int i = 1, j = m + 2; i <= n; i++)
    p[j++] = s[i];
  int j = 0;
  nxt[1] = 0;
  for (int i = 2; i <= n + m + 1; i++)
  {
    while (j > 0 && p[i] != p[j + 1])
      j = nxt[j - 1];
    if (p[i] == p[j + 1])
      j++;
    nxt[i] = j;
  }
}

int z[N];
void exkmp()
{
  int l = 1, r = 0;
  int n = strlen(s + 1);
  z[1] = 0;
  for (int i = 2; i <= n; i++)
  {

    if (i > r)
      z[i] = 0;
    else
    {
      int k = i - l + 1;
      z[i] = min(z[k], r - i + 1);
    }

    while (i + z[i] <= n && s[z[i] + 1] == s[i + z[i]])
    {
      ++z[i];
    }

    if (i + z[i] - 1 > r)
    {
      l = i;
      r = i + z[i] - 1;
    }
  }
}




void exkmp2()
{
  int l = 1, r = 0;
  int n = strlen(s + 1);
  z[1] = 0;
  for (int i = 2; i <= n; i++)
  {
    // l带r无法匹配,后面暴力匹配；
    if (i > r)
      z[i] = 0;
    else
    { // i<r,则i-r的字符与k-(r-l+1)的字符匹配，以已经匹配的z数组更新z【i】；
      int k = i - l + 1;
      z[i] = min(z[k], r - i + 1);
    }
    // 暴力匹配
    while (i + z[i] <= n && s[z[i] + 1] == s[i + z[i]])
    {
      ++z[i];
    }
    // 更新l与r；
    if (i + z[i] - 1 > r)
    {
      l = i;
      r = i + z[i] - 1;
    }
  }
}

void kmp()
{
  int n = strlen(p + 1);
  int j = 0;
  nxt[1] = 0;
  for (int i = 2; i <= n; i++)
  { // 无法匹配，回退指针；
    while (j > 0 && p[i] != p[j + 1])
      j = nxt[j - 1];
    // 匹配成功,长度加1
    if (p[i] == p[j + 1])
      j++;
    nxt[i] = j;
  }
}

void kmp2(char *s, char *p)
{
  int n = strlen(s + 1);
  int m = strlen(p + 1);
  p[m + 1] = '#';
  for (int i = 1, j = m + 2; i <= n; i++)
    p[j++] = s[i];
  int j = 0;
  nxt[1] = 0;
  for (int i = 2; i <= n + m + 1; i++)
  {
    while (j > 0 && p[i] != p[j + 1])
      j = nxt[j - 1];
    if (p[i] == p[j + 1])
      j++;
    nxt[i] = j;
  }
}



int main()
{
  cin >> s + 1 >> p + 1;
  kmp(s, p);
  for (int i = 1; i <= strlen(s + 1) + strlen(p + 1) + 1; i++)
    cout << nxt[i] << ' ';
  return 0;
}