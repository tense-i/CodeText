#include <bits/stdc++.h>
using namespace std;
const int N(1e3);
int n, m;

// prim
int w[N][N];
int dist[N];
bool vis[N];

int prim()
{
  int res = 0;
  // 初始距离为正无穷；
  memset(dist, 0x3f, sizeof(dist));
  // 1号点距离是0；
  dist[1] = 0;

  for (int i = 0; i < n; i++)
  {
    // 权值最小顶点的编号；
    int t = -1;
    for (int j = 1; j <= n; j++)
    {
      // 没有被访问或者还没更新或者当前的权值大于dist【j】的权值，则将t更新为小顶点j；
      if (!vis[j] && (t == -1 || dist[t] > dist[j]))
        t = j;
    }
    res += dist[t];
    vis[t] = true;
    // 用新加入的顶点t更新dist数组，cut{a,b,c}=cut{a,b}+cut{c};
    for (int j = 1; j <= n; j++)
      dist[j] = min(dist[j], w[t][j]);
  }
  return res;
}
// kurskal
struct edge
{
  int u;
  int v;
  int w;
  //写了有参构造则编译器不提供无参构造，93行代码就有错，vector<edge>edges(m)会调用无参构造初始化！！！
  edge(int _u, int _v, int _w)
  {
    u = _u;
    v = _v;
    w = _w;
  } 
};
vector<int> fa;
void init(int n)
{
  fa.resize(n + 1);
  for (int i = 1; i <= n; i++)
    fa[i] = i;
}
int find(int x)
{
  if (fa[x] != x)
    fa[x] = find(fa[x]);
  return fa[x];
}
bool unionset(int u, int v)
{
  u = find(u), v = find(v);
  if (u == v)
    return false;
  fa[u] = v;
  return true;
}
int kruskal(int n, vector<edge> &edges)
{
  sort(edges.begin(), edges.end(), [](edge &e1, edge &e2) -> int
       { return e1.w < e2.w; });
  init(n);
  int ans = 0;
  int cnt = 1;
  for (int i = 0; i < m; i++)
  {
    int u = edges[i].u;
    int v = edges[i].v;
    if (unionset(u, v))
    {
      ans += edges[i].w;
    }
  }
  return ans;
}
void test()
{
  // n为顶点数，m为边数；
  cin >> n >> m;
  init(n);
  vector<edge> edges(m + 1);
  for (int i = 0; i < m; i++)
  {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  }
  cout << kruskal(n, edges);
}
void test2(){
  
}
int main()
{
  test();
  return 0;
}