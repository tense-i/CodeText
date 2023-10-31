/* #include <bits/stdc++.h>
using namespace std;

const int N(1e6);
char a[N];
char s[N];
int top = 0;
int main()
{
    int n;
    cin >> n;
    cin >> a;
    s[++top] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (s[top] == a[i] + 32 || s[top] + 32 == a[i])
        {
            top--;
        }
        else
            s[++top] = a[i];
    }
    for (int i = 1; i <= top; i++)
        cout << s[i];
    cout << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int N(1e6);

int rear = 0;
int front = 1;

int q[N];

int a[N];

int main()
{
    int n;
    cin >> n;
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
        q[++rear] = i;
    int cnt = n;
    for (int i = 1; cnt; i++)
    {
        --a[q[front]];
        if (!a[q[front]])
        {
            ans[q[front]] = i, cnt--;
        }
        else
            q[++rear] = q[front];
        ++front;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
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
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;
int main()
{

    while (scanf("%d%d", &n, &m) != EOF)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            ans.push_back(x);
        }
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            ans.push_back(x);
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < n + m; i++)
        {
            if (i != n + m - 1)
            {
                cout << ans[i] << ' ';
            }
            else
                cout << ans[i];
        }
        cout << endl;
    }
    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;

const int N(1e4 + 10);

vector<int> edges[N];

int q[N];
int dist[N];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        memset(dist, 255, sizeof(dist));
        dist[x] = 0;
        int front = 1, rear = 0;
        q[++rear] = x;
        while (front <= rear)
        {
            int u = q[front];
            ++front;
            for (auto v : edges[u])
            {
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    q[++rear] = v;
                }
            }
        }
        cout << dist[y] << endl;
    }
} */
/*
#include <bits/stdc++.h>
using namespace std;

const int N(1e5 + 10);
int n, m;
int f[3][N];
int dist[N];
vector<pair<int, int>> edges[N];
int q[N];
bool vis[N] = {false};
void spfa(int s, int t)
{
    memset(dist, 127, sizeof(dist));
    memset(vis, false, sizeof(vis));
    int front = 1;
    int rear = 0;
    q[++rear] = s;
    vis[s] = true;
    dist[s] = 0;
    while (rear >= front)
    {

        int x = q[front];
        vis[x] = false;
        front++;
        for (auto i : edges[x])
        {
            int u = i.first;
            int v = i.second;
            if (dist[u] > dist[x] + v)
            {
                dist[u] = dist[x] + v;
                if (!vis[u])
                {
                    q[++rear] = u;
                    vis[u] = true;
                }
            }
        }
    }
}

int main()
{
    int a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        edges[x].push_back(make_pair(y, v));
        edges[y].push_back(make_pair(x, v));
    }
    cin >> a >> b >> c;
    int ans = INT_MAX, res = 0;
    spfa(a, n);
    memcpy(f[0], dist, sizeof(dist));
    spfa(b, n);
    memcpy(f[1], dist, sizeof(dist));
    spfa(c, n);
    memcpy(f[2], dist, sizeof(dist));
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, (f[0][i] + f[1][i] + f[2][i]));
        }
    cout << ans << endl;
    return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;

const int N(1e6);

struct edge
{
    int y, v;
    edge(int _y, int _v)
    {
        y = _y;
        v = _v;
    }
};
vector<edge> edges[N];
int n, m, dist[N];
bool vis[N]; */
/*
void dijkstra(int s, int t)
{
    memset(vis, false, sizeof(vis));
    memset(dist, 127, sizeof(dist));
    dist[s] = 0;
    for (;;)
    {
        int x = -1;
        for (int i = 1; i <= n; i++)
            if (!vis[i] && dist[i] < 1 << 30)
                if (x == -1 || dist[i] < dist[x])
                    x = i;
        if (x == t || x == -1)
            break;
        vis[x] = true;
        for (auto i : edges[x])
            dist[i.y] = min(dist[i.y], dist[x] + i.v);
    }
    cout << dist[t] << endl;
}
  */
// pair<dist,y>,默认按照dist排序

