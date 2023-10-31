/* #include <bits/stdc++.h>
using namespace std;
// int n;
string n;
int k;
int a[300];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n.size(); i++)
    {
        a[i] = n[i] - '0';
    }
    int len = n.size();
    int j = 0;
    for (int v = 1; v <= k; v++)
        for (int i = 0; i < len; i++)
        {
            if (a[i] > a[i + 1])
            {
                for (j = i; j < len; j++)
                {
                    a[j] = a[j + 1];
                }
                len--;
                break;
            }
        }
    int m = 0;
    for (int i = 0; i < len; i++)
        if (a[i] > 0)
        {
            m = i;
            break;
        }
    for (int i = m; i < len; i++)
        cout << a[i];
    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> heap;
int n;
int main()
{
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        heap.push(x);
    }
    int res = 0;
    while (heap.size() > 1)
    {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();
        res += a + b;
        heap.push(a + b);
    }
    cout << res << endl;
    return 0;
} */

/*
#include <bits/stdc++.h>
using namespace std;
deque<int> deq;
const int N(5e5 + 10);
int a[N] = {0};
int s[N] = {0};
int n, m;
int ans = -233333333;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        while (!deq.empty() && s[i] < s[deq.back()])
        {
            deq.pop_back();
        }
        deq.push_back(i);
        if (i >= m)
        {
            while (!deq.empty() && deq.front() < i - m + 1)
            {
                deq.pop_front();
            }
            ans = max(ans, s[i] - s[deq.front()]);
        }
    }
    cout << ans;
    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
    int k;
    int v;
} a[10001];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].v;
        a[i].k = i;
    }
    sort(a + 1, a + 1 + n, [](node &i, node &j)
         { return i.v < j.v; });
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].k << ' ';
        ans += a[i].v * (n - i);
    }
    cout << endl;
    printf("%.2f", ans * 1.0 / n);

    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int n;
struct node
{
    int l, r;
} a[10005];

vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}
vector<int> div(vector<int> a, int b)
{
    vector<int> c;
    bool is_first = true;
    for (int i = a.size() - 1, t = 0; i >= 0; i--)
    {
        t = t * 10 + a[i];
        int x = t / b;
        if (!is_first || x)
        {
            is_first = false;
            c.push_back(x);
        }
        t %= b;
    }
    reverse(c.begin(), c.end());
    return c;
}

int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r;
    }
    sort(a + 1, a + n + 1, [](node &a, node &b)
         { return a.l * a.r < b.l * b.r; });
    vector<int> s(1, 1);
    // vector<int> res(1, 0);
    for (int i = 0; i < n; i++)
    {
        s = mul(s, a[i].l);
    }
    s = div(s, a[n].r);
    if (s.back() == 0)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = s.size() - 1; i >= 0; i--)
    {
        cout << s[i];
    }
    return 0;
} */

/*
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 1010;

int n;
PII p[N];

vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

vector<int> div(vector<int> a, int b)
{
    vector<int> c;
    bool is_first = true;
    for (int i = a.size() - 1, t = 0; i >= 0; i--)
    {
        t = t * 10 + a[i];
        int x = t / b;
        if (!is_first || x)
        {
            is_first = false;
            c.push_back(x);
        }
        t %= b;
    }
    reverse(c.begin(), c.end());
    return c;
}

vector<int> max_vec(vector<int> a, vector<int> b)
{
    if (a.size() > b.size())
        return a;
    if (a.size() < b.size())
        return b;
    if (vector<int>(a.rbegin(), a.rend()) > vector<int>(b.rbegin(), b.rend()))
        return a;
    return b;
}

int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        p[i] = {a * b, a};
    }
    sort(p + 1, p + n + 1);

    vector<int> product(1, 1);

    vector<int> res(1, 0);
    for (int i = 0; i <= n; i++)
    {
        if (i)
            res = max_vec(res, div(product, p[i].first / p[i].second));
        product = mul(product, p[i].second);
    }

    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
    cout << endl;
    return 0;
} */

/*

#include <bits/stdc++.h>
using namespace std;
string s1, s2;
vector<int> a, b;

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
int main()
{
    cin >> s1 >> s2;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        a.push_back(s1[i] - '0');
    }
    for (int i = s2.size() - 1; i >= 0; i--)
    {
        b.push_back(s2[i] - '0');
    }
    a = mul(a, b);
    for (int i = a.size() - 1; i >= 0; i--)
        cout << a[i];
    return 0;
} */

