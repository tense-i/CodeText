/* #include <bits/stdc++.h>
using namespace std;
const int N(1e4);
int nxt[N];
char s[N];
int n;
int z[N];
void kmp()
{
  int j = 0;
  nxt[1] = 0;
  n = strlen(s + 1);
  for (int i = 2; i <= n; i++)
  {
    while (j > 0 && s[i] != s[j + 1])
      j = nxt[j - 1];
    if (s[i] == s[j + 1])
      j++;
    nxt[i] = j;
  }
}
void exkmp()
{
  z[1] = 0;
  int l = 1, r = 0;
  int n = strlen(s + 1);
  for (int i = 2; i <= n; i++)
  {
    if (i > r)
      z[i] = 0;
    else
    {
      int k = i - l + 1;
      z[i] = min(z[k], r - i + 1);
    }
    while (i + z[i] <= n && s[z[i] + 1] == s[z[i] + i])
      ++z[i];
    if (i + z[i] - 1 > r)
    {
      l = i;
      r = i + z[i] - 1;
    }
  }
}

char t[N];
int p[N];
void manacher()
{
  int n = strlen(s + 1);
  int k = 0;
  t[++k] = '$';
  for (int i = 1; i <= n; i++)
  {
    t[++k] = s[i];
    t[++k] = '$';
  }
  int m = 0;
  int r = 0;
  for (int i = 1; i <= k; i++)
  {
    if (i > r)
      p[i] = 1;
    else
      p[i] = min(p[2 * m - i], r - i + 1);
    while(i-p[i]>0&&i+p[i]<=k&&t[i-p[i]]==t[i+p[i]])
      ++p[i];
    if (i + p[i] - 1 > r)
    {
      m = i;
      r = i + p[i] - 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= k; i++)
    ans = max(ans, p[i]);
  cout << ans - 1 << endl;
}


int main()
{
  cin >> s + 1;
  manacher();
  return 0;
} */

/*

#include <bits/stdc++.h>
using namespace std;
const int N(1e4);
int nxt[N];
char s[N];
int n;

void kmp()
{
  int j = 0;
  nxt[1] = 0;
  n = strlen(s + 1);
  for (int i = 2; i <= n; i++)
  {
    while (j > 0 && s[i] != s[j + 1])
      j = nxt[j - 1];
    if (s[i] == s[j + 1])
      j++;
    nxt[i] = j;
  }
  int ans = 0;

  cout << n-nxt[n] << endl;
}

int main()
{
  cin >> s + 1;
  kmp();
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;

int f(int m)
{
  return 1;
}
double calc()
{
  double l = 0, r = 1e10;
  // 具体多少次三分，一般情况下100次就够了
  for (int i = 1; i <= 100; i++)
  {
    double m1 = l + (r - l) / 3,
           m2 = l + (r - l) / 3 * 2;
    if (f(m1) < f(m2))
    {
      l = m1;
    }
    else
      r = m2;
  }
}
double calc()
{
  double l = 0, r = 1e10;
  while (r - l >= 1e-5)
  {
    double m1 = l + (r - l) / 3.0,
           m2 = r - (r - l) / 3.0;
    if (f(m1) < f(m2))
      l = m1;
    else
      r = m2;
  }
}
int main()
{

  return 0;
} */

/*

#include <bits/stdc++.h>
using namespace std;

class maker
{
public:
  maker(const char *name, int age)
  {
    this->age = age;
    strcpy(this->name, name);
  }
  char name[20];
  maker()
  {
    this->name[0] = '\0';
    this->age = 0;
  }
  int age;
};
void test()
{
  maker m1("haha", 12), m2("hans", 132);
  ofstream ofs;
  ofs.open("test.txt", ios::out | ios::binary);
  if (!ofs.is_open())
  {
    cout << "打开失败" << endl;
  }
  ofs.write((const char *)&m1, sizeof(m1));
  ofs.write((const char *)&m2, sizeof(m2));
  ofs.close();
}
void test2()
{
  ifstream ifs;
  ifs.open("tst.txt", ios::in | ios::binary);
  maker m1, m2;
  ifs.read((char *)&m1, sizeof(m1));
  ifs.read((char *)&m2, sizeof(m2));
  cout << m1.age << endl;
  cout << m2.age << endl;
}
int main()
{

  test();
  test2();

  return 0;
} */
/*


#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int a[N], x, q, n;

int main()
{
  cin >> n >> q;
  int tot = 0;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
  {
    int l = i + 1, r = n;
    while (l < r)
    {
      int mid = l + r >> 1;
      if (a[mid] - a[i] >= q)
        r = mid;
      else
        l = mid + 1;
    }
    int st = l;
    if (a[l]-a[i]!=q)
      continue;
    l = st - 1;
    r = n;
    while (l < r)
    {
      int mid = l + r + 1 >> 1;
      if (a[mid] <= a[st])
        l = mid;
      else
        r = mid - 1;
    }
    tot += (l - st + 1);
  }
  cout << tot << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int a[N], x, n, m;
int sum = 0;
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (; m--;)
  {
    cin >> x;
    int l = 1, r = n+1;
    while (l < r)
    {
      int mid = l + r>> 1;
      if (a[mid] >= x)
        r = mid;
      else
        l = mid + 1;
    }
    if (a[l] - x <= x - a[l - 1])
      sum += a[l] - x;
    else
      sum += x - a[l - 1];
  }
  cout << sum << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(1e6 + 12);
long long n, m;
long long a[N];
int check(int mid)
{
  long long tot = 0;
  for (int i = 1; i <= n; i++)
  {
    if (a[i] >= mid)
      tot += a[i] - mid;
  }
  if (tot >= m)
    return 1;
  else
    return 0;
}
int main()
{
  cin >> n >> m;
  long long r = 0, l = 1;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    r = max(r, a[i]);
  }

  //sort(a + 1, a + 1 + n);
  while (l < r)
  {
    int mid =l+r+1>>1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(1e5 + 10);
int n, k;
int a[N];
int check(int mid)
{
  int tot = 0;
  for (int i = 1; i <= n; i++)
  {
    tot += a[i] / mid;
  }
  if (tot >= k)
    return 1;
  else
    return 0;
}
int main()
{
  cin >> n >> k;
  int r = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    r = max(r, a[i]);
  }
  if (r < k)
  {
    cout << 0 << endl;
    return 0;
  }
  int l = 1;
  while (l < r)
  {
    int mid = l + r +1>> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(1e5 + 10);
int n, m, len;
int a[N];

int check(int x)
{
  int tot = 0;
  int now = 0;
  int i = 0;
  while (i < n + 1)
  {
    i++;
    if (a[i] - a[now] <x)
      tot++;
    else
      now = i;
  }
  if (tot<= m)
    return 1;
  else
    return 0;
}
int main()
{
  cin >> len >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  a[0] = 0,a[n+1]=len;
  int l = 1;
  int r = len;
  while (l < r)
  {
    int mid = l + r+1 >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid -1;
  }
  cout << l << endl;
  return 0;
} */