// 所有不在C集合的元素
/* set<pair<int, int>> que;
void dijkstra1(int s, int t)
{
    memset(dist, 127, sizeof dist);
    dist[s] = 0;
    que.clear();
    // 开始所以点都不在C集合中
    // for (int i = 1; i <= n; i++)
    // que.insert(make_pair(dist[i], i));
    que.insert(make_pair(0, s));
    while (!que.empty())
    {
        // 取出不在集合C中最短的点
        int x = que.begin()->second;
        que.erase(que.begin());
        if (x == t || dist[x] > 1 << 30)
            break;
        // 遍历与该点相连的点，进行松弛操作
        for (auto i : edges[x])
        {
            // 可松弛、松弛后的点有可能能更新最短路，重新加入队列进行选择
            if (dist[x] + i.v < dist[i.y])
            {
                que.erase(make_pair(dist[i.y], i.y));
                dist[i.y] = dist[x] + i.v;
                que.insert(make_pair(dist[i.y], i.y));
            }
        }
    }
}

priority_queue<edge, vector<edge>, greater<edge>> q;

void dijkstra3(int s, int t)
{
    memset(dist, 127, sizeof(dist));
    dist[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        auto x = q.top();
        q.pop();
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        edges[x].push_back(edge{y, v});
        // edges[y].push_back(edge{x, v});
    }
    dijkstra1(1, 3);
    cout << dist[3];
    return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;

const int N(1e4 + 20), M(1e5 + 20);

int n, m, k;

struct edge
{
    int w;
    int v;
    edge(int _w, int _v)
    {
        w = _w;
        v = _v;
    }
};
int dist[N], dist2[N], dist1[N];

struct node
{
    int dis;
    int v;
    bool operator>(const node &a) const
    {
        return a.dis < this->dis;
    }
};
vector<edge> edges[N], edges2[N];

void dijkstra(int s, vector<edge> edges[])
{
    // que.clear();
    priority_queue<node, vector<node>, greater<node>> que;
    memset(dist, 127, sizeof(dist));
    dist[s] = 0;
    que.push({0, s});
    while (!que.empty())
    {
        int u = que.top().v;
        que.pop();
        for (auto i : edges[u])
        {
            int v = i.v;
            if (dist[v] > dist[u] + i.w)
            {
                dist[v] = dist[u] + i.w;
                que.push({dist[v], v});
            }
        }
    }
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back({z, y});
        edges2[y].push_back({z, x});
    }
    dijkstra(k, edges2);
    memcpy(dist1, dist, sizeof(dist));
    dijkstra(k, edges);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i] + dist1[i]);
    }
    cout << ans << endl;
    return 0;
}
 */
/*
#include <bits/stdc++.h>

using namespace std;
const int N(1e3);
int g[N][N];
int f[N][N];

int n, m, k;
void floyd()
{

    for (int k = 1; k <= n; k++)
        for (int x = 1; x <= n; x++)
            for (int y = 1; y <= n; y++)
            {
                if (f[x][k] < 1 << 30 && f[k][y] < 1 << 30)
                    f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
            }
}
int main()
{
    memset(f, 127, sizeof(f));
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        f[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        f[x][y] = z;
    }
    floyd();
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        if (f[x][y] < 1 << 30)
            cout << f[x][y] << endl;
        else
            cout << "-1";
    }
    return 0;
} */