/*                                            \
#include <bits/stdc++.h>                      \
using namespace std;                          \
                                            \ \
int n;                                        \
                                            \ \
                                            \ \
set<int> a;                                   \
                                            \ \
vector<int> mul(vector<int> &a, int b)        \
{                                             \
    int t = 0;                                \
    vector<int> c;                            \
    for (int i = 0; i < a.size() || t; i++)   \
    {                                         \
        if (i < a.size())                     \
            t += a[i] * b;                    \
        c.push_back(t % 10);                  \
        t /= 10;                              \
    }                                         \
    return c;                                 \
}                                             \
int main()                                    \
{                                             \
    cin >> n;                                 \
    int tot = 0;                              \
    for (int i = 2; i < n + 2; i++)           \
    {                                         \
        tot += i;                             \
        a.insert(i);                          \
        if (tot >= n)                         \
        {                                     \
            break;                            \
        }                                     \
    }                                         \
    a.erase(tot - n);                         \
    vector<int> s(1, 1);                      \
    for (auto i : a)                          \
    {                                         \
        cout << i << ' ';                     \
        s = mul(s, i);                        \
    }                                         \
    cout << endl;                             \
    for (int i = s.size() - 1; i >= 0; i--)   \
    {                                         \
        cout << s[i];                         \
    }                                         \
    return 0;                                 \
} */
/* #include<iostream>
using namespace std;

const int N = 50010;
int a[N], n, len, m, mina = 1e9 + 1, b[N];

int check(int mid) // 检查，是否最短距离为mid，如果两石头间距小于mid，不满足，移走
{
    int cnt = 0;
    int i = 0, now = 0; // i表示目标位置，now为当前位置。
    while (i < n + 1)
    {
        i++;
        if (a[i] - a[now] < mid)
        { // 两石头间距离小于mid，mid不是最短距离，不满足，移走该石头
            cnt++;
        }
        else
        { // 符合，跳过去
            now = i;
        }
    }
    if (cnt <= m)
        return 1; // 移走的石头个数小于 M，就能保证了任意两剩下的石头间距大于等于最短距离mid，那移走M个，更能保证
    return 0;
}

int main()
{
    cin >> len >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < mina)
            mina = a[i];
    }
    a[0] = 0, a[n + 1] = len; // 首尾都有石头

    if (n == 0)
    { // 特判掉起点和终点之间没有石头的情况，可以想一下为什么。评论区中有答案。感谢 luojias 同学的hack数据！
        cout << len;
        return 0;
    }

    // 二分答案：检查每一个答案（最短距离mid）是否符合要求
    long long l = 1, r = 1e10;
    while (l < r) // 模板2
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid; // 要的是距离的最大，所以尽可能地往右走
        else
            r = mid - 1;
    }
    cout << l;
    return 0;
}
 */
/*


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll len, n, k;
const int N(1e6 + 10);
ll a[N];

inline bool check(int x)
{
    int y = k;
    int size = 0; // 确定当前的比较位置
    for (int i = 1; i < N; i++)
    {

        if (a[i] - size <= x)
        {
            size = a[i]; // 成立则移动比较位置，比较下一组
        }
        else
        {
            size = size + x; // 设置新的路标，前一个路标已满足，移动位置到新路标
            i--;             // 防止因为循环把之前的路标给移走了！,
            // 先减一for循环在加1，相当于没变，判断a[i]-sz了，
            y--; // 减少可用新路标数
        }
    }
    if (y >= 0)
    {
        return true;
    }
    return false;
}
int main()
{

    cin >> len >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 1, r = len;
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

int n, p;
const int N(1e5 + 10);

struct node
{
    int x, y;
} a[N];
int check(double ans)
{                       // 验证答案
    double q = p * ans; // 充电器最多提供的能量
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].x * ans <= a[i].y)
        {             // 若设备已有的能量大于使用时间需要的能量
            continue; // 忽略该设备
        }
        sum += (a[i].x * ans - a[i].y); // 否则用充电器充电，使设备已有的能量等于使用时间需要的能量，并记录需要的能量。
    }
    return sum <= q; // 最后比较需要的能量总和和充电器最多提供的能量。
}
int main()
{
    int ans = 0;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y, ans = max(ans, a[i].y);
    sort(a + 1, a + 1 + n, [](node &a, node &b)
         { return a.y < b.y; });
    double l = 0, r = ans;
    while (r - l >= 1e-8)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l;
    return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
int n = 0;
int main()
{
    cout << 0x3f3f3 << '\n'
         << 0x3f3f3 << endl;

    return 0;
}

 */
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll k;
const int N(1e5 + 9);
ll a[N];
int main()
{
    cin >> n;
    cin >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ll tot = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] + a[i - 1] > k)
        {
            ll temp = a[i] + a[i - 1] - k;
            tot += temp;
            a[i] -= temp;
        }
    }
    cout << tot << endl;
    return 0;
} */
/*
#include <bits/stdc++.h>

using namespace std;

int n;

const int N(1e6);
int a[N];
bool b[N] = {false};
int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, [](int i, int j)
         { return i > j; });
    long long tot = 0;
    tot += a[0] * a[0];
    int x = 0, y = n - 1;
    bool f = true;
    int j = n - 1;
    while (j--)
    {
        tot += 1LL * (a[x] - a[y]) * (a[x] - a[y]);

        swap(x, y);
        if (f == true)
            y++, f = false;
        else
            y--, f = true;
    }
    cout << tot << endl;
    return 0;
} */

