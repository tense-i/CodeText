
#include <bits/stdc++.h>
using namespace std;
const int N(1e2 + 10);
int f[N][N], v[N], w[N], ff[N];
int n, m;

// 01背包
// 朴素版
void f_01bag()
{
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
}
// 滚动数组压缩
void f_01bag()
{
    for (int i = 1; i <= n; i++)
    {
        // 必须从大到小；
        for (int j = m; j >= w[i]; j--)
        {
            ff[j] = max(ff[j], ff[j - w[i]] + v[i]);
        }
    }
}

//

void f_wanquan()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            // 第i个物品不取，则变成01背包
            if (j < v[i])
                f[i][j] = f[i - 1][j];
            else // 第i个物品取了，可以多取！！；
                f[i][j] = max(f[i - 1][j], f[i][j - w[i]] + v[i]);
    }
    cout << f[n][m];
}

void f_wanquan()
{
    for (int i = 1; i <= n; i++)
    {
        // 从大到小枚举j
        for (int j = v[i]; j <= m; j++)
            ff[j] = max(ff[j], ff[j - w[i]] + v[i]);
    }
    cout << ff[m];
}

// 将多重背包转为01背包

// 二进制分组优化
int l[N];
void f_douchong()
{
    for (int i = 1; i <= n; i++)
    {
        int res = l[i];
        for (int k = 1; k <= res; res -= k, k += 2)
        {
            for (int j = m; j >= v[i] * k; j--)
            {
                ff[j] = max(ff[j], ff[j - v[i] * res] + w[i] * res);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    cout << f[n][m] << endl;
    return 0;
}