/*
#include <bits/stdc++.h>
using namespace std;
int d, p, c, f, s;
const int N(220);
struct edge
{
    int v;
    int w;
};
int sum = 0;
int ans = 0;
vector<edge> edges[N];
int res = 0;
bool vis[N] = {false};
void dfs(int u)
{
    res = max(res, sum);
    for (auto i : edges[u])
    {
        int v = i.v;
        int w = i.w;
        if (!vis[v])
        {
            vis[v] = true;
            sum += d;
            sum += w;
            dfs(v);
            sum -= d;
            sum -= w;
            vis[v] = false;
        }
    }
}
int main()
{
    cin >> d >> p >> c >> f >> s;
    for (int i = 1; i <= p; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[x].push_back({y, 0});
    }
    for (int i = 1; i <= f; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back({y, -z});
    }
    sum += d;
    vis[s] = true;
    dfs(s);
    cout << res << endl;
    return 0;
} */
/*

#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N(230), M(5e4 + 10);
int t[N];
int dist[N];

int g[N][N];

void floyd(int k)
{
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        if (g[i][k] < 1 << 30 && g[k][j] < 1 << 30)
            g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
int main()
{
cin >> n >> m;
memset(g, 127, sizeof(g));
for (int i = 0; i < n; i++)
    g[i][i] = 0;
for (int i = 0; i < n; i++)
    cin >> t[i];
for (int i = 0; i < m; i++)
{
    int x, y, z;
    cin >> x >> y >> z;
    g[x][y] = z;
    g[y][x] = z;
}
int q;
int cur = 0;
cin >> q;
while (q--)
{

    int x, y, z;
    cin >> x >> y >> z;
    while (t[cur] <= z && cur < n)
    {
        floyd(cur);
        cur++;
    }
    if (t[x] > z || t[y] > z)
    {
        cout << -1 << endl;
        continue;
    }
    cout << g[x][y] << endl;
}

return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
const int N(105);
struct edge
{
    int v;
    int w;
};

vector<edge> edges[N];
int dist[N];
int g[N][N];
int n, m;
bool vis[N];
int s;
int q[N];
void spfa(int s)
{
    memset(dist, 127, sizeof(dist));
    dist[s] = 0;
    int rear = 0, front = 1;
    q[++rear] = s;
    while (front <= rear)
    {
        int u = q[front++];
        for (auto i : edges[u])
        {
            if (dist[i.v] > dist[u] + i.w)
                dist[i.v] = dist[u] + i.w, q[++rear] = i.v;
        }
    }
}
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back({y, z});
    }
    spfa(s);
    int temp = pow(2, 31) - 1;
    for (int i = 1; i <= n; i++)
        if (dist[i] > 1 << 30)
            cout << temp << ' ';
        else
            cout << dist[i] << " ";

    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int y, z;
    edge(int _y, int _z) : y(_y), z(_z)
    {
        }
};

const int N(1e5);
vector<edge> edges[N];
int n, m;
int dist[N];
bool vis[N];

set<pair<int, int>> que;
void prim()
{
    memset(dist, 127, sizeof(dist));
    memset(vis, false, sizeof(vis));
    dist[1] = 0;
    que.clear();
    que.insert(make_pair(0, 1));
    int ans = 0, tot = 0;
    while (!que.empty())
    {
        int x = que.begin()->second;
        que.erase(que.begin());
        if (dist[x] > 1 << 30)
            break;
        vis[x] = true;
        tot++;
        ans += dist[x];
        for (auto ed : edges[x])
        {
            if (!vis[ed.y] && ed.z < dist[ed.y])
            {
                que.erase(make_pair(dist[ed.y], ed.y));
                dist[ed.y] = ed.z;
                que.insert(make_pair(dist[ed.y], ed.y));
            }
        }
    }
    if (tot != n)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back({y, z});
        edges[y].push_back({x, z});
    }
    prim();
    return 0;
} */
/*

#include <bits/stdc++.h>
using namespace std;

const int N(2e6 + 20);
long long ans = 0;
int s[N];
struct edge
{
    int u, v, w;
    bool operator<(const edge &oth)
    {
        return w > oth.w;
    }

} edges[N];
int n, m, k;

int f[N];

int find(int x)
{
    if (x != f[x])
        f[x] = find(f[x]);
    return f[x];
}

void kruskal()
{
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int x = find(edges[i].u);
        int y = find(edges[i].v);
        // 两个集合的代表元均为被占领的城市，不要合并，求依次加入最大的边，使得被占领的城市不连通
        if (s[x] && s[y])
            continue;

        f[x] = y;
        ans -= edges[i].w;
        if (s[x])
            s[y] = 1;
        else if (s[y])
            s[x] = 1;
    }
    cout << ans << endl;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        s[x] = 1;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        ans += edges[i].w;
    }
    sort(edges + 1, edges + 1 + n);
    // cout << edges[1].w << endl;
    kruskal();
    return 0;
} */
// #include <bits/stdc++.h>
/* #include <iostream>
#include <vector>

#include <algorithm>

using namespace std;
const int N(1e5);
int n, m;
struct po
{
    int x, y;
};
po posi[N];
vector<int> res1;
vector<po> res2;
int k[N];
int cnt = 0;
struct edge
{
    int u, v;
    long long w;
    bool operator<(const edge &oth) const
    {
        return w < oth.w;
    }

} edges[N];

int fa[N];

int find(int x)
{
    if (x != fa[x])
        fa[x] = find(fa[x]);
    return fa[x];
}

void kruskal()
{
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= cnt; i++)
    {
        int x = find(edges[i].u);
        int y = find(edges[i].v);
        if (x != y)
        {
            fa[x] = y;
            ans += edges[i].w;
            if (!edges[i].u)
            {
                res1.push_back(edges[i].v);
            }
            else
            {
                res2.push_back({edges[i].u, edges[i].v});
            }
        }
    }
    cout << ans << endl;
    cout << res1.size() << endl;
    for (auto i : res1)
        cout << i << ' ';
    cout << endl;
    cout << res2.size() << endl;
    if (res2.size() == 0)
        return;
    for (auto i : res2)
    {
        cout << i.x << ' ' << i.y << endl;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        posi[i].x = x;
        posi[i].y = y;
    }

    for (int i = 1; i <= n; i++)
    {
        edges[++cnt].u = 0;
        edges[cnt].v = i;
        cin >> edges[cnt].w;
    }

    for (int i = 1; i <= n; i++)
        cin >> k[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            edges[++cnt].u = i;
            edges[cnt].v = j;
            int ta = k[i] + k[j];
            int tb = abs(posi[i].x - posi[j].x);
            int tc = abs(posi[i].y - posi[j].y);
            edges[cnt].w = 1LL * ta * (tb + tc);
        }
    }
    sort(edges + 1, edges + cnt + 1);
    kruskal();
    return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
int t;
int n, m;
const int N(6e6 + 20);
struct edge
{
    int v, w;
};

vector<edge> edges[N];
int dis[N];
int q[N];
bool vis[N];
int cnt[N];

bool spfa()
{
    memset(dis, 127, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    memset(vis, false, sizeof(vis));
    dis[1] = 0;
    vis[1] = true;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (auto i : edges[u])
        {
            if (dis[u] + i.w < dis[i.v])
            {
                dis[i.v] = dis[u] + i.w;
                cnt[i.v] = cnt[u] + 1;
                if (cnt[i.v] >= n)
                {
                    return true;
                }
                if (!vis[i.v])
                {
                    q.push(i.v);
                    vis[i.v] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        // memset(edges, 0, sizeof(edges));
        for (int i = 1; i <= m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            if (z >= 0)
            {
                edges[x].push_back({y, z});
                edges[y].push_back({x, z});
            }
            else
                edges[x].push_back({y, z});
        }
        if (spfa())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
} */