/*
#include <bits/stdc++.h>
using namespace std;
int n;
const int N(1e6 + 100);
struct node
{

    int p;
    int w;
} a[N];
int t = 0;
int main()
{
    cin >> t;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].p >> a[i].w;
    }
    sort(a + 1, a + 1 + n, [](node &a, node &b)
         { return a.p < b.p; });
    long long tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (t >= 0)
        {
            if (t >= a[i].w)
            {
                t -= a[i].w;
                tot += (a[i].w * a[i].p);
            }
            else
            {
                // t -= a[i].w;
                tot += (t)*a[i].p;
                t -= a[i].w;
            }
        }
    }
    cout << tot << endl;
    return 0;
}
 */
/*
#include <bits/stdc++.h>
using namespace std;
int n;
int a[10000005];
int b[1000005], dp[10004][10004];
int m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    int ans = 0;
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m];
    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;

int n;

const int N(1e3 + 19);

int w[N], v[N];
int f[N][N];
int dp[N];
int t;
int main()
{

    cin >> t;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = t; j >= w[i]; j--)
        {
            if (w[i] <= t)
            {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[t] << endl;
    return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;

int n;
int m;
const int N(3e4 + 19);

int dp[N];

int a[30];
int b[30];
int main()
{

    cin >> n;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> a[i] >> x;
        b[i] = a[i] * x;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= a[i]; j--)
        {
            if (j >= a[i])
            {
                dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
            }
        }
    }

    cout << dp[n];
    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;

int n;
const int N(1e6);
int dp[N];
int v[N];
int w[N];
int f[N];
int num[N];
int main()
{
    int h1, m1, h2, m2;
    scanf("%d:%d%d:%d%d", &h1, &m1, &h2, &m2, &n);
    int t = 60 * (h2 - h1) + (m2 - m1);
    cout << t << endl;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> w[i] >> v[i] >> num[i];
        if (num[i] == 0)
        {
            num[i] = 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int res = num[i];
        for (int k = 1; k <= res; res -= k, k *= 2)
        {
            for (int j = t; j >= w[i] * k; j--)
                dp[j] = max(dp[j], dp[j - w[i] * k] + v[i] * k);
        }
        for (int j = t; j >= w[i] * res; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i] * res] + v[i] * res);
        }
    }
    cout << dp[t];
    return 0;
} */

/*
#include <bits/stdc++.h>
using namespace std;

int n;
const int N(1e6);
// int dp[N][N];
int v[N];
int w[N];
int f[N];
int num[N];
int m;
int main()
{
    cin >> n >> m;
    long long t = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        t *= num[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int res = num[i];
        for (int k = 1; k <= res; res -= k, k *= 2)
            for (int j = t; j >= w[i] * k; j--)
            {
                f[j] = max(f[j], f[j - w[i] * k] + v[i] * k);
            }
        for (int j = res; j >= w[i] * res; j--)
        {
            f[j] = max(f[j], f[j - w[i] * res] + v[i] * res);
        }
    }
    cout << f[m];
    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;


int a[] = {1, 5, 10, 20, 50, 100};
int dp[100000] = {0};
int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < 6; j++)
        {
            dp[j] = dp[j] + dp[j - a[i]];
        }
    }
    cout << dp[n];

    return 0;
} */
/*
#include <bits/stdc++.h>
#include <set>
using namespace std;

set<int>::iterator *it;
set<int> s;

int main()
{

    return 0;
} */