/*
#include <iostream>
using namespace std;
const int N = 100010;
typedef long long ll;
ll a[N], n, m, summ, mina = 1e9 + 1, maxa;

int check(int mid)
{
  ll cnt = 0, sum = 0;
  for (int i = 1; i <= n - 1; i++)
  {
    sum += a[i];
    if (sum + a[i + 1] > mid)
      cnt++, sum = 0; // 不能满足 "区间间距小于最大距离"，那就分段
  }
  if (cnt + 1 <= m)
    return 1; // 总的段数小于等于需要的段数，这样都能满足mid为每段的最大值，那么多分几段，肯定还能满足
  return 0;
}
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i], summ += a[i];
    if (a[i] < mina)
      mina = a[i];
    if (a[i] > maxa)
      maxa = a[i];
  }

  int l = maxa, r = summ; // l要设为maxa，所有段的最大值肯定大于等于maxa
  while (l < r)
  {
    int mid = l + r >> 1;
    if (check(mid))
      r = mid; // 求的是最大值的最小，故尽量往左来
    else
      l = mid + 1;
  }
  cout << l;
  return 0;
}
 */

/*

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int N = 200010;
typedef long long ll;
int a[N];
int n, c;
int check(int x)
{
  int tot = 1;
  int i = 1, now = 1;
  while (i < n)
  {
    i++;
    if (a[i] - a[now] < x)
    {
      tot++;
    }
    else
      now = i;
  }
  if (tot <= c)
    return 1;
  else
    return 0;
}
int main()
{
  cin >> n >> c;
  int r = 0;
  for (int i = 1; i <= n; i++)
    cin >> a[i], r = max(r, a[i]);
  sort(a + 1, a + 1 + n);
  int l = 1;
  while (l < r)
  {
    int mid = l + r + 1 >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << endl;
  return 0;
}

 */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(2e7 + 7);
int a[N];
char s[N], p[2*N];
int z[2 * N];
void exkmp(char *s, char *p)
{
  z[1] = 0;
  int len1 = strlen(s + 1);
  int len2 = strlen(p + 1);
  p[++len2] = '#';
  int j = len2;
  for (int i = 1; i <= len1; i++)
    p[++j] = s[i];
  int l = 1, r = 0;
  for (int i = 1; i <= j; i++)
  {
    if (i > r)
    {
      z[i] = 0;
    }
    else
    {
      int k = i - l + 1;
      z[i] = min(z[k], r - i + 1);
    }
    while (i + z[i] <= j && p[z[i] + 1] == p[z[i] + i])
      ++z[i];
    if (i + z[i] - 1 > r)
      l = i;
    r = i + z[i] - 1;
  }
  int ans = 0;
  for (int i = len2 + 1; i <= j; i++)
  {
    ans ^= ((i - len2) * (z[i] + 1));
  }
  printf("%d\n", ans);
}
void exkmp2(char *s)
{
  z[1] = 0;
  int l = 1, r = 0;
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++)
  {
    if (i > r)
      z[i] = 0;
    else
    {
      int k = i - l + 1;
      z[i] = min(z[k], r - i + 1);
    }
    while (i + z[i] <= n && s[z[i] + 1] == s[z[i] + i])
      ++z[i];
    if (i + z[i] - 1 > r)
    {
      l = i;
      r = i + z[i] - 1;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
   ans ^= (i * (z[i] + 1));
  printf("%d\n", ans);
}
int main()
{
  //cin >> s + 1;
  //cin >> p + 1;
  scanf("%s", s + 1);
  scanf("%s", p + 1);
  exkmp2(p);
  exkmp(s, p);
  return 0;
} */
/*
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2e7 + 10;
ll nxt[N], ext[N];
void qnxt(char *c)
{
  int len = str len(c);
  int p = 0, k = 1, l; // 我们会在后面先逐位比较出 nxt[1] 的值，这里先设 k 为 1
  // 如果 k = 0，p 就会锁定在 |c| 不会被更改，无法达成算法优化的效果啦
  nxt[0] = len; // 以 c[0] 开始的后缀就是 c 本身，最长公共前缀自然为 |c|
  while (p + 1 < len && c[p] == c[p + 1])
    p++;
  nxt[1] = p; // 先逐位比较出 nxt[1] 的值
  for (int i = 2; i < len; i++)
  {
    p = k + nxt[k] - 1; // 定义
    l = nxt[i - k];     // 定义
    if (i + l <= p)
      nxt[i] = l; // 如果灰方框小于初始的绿方框,直接确定 nxt[i] 的值
    else
    {
      int j = max(0, p - i + 1);
      while (i + j < len && c[i + j] == c[j])
        j++; // 否则进行逐位比较
      nxt[i] = j;
      k = i; // 此时的 x + nxt[x] - 1 一定刷新了最大值，于是我们要重新赋值 k
    }
  }
}
void exkmp(char *a, char *b)
{
  int la = strlen(a), lb = strlen(b);
  int p = 0, k = 0, l;
  while (p < la && p < lb && a[p] == b[p])
    p++; // 先算出初值用于递推
  ext[0] = p;
  for (int i = 1; i < la; i++) // 下面都是一样的逻辑啦
  {
    p = k + ext[k] - 1;
    l = nxt[i - k];
    if (i + l <= p)
      ext[i] = l;
    else
    {
      int j = max(0, p - i + 1);
      while (i + j < la && j < lb && a[i + j] == b[j])
        j++;
      ext[i] = j;
      k = i;
    }
  }
}
int la, lb;
char a[N], b[N];
ll ans;
int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  cin >> a >> b;
  qnxt(b);
  exkmp(a, b);
  la = strlen(a), lb = strlen(b), ans = 0;
  for (int i = 0; i < lb; i++) // 要注意下标从 0 开始
  {
    cout << nxt[i] << ' ';
    ans ^= (i + 1) * (nxt[i] + 1);
  }
  cout << endl;
  cout << ans << "\n";
  ans = 0;
  for (int i = 0; i < la; i++)
  {
    ans ^= (i + 1) * (ext[i] + 1);
  }
  cout << ans;
  return 0;
} */

/*

#include <bits/stdc++.h>
using namespace std;
const int N(1e9);
int a[N], c[N];
int solve(int l, int r)
{
  if (l == r)
    return 0;
  int m = l + r >> 1;
  long long res = solve(l, m) + solve(m + 1, r);
  int p1 = l, p2 = m + 1, cnt = 0;
  while (p1 <= m && p2 <= r)
  {
    if (a[p1] < a[p2])
      c[++cnt] = a[p1++], res += p2 - m - 1;
    else
      c[++cnt] = a[p2++];
  }
  while (p1 <= m)
    c[++cnt] = a[p1++], res += p2 - m - 1;
  while (p2 <= r)
  {
    c[++cnt] = a[p2++];
  }
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(1e8);
char s[N];
int t;
int n;
int solve(int l, int r, char ch)
{
  if (l == r)
  {
    if (ch == s[l])
      return 0;
    else
      return 1;
  }
  int m = (l + r >> 1);
  int x = 0, y = 0;
  for (int i = l; i <= m; i++)
    if (s[i] != ch)
      ++x;
  for (int i = m + 1; i <= r; i++)
    if (s[i] != ch)
      ++y;
  return min(x + solve(m + 1, r, ch + 1), y + solve(l, m, ch + 1));
}
int main()
{
  cin >> t;
  for (; t--;)
  {
    cin >> n;
    cin >> s + 1;
    cout << solve(1, n, 'a') << endl;
  }
}
 */
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
const int N(1e6);
// vector<vector<int>> edge(N, vector<int>());
vector<int> edge[N];
int a[N], dist[N], f[N][21], v[N][21];
inline void dfs(int x)
{
  for (auto y : edge[x])
  {
    if (!dist[y])
    {
      dist[y] = dist[x] + 1;
      f[y][0] = x;
      dfs(y);
    }
  }
}
int main()
{
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i < n; i++)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    edge[x].push_back(y);
    edge[y].push_back(x);
  }
  memset(dist, 0, sizeof(dist));
  dist[1] = 1;
  // 建树
  dfs(1);
  memset(v, 127, sizeof(v));
  for (int i = 1; i <= n; i++)
  {
    v[i][0] = a[i];
  }

  for (int i = 1; i <= 20; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      f[j][i] = f[f[j][i - 1]][i - 1],
      v[j][i] = min(v[j][i - 1], v[f[j][i - 1]][i - 1]);
    }
  }
  for (; q--;)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    if (dist[x] < dist[y])
      swap(x, y); // 保证x往上跳
    int z = dist[x] - dist[y];
    int ans = 1 << 30;
    for (int i = 0; z; z >>= 1, i++)
      if (z & 1) // 未不为0
        ans = min(ans, v[x][i]), x = f[x][i];
    if (x != y)
    {
      for (int i = 20; i >= 0; i--)
      {
        if (f[x][i] != f[y][i])
        {
          ans = min(ans, v[x][i]);
          ans = min(ans, v[y][i]);
          x = f[x][i];
          y = f[y][i];
        }
      }
      ans = min(ans, v[x][0]);
      ans = min(ans, v[y][0]);
      x = f[x][0];
    }
    ans = min(ans, v[x][0]);
    cout << ans << endl;
  }
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(5e6 + 12);
int a[N], d[N], s[N];
int n;
int p;
int main()
{
  cin >> n >> p;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  while (p--)
  {
    int x, y, z;
    cin >> x >> y >> z;
    d[x] += z;
    d[y + 1] -= z;
  }
  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++)
  {
    d[i] += d[i - 1];
    a[i] += d[i];
    ans = min(ans, a[i]);
  }
  cout << ans << endl;
  return 0;
} */

