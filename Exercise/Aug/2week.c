/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
long long dp[10005];
int m;

int w[10004];

int v[10004];

long long max(long long a, long long b)
{
    return (a > b ? a : b);
}

long long min(long long a, long long b)
{
    return (a > b ? a : b);
}

int h;

int main()
{
    scanf("%d%d%d", &h, &n, &m);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &v[i], &w[i]);
        sum += v[i];
    }
    if (sum <= h)
    {
        printf("Impossible");
        return 0;
    }
    memset(dp, 0, sizeof(dp));

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    for (int i = 1; i <= h; i++)
    {
        if (dp[i] >= h)
        {
            printf("%d", m - i);
            return 0;
        }
    }
    printf("Impossible");
    return 0;
}
 */

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int w[5005];
int v[5005];
int dp[50005];
int a[1001];

int n, m;
int k, r;

int max(int a, int b)
{
    return (a > b ? a : b);
}
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &r);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    qsort(a + 1, n, sizeof(int), cmp);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i <= m; i++)
        for (int j = k; j >= v[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    int tot = r - dp[k];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        tot -= a[i];
        if (tot >= 0)
            ans++;
    }
    printf("%d", ans);
    return 0;
}
 */
/* #include <stdio.h>
#include <string.h>

int n, s;
long long f[400];
int main()
{
    scanf("%d", &n);

    s = n * (n + 1) / 2;
    if (s & 1)
    {
        printf("0");
        return 0;
    }
    s /= 2;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = s; j >= i; j--)
            f[j] += f[j - i];
    printf("%d\n", (long long)f[s] / 2);
} */

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int n, m;
int dp[100009];
int w[200001];
int min(int a, int b)
{
    return a > b ? b : a;
}
int main()
{
    scanf("%d", &m);
    memset(dp, 127, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 1; i <= 18; i++)
        w[i] = (int)pow(i, 4);

    for (int i = 1; i <= 18; i++)
    {
        for (int j = w[i]; j <= m; j++)
        {
            dp[j] = min(dp[j], dp[j - w[i]] + 1);
        }
    }

    printf("%d", dp[m]);

    return 0;
}
*/

/* #include <stdlib.h>
#include <stdio.h>
#include <string.h>

int n, p, s;
int w[10000];
int v[10000];
int dp[10000];
int main()
{
    scanf("%d%d%d", &n, &p, &s);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &w[i], &v[i]);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = s; j >= w[i]; j--)
            dp[j] = __max(dp[j], dp[j - w[i]] + v[i]);
    }

    printf("%d", dp[s]);

    return 0;
}
 */
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int n;
int a[10001];
int s[50001];
int f[100][100];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    memset(f, 127, sizeof(f));
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            for (int k = j; k < j + i; k++)
                f[j][j + i] = __min(f[j][j + i], f[j][k] + f[k + 1][j + i] + s[j + i] - s[j - 1]);
        }
    }
    printf("%d", f[1][n]);
    return 0;
}
 */

/* #include <stdio.h>
typedef unsigned char *byte_p;

void show_bytes(byte_p start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    printf("&x== %p\n", x);
    show_bytes((byte_p)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_p)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_p)&x, sizeof(void *));
}

int main()
{
    int val = 0x87654321;
    printf("%p\n", val);
    printf("%d\n", val);
    byte_p valp = (byte_p)&val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
    show_bytes(valp, 4);
    show_bytes(valp, 5);
    return 0;
} */

/* #include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[4];
int dp[4004];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 3; i++)
        scanf("%d", &a[i]);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = a[i]; j <= n; j++)
        {
            if (dp[j - a[i]] != -1)
                dp[j] = max(dp[j], dp[j - a[i]] + 1);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
} */

/* #include <stdlib.h>
#include <stdio.h>
#include <string.h>

int a[7] = {0, 1, 2, 3, 5, 10, 20};
int num[7] = {0};
int dp[100000];

int main()
{
    for (int i = 1; i <= 6; i++)
        scanf("%d", &num[i]);
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= 6; i++)
    {
        int ret = num[i];
        for (int k = 1; k <= ret; ret -= k, k *= 2)
        {
            for (int j = 1000; j >= a[i]; j--)
            {
                if (dp[j - k * a[i]] != 0)
                    dp[j] = __max(dp[j], dp[j - k * a[i]] + 1);
            }
        }

        for (int j = 1000; j >= a[i] * ret; j--)
        {
            if (dp[j - ret * a[i]] != 0)
                dp[j] = __max(dp[j], dp[j - ret * a[i]] + 1);
        }
    }
    printf("%d", dp[1000]);
    return 0;
} */
