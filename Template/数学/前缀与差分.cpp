

#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;
const int N(5e6 + 12);
int a[N], d[N], s[N];
int n;
int p;


// 一维前缀和
void solve()
{
    // 每次对差分数组d操作
    while (p--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        // 左端点加d
        d[x] += z;
        // 右端点的下一个减去d
        d[y + 1] -= z;
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        // 还原原数组，对d数组求前缀和加上a数组的原数；
        d[i] += d[i - 1];
        a[i] += d[i];
    }
}









int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    return 0;
}