// #include <bits/stdc++.h>
/* #include <iostream>
#include <cstring>
using namespace std;
const int N(1e5 + 10);
int a[N], d[N];
int t;
int main()
{
  int n;
  while (~scanf("%d", &n))
  {
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i++)
    {
      int x, y;
      scanf("%d%d", &x, &y);
      d[x]++;
      d[y + 1]--;
    }
    for (int i = 1; i <= n; i++)
    {
      a[i] = a[i - 1] + d[i];
      if (i != n)
        printf("%d ", a[i]);
      else
        printf("%d\n", a[n]);
    }
  }
  return 0;
} */
/*
#include <iostream>
using namespace std;

const int N(1e5 + 2);
int a[N][N];
int n, k;
int main()
{
  cin >> n >> k;
  for (int i = 1; i <= k; i++)
  {
    int x1, y1, x2, y2;
    a[x1 + 1][y1 + 1]++;
    a[x1 + 1][y2 + 1]--;
    a[x2 + 1][y1 + 1]--;
    a[x2 + 1][y2 + 1]++;
  }
  int ans(0);
  for (int i = 1; i <= n + 1; i++)
  {
    for (int j = 1; j <= n + 1; j++)
    {
      a[i][j] = a[i][j + 1] + a[i + 1][j] - a[i - 1][j - 1];
      if (a[i][j] == k)
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(1e3 + 5);
int a[N][N], d = 1;
int main()
{
  int n, k;
  int ans(0);
  cin >> n >> k;
  while (n--)
  {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a[x1 + 1][y1 + 1] += d;
    a[x1 + 1][y2 + 1] -= d;
    a[x2 + 1][y1 + 1] -= d;
    a[x2 + 1][y2 + 1] += d;
  }
  for (int i = 1; i < N; i++)
  {
    for (int j = 1; j < N; j++)
    {
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
      if (a[i][j] == k)
        ans++;
    }
  }
  cout << ans;
  return 0;
} */
/*
#include <bits/stdc++.h>
// #include <iostream>
// #include <cstring>
using namespace std;
const int N(1e5 + 4);
int n, a[N], b[N];

int main()
{
  cin >> n;
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++)
  {
    b[i] = a[i] - a[i - 1];
  }
  long long ans = 0;
  for (int i = 1; i <= n + 1; i++)
  {
    if (b[i] > 0)
      ans += b[i];
  }
  cout << ans << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(1e9);
long long a, b, p;
long long quickmul(long long a, long long b)
{
  long long ans = 0;
  a %= p;
  for (; b; b >>= 1)
  {
    if (b & 1)
      ans += a, ans %= p;
    a += a, a %= p;
  }
  return ans;
}
int main()
{
  cin >> a >> b >> p;
  long long t = quickmul(a, b);
  cout << t << endl;
  return 0;
} */
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 高精度加法
vector<int> add(vector<int> a, vector<int> b)
{
  vector<int> c;
  int t = 0;
  for (int i = 0; i < a.size() || i < b.size(); i++)
  {
    if (i < a.size())
      t += a[i];
    if (i < b.size())
      t += b[i];
    c.push_back(t % 10);
    t /= 10;
  }
  if (t)
    c.push_back(1);
  return c;
}

// 高精度减法