/* #include <bits/stdc++.h>

using namespace std;
int n, m;

struct edge
{
    int v, w;
};

const int N(1e6);
const int mod(100003);
int ans[N];
int dist[N];
vector<edge> edges[N];
priority_queue<pair<int, int>> s;

void dijkstra()
{
    memset(dist, 127, sizeof(dist));
    dist[1] = 0;
    s.push(make_pair(0, 1));
    ans[1] = 1;
    while (!s.empty())
    {
        int u = s.top().second;
        s.pop();
        for (auto i : edges[u])
        {
            if (dist[i.v] > dist[u] + i.w)
            {
                dist[i.v] = dist[u] + i.w;
                ans[i.v] = ans[u];
                s.push(make_pair(-dist[i.v], i.v));
            }
            else
            {
                if (dist[i.v] == dist[u] + i.w)
                    ans[i.v] += ans[u], ans[i.v] %= mod;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[x].push_back({y, 1});
        edges[y].push_back({x, 1});
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
} */

/* #include <bits/stdc++.h>
using namespace std;
int n, m;
const int N(1e5 + 10);
struct edge
{
    int v;
    int w;
};

vector<edge> edges[N];
int dist[N] = {false};
int pre[N], path[N];
int que[N], vis[N];

void foyd(int s, int t)
{
    memset(dist, 127, sizeof(dist));
    dist[s] = 0;
    vis[s] = true;
    int front = 1, rear = 0;
    que[++rear] = s;
    while (front <= rear)
    {
        int u = que[front];
        vis[u] = false;
        front++;
        for (auto i : edges[u])
        {
            int v = i.v;
            int w = i.w;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pre[v] = u;
                if (!vis[v])
                    que[++rear] = v, vis[v] = true;
            }
        }
    }
    cout << dist[3] << endl;
    int l = 0;
    for (int i = t; i != s; i = pre[i])
    {
        path[++l] = i;
    }
    path[++l] = s;
    for (int i = l; i > 0; i--)
    {
        cout << path[i] << ' ';
    }
}
int k;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back({y, z});
        // edges[y].push_back({x, z});
    }
    foyd(1, 3);
    return 0;
}
 */

/*

 */

/* #include <bits/stdc++.h>
using namespace std;
const int N(1e4);
vector<int> edges[N + 1];
int d[N];
int n, m;

// 默认为大根堆，把值取反后为小根堆
priority_queue<int> q;
int l[N];
void toposort()
{
    int tot = 0;
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q.push(-i);
    while (!q.empty())
    {
        int x = -q.top();
        q.pop();
        l[++tot] = x;
        for (auto i : edges[x])
        {
            if (--d[i] == 0)
                q.push(-i);
        }
    }
    for (int i = 1; i <= tot; i++)
        cout << l[i] << ' ';
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        ++d[y];
    }
    toposort();
    return 0;
}
 */

/* #include <bits/stdc++.h>
using namespace std;

const int N(1e3);
long long dp[N][N] = {0};
int a[N][N] = {0};
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main()
{
    int n, m;
    int x, y;
    cin >> n >> m;
    cin >> x >> y;
    n += 2, m += 2, x += 2, y += 2;
    a[x][y] = 1;

    for (int i = 0; i < 8; i++)
    {
        a[dx[i] + x][dy[i] + y] = 1;
    }
/-0*
    dp[1][2] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            if (!a[i][j])
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    cout << dp[n][m] << endl;
    ;
    return 0;
}
 */

/* #include <iostream>
#include <cstring>
using namespace std;

const int N(1e6);
int n;
int dp[N];
long long dx[] = {1, 5, 10, 20, 50, 100};

int main()
{
    while (scanf("%d", &n) != EOF)

    {

        if (n == 0)
        {
            cout << 0 << endl;
            continue;
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int j = 0; j <= 5; j++)
        {
            for (int i = 1; i <= n; i++)
                if (i - dx[j] >= 0)
                {
                    dp[i] += dp[i - dx[j]];
                }
        }
        cout << dp[n] << endl;
    }
    return 0;
}
*/