/*

#include <bits/stdc++.h>

using namespace std;

const int N(1e6 + 10);

int dp[N], w[N], v[N];
int n, m;
int num[N];
int p = 100007;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    for (int i = 1; i <= n; i++)
    {
        int res = num[i];
        for (int k = 1; k <= res; res -= k, k *= 2)
        {
            for (int j = m; j >= w[i] * k; j--)
            {
                dp[j] = (dp[j] + dp[j - k]) % p;
            }
        }
        for (int j = m; j >= w[i] * res; j--)
        {
            dp[j] = (dp[j] + dp[j - res]) % p;
        }
    }
    cout << dp[m];
    return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
int main()
{
    char a = 0x95; // dec=99;
    a = a << 4;
    printf("0x%x\n", a);
    a = 0x95;
    a = a >> 4;
    printf("0x%x\n", a);
    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 41;
int F[MAXN][MAXN][MAXN][MAXN], num[351], g[5], n, m, x;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    F[0][0][0][0] = num[1]; // 走一步
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        g[x]++;
    }
    for (int a = 0; a <= g[1]; a++)
        for (int b = 0; b <= g[2]; b++)
            for (int c = 0; c <= g[3]; c++)
                for (int d = 0; d <= g[4]; d++)
                {
                    // 计算当前的步数
                    int r = 1 + a + b * 2 + c * 3 + d * 4;
                    if (a != 0)                                                         // 走一步
                        F[a][b][c][d] = max(F[a][b][c][d], F[a - 1][b][c][d] + num[r]); // 加上走这一步的价值
                    if (b != 0)                                                         // 走两步
                        F[a][b][c][d] = max(F[a][b][c][d], F[a][b - 1][c][d] + num[r]);
                    if (c != 0)
                        F[a][b][c][d] = max(F[a][b][c][d], F[a][b][c - 1][d] + num[r]);
                    if (d != 0)
                        F[a][b][c][d] = max(F[a][b][c][d], F[a][b][c][d - 1] + num[r]);
                }
    cout << F[g[1]][g[2]][g[3]][g[4]];
    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 112;
    int n = -1;
    int *d = &a;
    float e = 3.14f;
    float *f = &e;
    return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
int a[5];
vector<int> tot;
long long ans = 0;
int main()
{
    priority_queue<int, vector<int>, less<int>> que;
    for (int i = 1; i <= 4; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= a[i]; j++)
        {
            int x;
            cin >> x;
            que.push(x);
        }
        while (que.size() != 1)
        {
            int t1 = que.top();
            que.pop();
            int t2 = que.top();
            que.pop();
            ans += min(t1, t2);
            que.push(t1 - t2);
        }
        if (que.size() == 1)
        {
            ans += que.top();
            que.pop();
        }
    }
    cout << ans << endl;
    return 0;
} */
/*
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int a[40][40];
bool vis[40][40];
int ans = 0;
const int dx[] = {-1, -1, -1, 0};
const int dy[] = {-1, 0, 1, -1};

void dfs(int x, int y, int sum)
{
    cout << "x==" << x << " y==" << y << endl;
    if (x == n)
    {
        // 求所以情况的最大
        ans = max(ans, sum);
        return;
    }
    bool flage = false;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny])
        {
            // 有一个角被选择
            flage = true;
            break;
        }
    }
    if (!flage)
    {
        vis[x][y] = true;
        // cout << a[x][y] << endl;
        // 搜下一层
        dfs(x + (y + 1) / m, (y + 1) % m, sum + a[x][y]);
        vis[x][y] = false;
    }
    // 可选择搜，但是不搜
    dfs(x + (y + 1) / m, (y + 1) % m, sum);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }
        ans = 0;
        memset(vis, false, sizeof(vis));
        dfs(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
 */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(1000);

char sta[N];

// 从1开始存栈
int top = 0;
char s[1000];
int main()
{
    register int i, j, k;
    scanf("%s", s);
    bool ok = true;
    int len = strlen(s);
    for (i = 0; i < len; i++)
    {

        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            sta[++top] = s[i], cout << top << "  i= " << i << endl;
        else if (top == 0)
        {
            ok = false;
        }
        else if (s[i] == ')')
        {
            if (sta[top] == '(')
                --top;
            else
            {
                ok = false;
            }
        }
        else if (s[i] == ']')
        {
            if (sta[top] == '[')
                top--, cout << top << endl;
            else
            {
                ok = false;
            }
        }
        else if (s[i] == '}')
        {
            if (sta[top] == '{')
                top--;
            else
            {
                ok = false;
            }
        }
    }
    if (top != 0)
    {
        ok = false;
    }
    if (ok == true)
        printf("ok");
    else
        printf("no");

    return 0;
} */