int compare(vector<int> a, vector<int> b)
{
  if (a.size() != b.size())
    return a.size() > b.size();
  for (int i = 0; i < a.size() || i < b.size(); i++)
  {
    if (a[i] != b[i])
      return a[i] > b[i];
  }
  return 1;
}
vector<int> sub(vector<int> a, vector<int> b)
{
  vector<int> c;
  int t = 0;
  for (int i = 0; i < a.size(); i++)
  {
    t = a[i] - t;
    if (i < b.size())
      t -= b[i];
    c.push_back((t + 10) % 10);
    if (t < 0)
      t = -1;
    else
      t = 0;
  }
  while (c.size() > 1 && c.back() == 0)
    c.pop_back();
  return c;
}

// 高精度乘法

vector<int> mul(vector<int> &a, int b)
{

  vector<int> c;
  int t = 0;
  for (int i = 0; i < a.size() || t; i++)
  {
    if (i < a.size())
      t += a[i] * b;
    c.push_back(t % 10);
    t /= 10;
  }
  while (c.size() > 1 && c.back() == 0)
  {
    c.pop_back();
  }
  return c;
}

// 高精度除法
vector<int> div(vector<int> &a, int b, int &r)
{
  vector<int> c;
  for (int i = a.size() - 1; i >= 0; i--)
  {
    r = r * 10 + a[i];
    c.push_back(r / b);
    r %= b;
  }
  reverse(c.begin(), c.end());
  while (c.size() > 1 && c.back() == 0)
    c.pop_back();
  return c;
}

// 高精度

string s1, s2;

int main()
{

  vector<int> a{1}, b(0), c(0);
  for (int i = 1; i <= 3; i++)
  {
    a = mul(a, i);
    // b = add(a, c);
  }

  for (auto i : a)
    cout << i << ' ';
  return 0;
} */
// #include<bits/stdc++.h>

/*
#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>
using namespace std;
int fmain()
{
  int a[505];
  a[0] = 1;
  while (p--)
  {
    for (int i = 0; i < 500; i++)
    {
      a[i] *= 2;
    }
    for (int i = 0; i < 500; i++)
    {
      a[i + 1] += a[i] / 10;
      a[i] %= 10;
    }
  }
}
typedef array<int, 500> myarr;
myarr mul(myarr a, myarr b)
{
  myarr res{0};
  for (int i = 0; i < 500; i++)
  {
    for (int j = 0; j < 500; j++)
    {
      if (i + j >= 500)
        continue;
      res[i + j] += a[i] * b[j];
    }
  }
  for (int i = 0; i < 500; i++)
  {
    res[i + 1] += res[i] / 10;
    res[i] %= 10;
  }
  return res;
}
// 高精度乘整数
myarr mul2(myarr a, int b)
{
  for (int i = 0; i < 500; i++)
  {
    a[i] * b;
  }
  // 处理进位
  for (int i = 0; i < 500; i++)
  {
    a[i + 1] += a[i] / 10;
    a[i] %= 10;
  }
  return a;
}
array<int, 500> power(int a, int b)
{
  if (b == 0)
    return array<int, 500>{1};
  myarr res = power(a, b / 2);
  res = mul(res, res);
  if (b & 1)
  {
    res = mul2(res, a);
  }
  return res;
}
int n, p;
int main()
{
  cin >> p;
  cout << int(p * log10(2)) + 1 << endl;
  myarr a = power(2, p);
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 50; j++)
    {
      cout << a[499 - i * 50 - j];
    }
    cout << endl;
  }
  return 0;
} */
/*
#include <bits/stdc++.h>
#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>
using namespace std;
typedef array<int, 500> arr;
arr mul(arr &a, arr &b)
{
  arr res{0};
  for (int i = 0; i < 500; i++)
  {
    for (int j = 0; j < 500; j++)
    {
      if (i + j >= 500)
        continue;
      res[i + j] += a[i] * b[j]; //+=而不是简单赋值
    }
  }
  for (int i = 0; i < 500; i++)
  {
    res[i + 1] += res[i] / 10;
    res[i] %= 10;
  }
  return res;
}
int main()
{
  int p;
  cin >> p;
  cout << int(p * log10(2)) + 1 << endl;
  arr ans{1}, base{2};
  for (; p; p >>= 1)
  {
    if (p & 1)
      ans = mul(ans, base);
    base = mul(base, base);
  }
  ans[0]--;
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 50; j++)
    {
      cout << ans[499 - i * 50 - j];
    }
    cout << endl;
  }
  return 0;
} */

/*
#include <bits/stdc++.h>
using namespace std;

const int N(1e5);
int a[N];
int n, x;

int check(int x)
{
  return true;
}
// 模板一
int binsearch(int l, int r)
{
  while (l < r)
  {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
}

// 模板二
 */
