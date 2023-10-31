/* #include <bits/stdc++.h>
using namespace std;
const int N(1e3);

int n;
bool vis[N];
int dis[N];

struct edge
{
  int v, w;
};
vector<edge> edges[N];

// 朴素版的dijstral算法；
int dijstral(int s, int t)
{
  memset(dis, 0x3f3f, sizeof(dis));
  dis[s] = 0;
  for (int i = 1; i <= n; i++)
  {
    int u = 0, mind = 0x3f3f;
    for (int j = 1; j <= n; j++)
      if (!vis[j] && dis[j] < mind)
      {
        mind = dis[j];
        u = j;
      }
    vis[u] = true;
    for (auto i : edges[u])
      if (dis[i.v] > dis[u] + i.w)
      {
        dis[i.v] = dis[u] + i.w;
      }
  }
  return dis[t];
}

// 优先队列优化；

// q记录所有不在集合c中的点；

// pair<dis[u],u>;
set<pair<int, int>> q;
int dijstral(int s, int t)
{
  memset(dis, 0x3f3f, sizeof(dis));
  dis[s] = 0;
  q.clear();
  for (int i = 1; i <= n; i++)
    q.insert(make_pair(dis[i], i));
  while (!q.empty())
  {
    int u = q.begin()->second;
    q.erase(q.begin());
    if (u == t || dis[u] > 0x3f3f)
    {
      break;
    }
    for (auto i : edges[u])
    {
      if (dis[i.v] > dis[u] + i.w)
      { // 找到要删除的节点；
        q.erase(make_pair(dis[i.v], i.v));
        dis[i.v] = dis[u] + i.w;
        // 重新插入；
        q.insert(make_pair(dis[i.v], i.w));
      }
    }
  }
}

// 优先队列
struct edge
{
  int v, w;
};

struct node
{
  int dis, u;

  bool operator>(const node &a) const { return dis > a.dis; }
};
vector<edge> e[maxn];
int dis[maxn], vis[maxn];
priority_queue<node, vector<node>, greater<node>> pq;

void dijkstra(int n, int s)
{
  memset(dis, 63, sizeof(dis));
  dis[s] = 0;
  pq.push({0, s});
  while (!pq.empty())
  {
    int u = pq.top().u;
    pq.pop();
    if (vis[u])
      continue;
    vis[u] = 1;
    for (auto ed : e[u])
    {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w)
      {
        dis[v] = dis[u] + w;
        pq.push({dis[v], v});
      }
    }
  }
}

int main()
{

  return 0;
} */