/* #include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 0;
    int n = 0;
    int dx = 0;
    return 0;
} */
/*
#include <iostream>
#include <cstring>
using namespace std;

int n, m;
const int N(1e6 + 2);

int a[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (m--)
    {
        int x;
        cin >> x;
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (x <= a[mid])
                r = mid;
            else
                l = mid + 1;
        }
        if (x != a[l])
        {
            cout << -1 << endl;
            continue;
        }
        else
            cout << l << endl;
    }
    return 0;
} */

/*
#include <bits/stdc++.h>
using namespace std;

int n, c;

int a[200010];
int tot = 0;
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    // qsort(a + 1, n, sizeof(int), cmp);
    for (int i = 1; i <= n; i++)
    {
        int l = i + 1, r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (a[mid] >= a[i] + c)
            {
                r = mid;
            }
            else
                l = mid + 1;
        }
        int h = l;
        if (a[l] == a[i] + c)
            h = l;
        else
            continue;
        l = h - 1;
        r = n;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (a[mid] <= a[h])
                l = mid;
            else
                r = mid - 1;
        }
        tot += (l - h + 1);
    }
    printf("%d\n", tot);
    return 0;
}
 */
/* #include <stdio.h>
#include <stdlib.h>

int m, n;
int a[100005], b[100005];
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
long long tot = 0;
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    qsort(a + 1, m, sizeof(int), cmp);
    a[0] = -1e9;
    a[n + 1] = 1e9;

    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = m + 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (a[mid] >= b[i])
                r = mid;
            else
                l = mid + 1;
        }
        if (a[l] - b[i] <= b[i] - a[l - 1])
            tot += a[l] - b[i];
        else
            tot += b[i] - a[l - 1];
    }
    printf("%d\n", tot);

    return 0;
} */

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k, len;
int n;
int a[200010];