/*

#include <bits/stdc++.h>
using namespace std;
const int N(2e5 + 12);
int a[N];
int n, x;
int main()
{
cin >> n >> x;
for (int i = 1; i <= n; i++)
 cin >> a[i];
int tot = 0;
sort(a + 1, a + 1 + n);
for (int i = 1; i < n; i++)
{
 int l = i + 1, r = n;
 while (l < r)
 {
   int mid = r + l >> 1;
   if (a[mid] - a[i] >= x)
     r = mid;
   else
     l = mid + 1;
 }
 int t = l;
 if (a[l] - a[i] != x)
   continue;
 else
   t = l;
 l = t - 1, r = n;
 while (l < r)
 {
   int mid = l + r + 1 >> 1;
   if (a[mid] <= a[t])
     l = mid;
   else
     r = mid - 1;
 }
 tot += l - t + 1;
}
cout << tot << endl;
return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(2e5 + 12);
int n, m;
int a[N], b[N];
int ans = 0;
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);
  a[0] = -1e9;
  a[n + 1] = 1e9;
  int tot = 0;
  while (m--)
  {
    int x;
    cin >> x;
    int l = 1, r = n + 1;
    while (l < r)
    {
      int mid = l + r >> 1;
      if (a[mid] >= x)
        r = mid;
      else
        l = mid + 1;
    }
    if (a[l] - x <= x - a[l - 1])
      ans += a[l] - x;
    else
      ans += x - a[l - 1];
  }
  cout << ans << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int n, k;
const int N(1e5 + 10);
int a[N];

int check(int x)
{
  int tot = 0;
  for (int i = 1; i <= n; i++)
    tot += a[i] / x;
  if (tot >= k)
  {
    return 1;
  }
  else
    return 0;
}
int main()
{
  cin >> n >> k;
  int len = 0, sum = 0;
  for (int i = 1; i <= n; i++)
    cin >> a[i], len = max(len, a[i]), sum += a[i];
  if (sum < k)
  {
    cout << 0;
    return 0;
  }
  int l = 1, r = len;
  while (l < r)
  {
    int mid = l + r + 1 >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;

int len, n, m;
const int N(5e4 + 12);
int a[N];

int check(int x)
{
  int tot = 0;
  int i = 0;
  int now = 0;
  while (i < n + 1)
  {
    // 第一块必须跳，起点
    i++;
    if (a[i] - a[now] < x)
      tot++;
    else
      now = i;
  }
  if (tot <= m)
    return 1;
  else
    return 0;
}
int main()
{
  cin >> len >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  a[0] = 0;
  a[n + 1] = len;
  int l = 1, r = len;
  while (l < r)
  {
    int mid = l + r + 1 >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(1e5 + 5);
int n, m, len;
int a[N];
inline bool check(int x)
{
  int tot = 0;
  int sz = 0;
  for (int i = 1; i <= n; i++)
  {
    if (a[i] - sz <= x)
      sz = a[i];
    else
    {
      sz = sz + x;
      i--;
      tot++;
    }
  }
  if (tot <= m)
    return 1;
  else
    return 0;
}
int main()
{
  scanf("%d%d%d", &len, &n, &m);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + n + 1);
  int l = 1, r = len;
  int ans = 0;
  while (l < r)
  {
    int mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(1e2 + 3);
int a[N][N], f[N];
vector<vector<int>> edges;
int n;
int m;
int main()
{
  cin >> n >> m;
  edges.resize(m + 1);
  memset(a, 127, sizeof(a)); // 所以距离初始为无穷大
  for (int i = 1; i <= m; i++)
  {
    int x, y, z;
    cin >> x >> y >> z;
    a[x][y] = min(a[x][y], z);
  }
  memset(f, 127, sizeof(f));
  f[1] = 0;
  for (int i = 2; i <= n; i++)
  {
    for (int j = 1; j < i; j++)
      if (f[j] < 1 << 30 && a[j][i] < 1 << 30)
        f[i] = min(f[i], f[j] + a[j][i]);
  }
  cout << f[n] << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int n, a[100], f[1001];

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
  {
    f[i] = 1;
    for (int j = 1; j < i; j++)
      if (a[j] < a[i])
        f[i] = max(f[i], f[j] + 1);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = max(ans, f[i]);
  cout << ans << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N(1e4 + 2);
int a[N], b[N];
int f[N][N];
int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      f[i][j] = max(f[i - 1][j], f[i][j - 1]);
      if (a[i] == b[j])
        f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
    }
  }
  cout << f[n][n] << endl;

  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(1e2 + 10);
int f[N][N], v[N], w[N];
int n, m;

void f_duochongBag()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
      if (j < v[i])
        f[i][j] = f[i - 1][j];
      else
        f[i][j] = max(f[i - 1][j], f[i][j - w[i]] + v[i]);
  }
  cout << f[n][m];
}

void f_wanquanBag()
{
}
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> w[i] >> v[i];
  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
      if (j < v[i]) // 转不下，没得选；
        f[i][j] = f[i - 1][j];
      else // 装得下，选或不选
        f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
  }
  cout << f[n][m] << endl;
  return 0;
} */

/*
#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N(1e4 + 10);
// vector<vector<int>> dp(n, vector<int>(n + 1, 0));
int dp[N][N] = {0};
struct node
{
  int v;
  int t;
} node[N];
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    cin >> node[i].t >> node[i].v;
  }
  for (int i = 1; i <= m; i++)
  {
    for (int j = node[i].t; j <= n; j++)
    {
      if (node[i].t <= j)
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - node[i].t] + node[i].v);
      }
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  cout << dp[m][n] << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
long long n, m;
const int N(1e4 + 30);
const int M(1e7 + 10);
// vector<vector<int>> dp(n, vector<int>(n + 1, 0));
// int dp[N][N] = {0};
long long dp[M] = {0};
struct node
{
  long long v;
  long long t;
} node[N];
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    cin >> node[i].t >> node[i].v;
  }
  for (int i = 1; i <= m; i++)
  {
    for (int j = node[i].t; j <= n; j++)
    {
      dp[j] = max(dp[j], dp[j - node[i].t] + node[i].v);
    }
  }
  cout << dp[n] << endl;
  return 0;
}  */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(104);
const int M(1e4 + 19);
int w[N], v[N];
int dp[M] = {0};
int n, m;
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = m; j >= w[i]; j--)
      dp[j] += dp[j - w[i]];
  }
  cout << dp[m] << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(30);
const int M(3e4 + 19);
int n, m;
int dp[M] = {0};
int v[N], w[N];
int main()
{

  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    cin >> v[i] >> w[i];
    w[i] *= v[i];
  }
  for (int i = 1; i <= m; i++)
  {
    for (int j = n; j >= v[i]; j--)
      dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
  }
  cout << dp[n] << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int s, n, d;
const int N(1e5 + 10);
const int M(1e7);
int w[N], v[N];
int dp[M];
int main()
{
  cin >> s >> n >> d;
  for (int i = 1; i <= d; i++)
    cin >> w[i] >> v[i];
  // 对每一年都多重背包
  for (int i = 1; i <= n; i++)
  {
    // 一份卷可以买多少次
    int m = s / 1000;
    // 枚举每份卷
    for (int j = 1; j <= d; j++)
    {
      // 一份卷可买多次
      for (int k = (w[j] / 1000); k <= m; ++k)
      {
        if (k >= (w[j] / 1000))
          dp[k] = max(dp[k], dp[k - (w[j] / 1000)] + v[j]);
      }
    }
    s += dp[m];
    memset(dp, 0, sizeof(dp));
  }
  cout << s << endl;
  return 0;
}
 */
/*
#include <stdio.h>
#include <iostream>
#include <memory.h>
using namespace std;
int w[100000];
int v[100000];
int dp[100000];
int s, n, d;
int main()
{
 scanf("%d%d%d", &s, &n, &d);
 for (int i = 1; i <= d; ++i)
 {
   scanf("%d%d", &w[i], &v[i]);
 }
 for (int i = 1; i <= n; ++i)
 {
   int m = s / 1000;
   for (int j = 1; j <= d; ++j)
   {
     for (int k = w[j] / 1000; k <= m; ++k)
     {
       if (k >= w[j] / 1000)
         dp[k] = max(dp[k], dp[k - w[j] / 1000] + v[j]);
       //				printf("%d ",dp[k]);
     }
     //			printf("\n");
   }
   s += dp[m];
   memset(dp, 0, sizeof(dp));
 }
 printf("%d", s);
} */
/*
#include <bits/stdc++.h>
using namespace std;
int n;
const int N(1e4 + 10);
int w[N], v[N], num[N];
int dp[N];
int main()
{
  int h1, m1, h2, m2;
  scanf("%d:%d%d:%d%d", &h1, &m1, &h2, &m2, &n);
  int t = (h2 * 60 + m2) - (h1 * 60 + m1);
  for (int i = 1; i <= n; i++)
  {
    cin >> w[i] >> v[i] >> num[i];
    if (num[i] == 0)
      num[i] = 0x3f3f3f;
  }
  for (int i = 1; i <= n; i++)
  {
    int res = num[i];
    for (int k = 1; k <= res; res -= k, k *= 2)
      for (int j = t; j >= k * w[i]; j--)
        dp[j] = max(dp[j], dp[j - w[i] * k] + v[i] * k);
    for (int j = t; j >= w[i] * res; j--)
      dp[j] = max(dp[j], dp[j - w[i] * (res)] + v[i] * res);
  }
  cout << dp[t] << endl;
  return 0;
} */

