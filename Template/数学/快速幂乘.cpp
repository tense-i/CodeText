#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// 二分快速幂
int p;
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

// modP
// 快速幂
const int P(1e9);
int n;
int quickpow(int a, int b)
{
    long long ans = 1;
    for (; n; n >>= 1)
    {
        if (n & 1)
            ans *= a, ans %= P;
        a *= a, a %= P;
    }
    return ans;
}
// 快速乘
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

int quickpow(int a, int b)
{
    long long ans = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans *= a;
        a *= a; // 倍增、提前计算好a的次幂
    }
    return ans;
}

int main()
{

    return 0;
}