int check(int x)
{
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        tot += (a[i] / x);
    }
    if (tot >= k)
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    scanf("%d%d", &n, &k);
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        r = __max(a[i], r);
    }
    if (r < k)
    {
        printf("0");
        return 1;
    }
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    if (l < 1)
        printf("0");
    else
        printf("%d", l);
    return 0;
} */

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len, n, m;
long long a[100001];
int check(int x)
{
    int now = 0;
    int tot = 0;
    int i = 1;
    while (i <= n + 1)
    {

        if (a[i] - a[now] < x)
        {
            tot++;
        }
        else
        {
            now = i;
        }
        i++;
    }

    if (tot <= m)
    {
        return 1;
    }
    else
        return 0;
}
int main()
{
    scanf("%d%d%d", &len, &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[0] = 0;
    a[n + 1] = len;
    int l = 0, r = len;
    while (l < r)
    {
        long long mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d", l);
    return 0;
} */

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
long long a[100010];

int check(int x)
{
    int tot = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        if (sum + a[i + 1] > x)
            tot++, sum = 0;
    }
    if (tot + 1 <= m)
        return 1;
    else
        return 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    ;
    long long l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        r += a[i];
        if (l < a[i])
            l = a[i];
    }
    while (l < r)
    {
        long long mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d", l);
    return 0;
} */
/*
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N(1e4), M(1e3);

int h[N], e[M], ne[M], idx;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

struct edge{
    int u;
    int v;
    int w;
} edges[N];

int dist[N];
int pre[N];

void bellman(int s,int t)
{
    memset(dist, 127, sizeof(dist));
    dist[s] = 0;
    for (;;)
    {
        bool ok = false;
        for (int i = 1; i <= 2 * m;i++)
        {
            int u = edges[i].u;
            int v = edges[i].v;
            int w = edges[i].w;
            if(dist[u]<1<<30)
            {
                if(dist[v]>dist[u]+w)
                {
                    dist[v] = dist[u] + w;
                    ok = true;
                }
            }
            if(!ok)
                break;
        }
    }
}
int n,m;



int main()
{
    memset(h, -1, sizeof(h));
    return 0;
} */

/*

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct edge
{
    int v;
    int w;
};
const int N(1e3);
int q[N];
bool vis[N] = {false};

int dist[N];
vector<edge> edges[N];
int n, m;
int s, t;

void bellman(int s)
{
    memset(dist, 127, sizeof(dist));
    dist[s] = 0;
    for (;;)
    {
        bool ok = false;
        for (int i = 1; i <= n; i++)
        {
            for (auto ed : edges[i])
            {
                int j = ed.v;
                int w = ed.w;
                if (dist[i] < 1 << 30)
                    if (dist[j] > dist[i] + w)
                    {
                        dist[j] = dist[i] + w;
                        ok = true;
                    }
            }
        }
        if (!ok)
            break;
    }
}

void dikstra()
{
    memset(dist, 127, sizeof(dist));
    memset(vis, false, sizeof(vis));
    dist[s] = 0;
    for (;;)
    {
        int x = -1;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] < 1 << 30 && !vis[i])
            {
                if (x == -1 || dist[i] < dist[x])
                    x = i;
            }
        }
        if (x == -1 || x == t)
            break;
        vis[x] = true;
        for (auto ed : edges[x])
        {
            dist[ed.v] = min(dist[ed.v], dist[x] + ed.w);
        }
    }
}

void spfa(int s)
{
    memset(dist, 127, sizeof(dist));
    memset(vis, false, sizeof(false));
    dist[s] = 0;
    int rear = 0, front = 1;
    vis[s] = true;
    q[++rear] = s;
    while (rear >= front)
    {
        int u = q[front];
        front++;
        vis[u] = false;
        for (auto ed : edges[u])
        {
            int v = ed.v;
            int w = ed.w;
            if (dist[u] < 1 << 30)
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    if (!vis[v])
                    {
                        q[++rear] = v;
                        vis[v] = true;
                    }
                }
        }
    }
}

int main()
{
    cin >> n >> m;
    cin >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back({y, z});
        edges[y].push_back({x, z});
    }
    bellman(s);
    cout << dist[t];
    return 0;
}

 */

/* #include <bits/stdc++.h>
using namespace std;

struct edge
{
    int v;
    int w;
    int next;
} edgess[N];

const int N(1e3);
int dist[N];
int vis[N];
vector<edge> edges[N];
int n, m;
int s, t;

void dijkstra(int s)
{
    memset(dist, 127, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[s] = 0;
    for (;;)
    {
        int x = -1;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] < 1 << 30 && !vis[i])
            {
                if (dist[i] < dist[x] || x == -1)
                    x = i;
            }
        }
        if (x == t || x == -1)
            break;
        vis[x] = true;
        for (auto ed : edges[x])
        {
            dist[ed.v] = min(dist[ed.v], dist[x] + ed.w);
        }
    }
}

set<pair<int, int>> q;

void dijkstra()
{
    memset(dist, 127, sizeof(dist));
    dist[s] = 0;
    q.insert(make_pair(0, s));

    while (!q.empty())
    {
        int u = q.begin()->second;
        q.erase(q.begin());
        for (auto ed : edges[u])
        {
            if (dist[ed.v] > dist[u] + ed.w)
            {
                q.erase(make_pair(dist[ed.v], ed.v));
                dist[ed.v] = dist[u] + ed.w;
                q.insert(make_pair(dist[ed.v], ed.v));
            }
        }
    }
}

int h[N], e[N], ne[N], index;

int g[N][N];
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (g[i][k] < 1 << 30 && g[k][j] < 1 << 30)
                {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
}
int main()
{

    return 0;
}
 */

/* #include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
const int N(1e3);

struct edge
{
    int v;
    int w;
};

vector<edge> edges[N];
int dist[N];
bool vis[N];
void dijkstra()
{
    memset(dist, 127, sizeof(dist));
    memset(vis, false, sizeof(vis));
    dist[s] = 0;
    for (;;)
    {
        int x = -1;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && dist[i] < 1 << 30)
                if (x == -1 || dist[i] < dist[x])
                    x = i;
        }
        if (x == -1 || x == t)
            break;
        vis[x] = true;
        for (auto ed : edges[x])
        {
            dist[ed.v] = min(dist[ed.v], dist[x] + ed.w);
        }
    }
}
int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    dijkstra();
    cout << dist[t] << endl;
    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
const int N(1e4);
int h[N], e[N], w[N], ne[N], idx;

int n, m, s, t;
int dist[N], q[N];
int vis[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

void spfa()
{
    memset(dist, 127, sizeof(dist));

    memset(vis, false, sizeof(vis));
    dist[s] = 0;
    int front = 1, rear = 0;
    q[++rear] = s;
    vis[s] = true;
    while (front <= rear)
    {
        int u = q[front++];
        vis[u] = false;
        for (int i = h[u]; ~i; i = ne[i])
        {
            int v = e[i];
            if (dist[v] > dist[u] + w[i])
            {
                dist[v] = dist[u] + w[i];
                if (!vis[v])
                {
                    q[++rear] = v;
                    vis[v] = true;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    cin >> s >> t;
    // idx = 0;
    memset(h, -1, sizeof(h));
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    spfa();

    cout << dist[t];
    // for (int i = 1; i <= n; i++)
    //  cout << dist[i] << ' ';
    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;

const int N(1e3), M(1e4);

int g[N][N];

vector<pair<int, int>> q;
int n, m;
int main()
{
    cin >> n >> m;
    memset(g, 127, sizeof(g));
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (g[i][k] < 1 << 30 && g[k][j] < 1 << 30)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans = max(ans, g[1][i]);
    }
    cout << ans << endl;
    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;

const int N(810), M(3000);
int h[N];
int e[M], ne[M], w[M];
int n, m, k;
int a[N];
int idx;

int dist[N];

void add(int x, int y, int z)
{
    e[idx] = y;
    w[idx] = z;
    ne[idx] = h[x];
    h[x] = idx++;
}

set<pair<int, int>> q;

void dijkstra(int s)
{
    memset(dist, 127, sizeof(dist));
    dist[s] = 0;
    q.clear();
    q.insert(make_pair(0, s));

    while (!q.empty())
    {
        int u = q.begin()->second;
        q.erase(q.begin());
        for (int i = h[u]; ~i; i = ne[i])
        {
            int v = e[i];
            if (dist[v] > dist[u] + w[i])
            {
                q.erase(make_pair(dist[v], v));
                dist[v] = dist[u] + w[i];
                q.insert(make_pair(dist[v], v));
            }
        }
    }
}
int main()
{
    cin >> k >> n >> m;
    memset(h, -1, sizeof(h));
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    long long ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        dijkstra(i);
        long long tot = 0;
        for (int j = 1; j <= n; j++)
        {
            tot += (dist[j] * a[j]);
        }
        ans = min(ans, tot);
    }
    cout << ans << endl;
    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;

const int N(1e2), M(2e5 + 10);
int n, m;
int s, t;
bool vis[N];

double g[N][N];
double dist[N];

void dijkstra()
{
    memset(dist, 0, sizeof(0));
    dist[s] = 1;
    for (;;)
    {
        int x = -1;
        for (int i = 1; i <= n; i++)
        {
            // 取最大
            if (!vis[i])
                if (x == -1 || dist[x] < dist[i])
                    x = i;
        }
        if (x == -1 || x == t)
            break;
        vis[x] = true;
        for (int j = 1; j <= n; j++)
        {
            dist[j] = max(dist[j], dist[x] * g[x][j]);
        }
    }
}
int main()
{
    cin >> n >> m;
    // memset(g, -1, sizeof(g));

    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        double z = (100.0 - c) / 100;
        g[a][b] = g[b][a] = max(g[a][b], z);
    }

    cin >> s >> t;
    dijkstra();
    printf("%.8lf", 100 / dist[t]);
    return 0;
} */

/* #include <bits/stdc++.h>

using namespace std;

const int N(1e2 + 3), M(1e4);

int g[N][N];
int stop[N];
int q[N];
int n, m;
int dist[N];
void bfs()
{
    int rear = 0, front = 1;
    memset(dist, 127, sizeof(dist));
    dist[1] = 0;
    q[++rear] = 1;
    while (front <= rear)
    {
        int u = q[front++];
        for (int i = 1; i <= n; i++)
        {
            if (g[u][i] && dist[i] > dist[u] + 1)
            {
                dist[i] = dist[u] + 1;
                q[++rear] = i;
            }
        }
    }
}
int main()
{
    cin >> m >> n;
    while (m--)
    {
        int cnt = 0;
        char c = 1;

        while (c != -1 && c != '\n')
        {
            cin >> stop[cnt++];
        }
        for (int j = 0; j < cnt; j++)
        {
            for (int k = j + 1; k < cnt; k++)
            {
                g[stop[j]][stop[k]] = 1;
            }
        }
    }
    bfs();
    if (dist[n] > 1 << 30)
        puts("NO");
    else
        cout << max(dist[n] - 1, 0) << endl;
    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;
class a
{

private:
    int a;

public:
    void show2()
    {
        cout << endl;
    }

private:
    void show()
    {
        cout << a << endl;
    }
};
class b : public a
{
    friend class a;

public:
};

int main()
{
    return 0;
}
 */

/* #include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
int n;

void f()
{
    for (int i = 1; i <= 10; i++)
    {
        this_thread::sleep_for(chrono::seconds(1));

        printf("线程创建%d\n", i);
    }
}
int main()
{
    thread td(f);
    for (int i = 1; i <= 10; i++)
    {
        printf("main...%d\n", i);
        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
} */
/*
#include <bits/stdc++.h>

class pos
{
    friend class robot;

private:
    int x;
    int y;

public:
    pos() = default;
    pos(int x, int y = 0) : x(x), y(y) {}
    pos(int x) : pos(x, 0) {}
    // pos(int y) : pos(0, y) {}

private:
};

enum DIR
{
    EAST = 0,
    SOUTH,
    WEST,
    NORTH
};
class robot
{

public:
    robot &go(int dir)
    {
        switch (dir)
        {
        case DIR::WEST:
            p.x++;
            break;
        default:
            break;
        }
        return *this;
    }
    // virtual robot &showModel()
    // {
    //     printf("the robot model is %s\n", this->m_model);
    //     return *this;
    // }
    virtual void RobotCanDone(robot *rob)
    {
        std::cout << rob->m_model << std::endl;

        return;
    };

    virtual robot &showModel()
    {
        std::cout << this->m_model << std::endl;
        return *this;
    }
    virtual robot &showGeneration()
    {
        std::cout << this->m_generation << std::endl;
        return *this;
    }

public:
    robot() = default;
    robot(pos s, int bc = 1200, int id = 1, std::string model = "robot") : p(s), m_battery_capacity(bc), m_id(id), m_model(model) {}
    robot(pos s) : robot(s, 1200, 1) {}
    virtual ~robot() = default;

private:
    pos p;
    int m_battery_capacity;
    int m_id;
    std::string m_model;

protected:
    int m_generation = 1;
};

class homeRobot : public robot
{
private:
    std::string Cansee;

public:
    homeRobot() : robot(), Cansee("none")
    {
        this->m_generation = 2;
    }
    homeRobot(pos s, int bc, int id, std::string str, std::string str2) : robot(s, bc, id, str), Cansee(str2) {}

    void RobotCanDone()
    {
        printf("its home robot, is clearer\n");
    }
};

int main()
{
    robot *pRob = new homeRobot;
    homeRobot *pt = new homeRobot(pos(1, 2), 2400, 100002, "ha", "clear");
    robot *p = dynamic_cast<robot *>(pt);
    p->showModel();
    // pRob->RobotCanDone();
    // pRob->showModel();
    // pRob->showGeneration();bhngbn
    // robot *p = nullptr;
    // homeRobot *a = new homeRobot(pos(2, 3), 2400, 1012, "clearer One", "rubbish");
    // robot &b = *a;
    // // b.RobotCanDone();
    // b.showModel().RobotCanDone();
    // b.showModel(b);

    return 0;
} */

/* #include <bits/stdc++.h>

namespace myclass
{
    class point;
    class base0;
};

class point
{
public:
    point() = default;
    point(int x, int y) : x(x), y(y) { std::cout << "有参构造" << std::endl; }
    point(const point &oth)
    {
        *this = oth;
        std::cout << "拷贝构造" << std::endl;
    }
    point(point &oth)
    {
        *this = oth;
        std::cout << "拷贝构造" << std::endl;
    }

private:
    int x = 0;
    int y = 0;
};

class line
{
private:
    point p1;
    point p2;
    double dist;

public:
    line() = default;
    line(point &toh1, point &oth2) : p1(toh1), p2(oth2) {}
};

void fun2();

point fun()
{
    point a(1, 2);
    return a;
}

void f(point oth)
{
    return;
}

class base0
{
    int i;

public:
    base0() = default;
    explicit base0(int i) : i(i) { std::cout << "构造base 0" << std::endl; }
};
class base1
{
    std::string str;

public:
    base1() = default;
    base1(std::string) : str(str) { std::cout << "构造base 1" << std::endl; }
};

class base2
{
    char ch;

public:
    base2() = default;
    base2(char ch) : ch(ch) { std::cout << "构造base 2" << std::endl; }
};

class base3
{

    bool b;

public:
    base3() = default;
    base3(bool b) : b(b) { std::cout << "构造base 3" << std::endl; }
};

class base4
{
private:
    base0 b0;
    base1 b1;
    base2 b2;
    base3 b3;

public:
    base4(){};
    explicit base4(int b0, std::string b1, char b2, bool b3) : b0(b0), b1(b1), b2(b2), b3(b3) {}
};

void fun2(int a, int b, int c)
{
}

class base5
{
private:
    char t;
    static int id;
    const int tid = 0;

public:
    base5()
    {
    }
    void showId() const
    {
        id++;
        printf("%d\n", id);
    }
    static void showTid()
    {
        id++;
        printf("%d\n", id);
    }

    void writeId()
    {
        ;
    }
};

int base5::id = 3;

int main()
{

    return 0;
} */
/*
#include <bits/stdc++.h>

using namespace std;

class base
{
};

class drav : public base
{
};

int main()
{
    drav *d = new drav;
    base *b = new base;
    auto pp = static_cast<base>(*d);

    return 0;
} */
/*
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sum(vector<int> &nums, int l)
    {
        int ans = 0;
        int k = 3;
        while (k--)
        {
            if (l < nums.size())
                ans += nums[l++];
        }
        return ans;
    }
    long long minIncrementOperations(vector<int> &nums, int k)
    {
        int tot = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int s = sum(nums, i);

            if (s < k)
            {
                tot++;
                if (i + 3 < nums.size())
                    nums[i + 2]++;
            }
        }
        return tot;
    }
};
int main()
{
    Solution *s = new Solution;
    vector<int> v{};
    s.minIncrementOperations();

    return 0;
} */

#include <iostream>
using namespace std;