/*
#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N(1e2 + 2);
const int p(1e6 + 7);
int dp[N] = {0}, num[N];
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> num[i];
  dp[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    int res = num[i];
    for (int k = 1; k <= res; res -= k, k *= 2)
    {
      for (int j = m; j >= num[i] * k; j--)
        dp[j] = max(dp[j], dp[j - num[i] * k]);
    }
    for (int j = res; j >= num[i] * res; j--)
    {
      dp[j] = max(dp[j], dp[j - num[i] * res]);
    }
  }
  cout << dp[m];
  return 0;
} */
/*
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int N(1e4);
int v[N], w[N], a[N];
int n, m;
vector<int> c[N];
int f[N];
int main()
{
  cin >> m >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> w[i] >> v[i] >> a[i];
    c[a[i]].push_back(i);
  }
  for (int i = 1; i <= 100; i++)
  {
    for (int j = m; j; j--)
    {
      for (auto k : c[i])
        if (j >= w[k])
          f[j] = max(f[j], f[j - w[k]] + v[k]);
    }
  }
  cout << f[m] << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(1e3);
int w[N], v[N], t[N], f[N][N];
int n, m;
int k;
int main()
{
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++)
  {
    cin >> w[i] >> t[i] >> v[i];
  }
  for (int i = 1; i <= k; i++)
  {
    for (int j = n; j >= w[i]; j--)
    {
      for (int x = m; x >= t[i]; x--)
      {
        f[j][x] = max(f[j][x], f[j - w[i]][x - t[i]] + v[i]);
      }
    }
  }
  cout << f[n][m];
  return 0;
} */

/*
#include <bits/stdc++.h>
using namespace std;
int n, m, k;
const int N(1e3 + 10);
int w[N], v[N], t[N];
int dp[N][N];
int main()
{
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    cin >> v[i] >> w[i] >> t[i];
  for (int i = 1; i <= n; i++)
  {
    for (int j = m; j >= w[i]; j--)
    {
      for (int x = k; x >= t[i]; x--)
      {
        dp[j][x] = max(dp[j][x], dp[j - w[i]][x - t[i]] + v[i]);
      }
    }
  }
  cout << dp[m][k] << endl;
  return 0;
} */

#include <bits/stdc++.h>
using namespace std;
/* const int N(1e3);
int n;
bool prime[N];
void is_prime()
{
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  int p = 2;
  while (p * p <= n)
  {
    if (prime[p] == true)
    {
      for (int i = p * p; i <= n; i += p)
      {
        prime[i] = false;
      }
    }
    p++;
  }
}

void is_prime()
{
  int arr[N];
  memset(arr, true, sizeof(arr));
  vector<int> ispm(n + 1);
  arr[0] = arr[1] = false;
  for (int i = 2; i <= n; i++)
  {
    if (arr[i])
      ispm.push_back(i);
    for (int j = 0; j < ispm.size() && i * ispm[j] <= n; j++)
    {
      arr[i * ispm[j]] = false;
      if (i % ispm[j] == 0)
        break;
    }
  }
}
int main()
{
  cin >> n;

  // is_prime();
  // for (int i = 1; i <= n; i++)
  //   if (prime[i] == true)
  //     cout << i << endl;
  return 0;
} */

/*
#include <bits/stdc++.h>
using namespace std;
int l, r;
// const int N(1e9 + 100);
// int arr[N];
const int MAXN(1e9 + 2000);
bool isnp[MAXN];
vector<int> primes; // 质数表
void init(int n)
{
  for (int i = 2; i <= n; i++)
  {
    if (!isnp[i])
      primes.push_back(i);
    for (int p : primes)
    {
      if (p * i > n)
        break;
      isnp[p * i] = 1;
      if (i % p == 0)
        break;
    }
  }
}
int main()
{
  cin >> l >> r;
  // l = 2, r = 11;
  init(r);
  int ans = 0;
  for (int i = l; i <= r; i++)
  {
    if (isnp[i] == false)
      ans++;
  }
  cout << ans << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int n, k;
const int N(1e5 + 10);
double a[N];
int check(double x)
{
  int tot = 0;
  for (int i = 1; i <= n; i++)
    tot += (a[i] / x);
  if (tot >= k)
  {
    return 1;
  }
  else
    return 0;
}
main()
{
  cin >> n >> k;
  double r = 0;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    a[i] *= 100;
  }
  double l = 0;
  r = INT_MAX;
  while (r - l >= 1e-5)
  {
    double mid = (l + r + 1) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  // char s[12];
  // sprintf(s + 1, "%.3f", l / 100);
  // s[strlen(s + 1)] = '\0';
  // printf("%s", s + 1);
  printf("%.2lf", r / 100);
  return 0;
} */

