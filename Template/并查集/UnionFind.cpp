#include <bits/stdc++.h>
using namespace std;
vector<int> fa;
vector<int> arr;
int n;
vector<int> Rank;

// 初始化
void init()
{
  fa.resize(n);
  for (int i = 0; i < n; i++)
  {
    fa[i] = i;
  }
}

// 搜索路径压缩
int find(int x)
{
  if (x != fa[x])
    fa[x] = find(fa[x]);
  return fa[x];
}

// 合并，直接合并
bool Unionset(int x, int y)
{
  int fx = find(x), fy = find(y);
  if (fx == fy)
    return false;
  fa[fx] = fy;
  return true;
}
// 启发式合并
bool unionset(int x, int y)
{
  int fx = find(x), fy = find(y);
  if (fx == fy)
    return false;
  if (Rank[fx] > Rank[fy])
    swap(Rank[fx], Rank[fy]);
  fa[fx] = fy;
  Rank[fy] += Rank[fx];
  return true;
}

int main()
{
  cin >> n;

  arr.resize(n);
  Rank.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  return 0;
}