// #include <bits/stdc++.h>
/* #include <iostream>
#include <cmath>
using namespace std;
long long n;
const int N(1e5 + 10);
char s[N];

int myatoi(const char *s)
{
  int res = 0;
  int sign = 1;
  int i = 0;
  while (s[i] == ' ')
    i++;
  while (s[i] == '+' || s[i] == '-')
  {
    sign = (s[i] == '-') ? -1 : 1;
    i++;
  }
  while (s[i] >= '0' && s[i] <= '9')
  {
    res = res * 10 + (s[i] - '0');
  }
  return res;
}


int myatof(const char *s)
{
  int res = 0;
  int sign = 1;
  int pow = 0;
  int i = 0;
  while (s[i] == ' ')
    i++;
  while (s[i] == '+' || s[i] == '-')
  {
    sign = (s[i] == '-') ? -1 : 1;
    i++;
  }
  while (s[i] >= '0' && s[i] <= '9')
  {
    res = res * 10 + (s[i] - '0');
    i++;
  }
  if (s[i] == '.')
  {
    i++;
    while (s[i] >= '0' && s[i] <= '9')
    {
      res = res * 10.0 + s[i] - '0';
      pow *= 10.0;
      i++;
    }
  }
  return sign * res / pow;
}
int main()
{
  cin >> s;
  // n = atoll(s);
  n = strtol(s, NULL, 10);
  n = strtoll(s, NULL, 16);
  n = strtold(s, NULL);
  cout << n << endl;
  return 0;
} */
/*


#include <bits/stdc++.h>
using namespace std;
const int N(1e6 + 10);
int a[N];
int n, k;
deque<int> deq;
int main()
{
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
  {
    while (!deq.empty() && a[deq.back()] > a[i])
    {
      deq.pop_back();
    }
    deq.push_back(i);
    if (i >= k)
    {
      while (!deq.empty() && deq.front() < i - k + 1)
      {
        deq.pop_front();
      }
      cout << a[deq.front()] << ' ';
    }
  }
  cout << endl;
  deq.clear();
  for (int i = 1; i <= n; i++)
  {
    while (!deq.empty() && a[deq.back()] <= a[i])
      deq.pop_back();
    deq.push_back(i);
    if (i >= k)
    {
      while (!deq.empty() && deq.front() < i - k + 1)
        deq.pop_front();
      cout << a[deq.front()] << " ";
    }
  }

  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int n, k, c, a[10000], q[100000];
int main()
{
  cin >> n >> k >> c;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int front = 1, rear = 0, ans = 0;
  for (int i = 1; i <= n; i++)
  {
    // 去尾
    while (front <= rear && a[q[rear]] <= a[i])
    {
      rear--;
    }
    q[++rear] = i;
    if (i >= c)
    {
      if (a[q[front]] <= k)
        ++ans;
      if (q[front] == i - c + 1) // 去头；
        ++front;
    }
  }
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{

  return 0;
} */
/*


#include <bits/stdc++.h>
using namespace std;
class bon
{
  friend std::ostream &operator<<(std::ostream &out, bon &b);

public:
  bon(int age, const char *name)
  {
    this->age = age;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
  }
  ~bon()
  {
    if (this->name != nullptr)
    {
      delete[] this->name;
    }
  }
  bon &operator=(const bon &other)
  {
    if (this->name != nullptr)
    {
      delete[] this->name;
      this->name = nullptr;
      this->name = new char[strlen(other.name) + 1];
      strcpy(this->name, other.name);
      this->age = other.age;
    }
    return *this;
  }

private:
  int age;
  char *name;
};
std::ostream &operator<<(std::ostream &out, bon &b)
{
  std::cout << b.name << std::endl;
  std::cout << b.age << std::endl;
  return out;
}
int main()
{
  bon b1(18, "hapy");
  bon b2(18, "bonon");
  cout << b1;
  cout << b2;
  b1 = b2;
  cout << b1;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int n;
int m;
const int N(1e4 + 10);
int a[N] = {0};
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= m; i++)
  {
    int x, y;
    cin >> x >> y;
    for (int j = x; j <= y; j++)
    {
      a[j]++;
    }
  }
  int ans = 0;
  for (int j = 0; j <= n; j++)
  {
    if (a[j] == 0)
      ans++;
  }
  cout << ans;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
  cin >> s;
  int tot = 0;
  int j = 1;
  for (int i = 0; i < s.size() - 2; i++)
  {
    if (s[i] != '-')
      tot += (s[i] - '0') * j, j++;
  }

  int t = tot % 11;
  // cout << t;
  if (t == 10)
  {
    if (s[s.size() - 1] == 'X')
    {
      cout << "Right" << endl;
      return 0;
    }
    else
    {
      s[s.size() - 1] = 'X';
      cout << s << endl;
      return 0;
    }
  }
  if (t == (s[s.size() - 1] - '0'))
  {
    cout << "Right" << endl;
    return 0;
  }
  else
  {
    s[s.size() - 1] = '0' + t;
    cout << s << endl;
    return 0;
  }
  return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;

int l, r;
int main()
{
  cin >> l >> r;
  int ans = 0;
  for (int i = l; i <= r; i++)
  {
    string s = to_string(i);
    ans += count(s.begin(), s.end(), '2');
  }
  cout << ans << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int n;
const int N(1e2 + 10);
int a[N];
unordered_set<int> nums(N);
unordered_set<int> ans(N);
int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i], nums.insert(a[i]);
  for (int i = 1; i <= n; i++)
  {
    for (int j = i + 1; j <= n; j++)
    {
      int tem = a[i] + a[j];
      auto it = nums.find(tem);
      if (it != nums.end())
      {
        ans.insert(*it);
      }
    }
  }
  cout << ans.size() << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N(1e6 + 10);
int a[N];
int main()
{
  cin >> n >> m;
  int t = m + 1;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int tot = 0;
  while (t <= n + m)
  {
    for (int i = 1; i <= m; i++)
    {
      a[i]--;
      if (a[i] == 0)
      {
        a[i] = a[t++];
      }
    }
    tot++;
  }
  cout << tot << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int win[62503];
int w = 0, l = 0;
int main()
{
  char c;
  for (int i = 1; cin >> c && c != 'E'; i++)
  {
    if (c == 'W')
      win[i] = 1;
    else
      win[i] = 2;
  }
  for (int i = 1; 1; i++)
  {
    if (win[i] == 1)
      w++;
    if (win[i] == 2)
      l++;
    if (win[i] == 0)
    {
      cout << w << ":" << l << endl;
      cout << endl;
      break;
    }
    if (fabs(w - l) >= 2 && max(w, l) >= 11)
    {
      cout << w << ":" << l << endl;
      w = l = 0;
    }
  }
  w = l = 0;
  for (int i = 1; 1; i++)
  {
    if (win[i] == 1)
      w++;
    if (win[i] == 2)
      l++;
    if (win[i] == 0)
    {
      cout << w << ":" << l << endl;
      cout << endl;
      break;
    }
    if (fabs(w - l) >= 2 && max(w, l) >= 21)
    {
      cout << w << ":" << l << endl;
      w = l = 0;
    }
  }
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int n;
int a[] = {0, 100, 50, 10, 5, 1};
int main()
{
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= 5; i++)
  {
    if (n / a[i] >= 1)
      ans += n / a[i], n %= a[i];
  }
  cout << ans << endl;
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int n;
int k;
const int N(1e6 + 10);
int a[N];
int main()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n, [](int a, int b)
       { return a > b; });
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += a[i];
    if (ans >= k)
    {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int n, m, k, l, d;
const int N(1e6 + 10);
int h[N] = {0}, s[N] = {0}, f[N] = {0};
int main()
{

  cin >> n >> m >> k >> l >> d;
  for (int i = 1; i <= d; i++)
  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) // 列方向，用水平隔开
    {
      s[min(y1, y2)]++;
    }
    if (y1 == y2)
    {
      h[min(x1, x2)]++;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    f[i] = i;
  }
  // 选择排序，比较两个，交换下标与值，从大到小排序
  for (int i = 1; i <= m; i++)
  {
    for (int j = i + 1; j <= m; j++)
    {
      if (h[j] > h[i])
      {
        swap(h[i], h[j]);
        swap(f[i], f[j]);
      }
    }
  }
  sort(f, f + k + 1);
  for (int i = 1; i <= k; i++)
  {
    cout << f[i];
    if (i != k)
    {
      cout << ' ';
    }
  }
  cout << endl;
  for (int i = 1; i <= n; i++)
  {
    f[i] = i;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = i + 1; j <= n; j++)
    {
      if (s[j] > s[i])
      {
        swap(s[i], s[j]);
        swap(f[i], f[j]);
      }
    }
  }
  sort(f, f + l + 1);
  for (int i = 1; i <= l; i++)
  {
    cout << f[i];
    if (i != l)
    {
      cout << ' ';
    }
  }
  return 0;
} */

/*

#include <string>
#include <bits/stdc++.h>
using namespace std;
int k, n;
const int N(1e6 + 10);
int a[N];

int check(int x, int l)
{
  l = 0;
}
int main()
{
  cin >> k >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int ans = 0;
  sort(a + 1, a + 1 + n);
  int l = 1, r = n;
  while (l <= r)
  {
    if (a[l] + a[r] <= k)
      l++, r--, ans++;
    else
      ans++, r--;
  }
  cout << ans << endl;
  return 0;
}
 */
/*

#include <bits/stdc++.h>
using namespace std;
typedef array<int, 500> arr;
arr mul(arr &a, arr &b)
{
arr c{0};
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
arr quickpow(arr &a, int b)
{
arr res{1};
for (; b; b >>= 1)
{
 if (b & 1)
   res = mul(res, a);
 a = mul(a, a);
}
return res;
}

int quickpow(int a, int b)
{
if (b == 0)
 return 1;
int res = quickpow(a, b / 2);
if (b & 1)
 return 1LL * res * res * a;
else
 return res * res;
}
int main()
{
int a, b;
cin >> a >> b;
cout << quickpow(a, b);
return 0;
} */

/*
#include <bits/stdc++.h>
using namespace std;
vector<int> div(vector<int> &a, int b)
{
  int r = 0;
  bool f = true;
  vector<int> c;
  for (int i = a.size() - 1; i >= 0; i--)
  {
    r = r * 10 + a[i];
    int x = r / b;
    if (!f || x)
    {
      c.push_back(x);
      f = false;
    }
    r %= b;
  }
  c.reserve(c.size());
  cout << r << endl;
  while (c.size() > 0 && c.back() == 0)
    c.pop_back();
  return c;
}
int main()
{
  vector<int> a{1, 2};
  int b = 3;
  a = div(a, b);
  for (int i = a.size() - 1; i >= 0; i--)
  {
    cout << a[i] << ' ';
  }
  return 0;
}
 */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(25);
int n;
int path[N];
bool col[N], dg[N], udg[N];
int ans = 0;
void dfs(int u)
{
  if (u == n)
  {
    ans++;
    if (ans < 4)
    {
      for (int i = 0; i < n; i++)
      {
        cout << path[i] << ' ';
      }
      cout << endl;
    }
    return;
  }

  for (int i = 1; i <= n; i++)
  {
    if (!col[i] && !dg[u + i] && !udg[n + i - u])
    {
      path[u] = i;
      col[i] = dg[u + i] = udg[n + i - u] = true;
      dfs(u + 1);
      col[i] = dg[u + i] = udg[n + i - u] = false;
    }
  }
}
int main()
{
  cin >> n;
  dfs(0);
  cout << ans << endl;
  return 0;
} */
/*
#include <iostream> //个人不建议采用头文件，可能和定义的变量或名字起冲突，从而引起编译错误；
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
int a[100], b[100], c[100], d[100];
// a数组表示的是行；
// b数组表示的是列；
// c表示的是左下到右上的对角线；
// d表示的是左上到右下的对角线；
int total; // 总数:记录解的总数
int n;     // 输入的数，即N*N的格子，全局变量，搜索中要用
int print()
{
  if (total <= 2) // 保证只输出前三个解，如果解超出三个就不再输出，但后面的total还需要继续叠加
  {
    for (int k = 1; k <= n; k++)
      cout << a[k] << " "; // for语句输出
    cout << endl;
  }
  total++; // total既是总数，也是前三个排列的判断
}
void queen(int i) // 搜索与回溯主体
{
  if (i > n)
  {
    print(); // 输出函数，自己写的
    return;
  }
  else
  {
    for (int j = 1; j <= n; j++) // 尝试可能的位置
    {
      if ((!b[j]) && (!c[i + j]) && (!d[i - j + n])) // 如果没有皇后占领，执行以下程序
      {
        a[i] = j; // 标记i排是第j个
        b[j] = 1; // 宣布占领纵列
        c[i + j] = 1;
        d[i - j + n] = 1;
        // 宣布占领两条对角线
        queen(i + 1); // 进一步搜索，下一个皇后
        b[j] = 0;
        c[i + j] = 0;
        d[i - j + n] = 0;
        // （回到上一步）清除标记
      }
    }
  }
}
int main()
{
  cin >> n;      // 输入N*N网格，n已在全局中定义
  queen(1);      // 第一个皇后
  cout << total; // 输出可能的总数
  return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(25);
int n;
int path[N];
bool col[N], dg[N], udg[N], row[N];
int ans = 0;

void dfs(int x, int y, int s)
{
  if (y == n)
  {
    y = 0;
    x++;
  }
  if (x == n)
  {
    if (s == n)
    {
      ans++;
      if (ans <= 2)
      {
        for (int i = 0; i < n; i++)
        {
          cout << path[i] << ' ';
        }
        cout << endl;
      }
    }
  }
  // 不放皇后、列数加加
  dfs(x, y + 1, s);

  // 放黄后
  if (!row[x] && !col[x + y] && !udg[x - y + n])
  {
    path[s] = x;
    row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
    dfs(x, y + 1, s + 1);
    row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
  }
}
int main()
{
  cin >> n;
  dfs(0, 0, 0);
  return 0;
} */

/* #include <bits/stdc++.h>

using namespace std;

int n, m;
const int N(40);
int a[N][N];
int x, y;
int c, d;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<pair<int, int>> path;
vector<vector<pair<int, int>>> res;


void dfs(int x, int y)
{
  if (x == c && y == d)
  {
    res.push_back(path);
    return;
  }
  for (int i = 0; i < 4; i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != 0)
    {
      a[nx][ny] = 0;
      path.push_back(make_pair(nx, ny));
      dfs(nx, ny);
      nx -= dx[i];
      ny -= dy[i];
      a[nx][ny] = 1;
    }
  }
}


int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
      cin >> a[i][j];
  }
  cin >> x >> y;
  cin >> c >> d;
  a[x][y] = 0;
  path.push_back(make_pair(x, y));
  dfs(x, y);
  return 0;
} */