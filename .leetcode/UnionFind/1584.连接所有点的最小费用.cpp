/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start

/* class Solution
{
public:
    struct edge
    {
        int val, v, u;
        edge(int _val, int _v, int _u)
        {
            val = _val;
            v = _v;
            u = _u;
        }
    };
    static bool cmp(edge &a, edge &b)
    {
        return a.val < b.val;
    }
    int find(int x)
    {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unionSet(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy)
            return false;
        parent[fx] = fy;
        return true;
    }
    vector<int> parent;
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<edge> edges;
        int n = points.size();
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int s = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edge e(s, i, j);
                edges.push_back(e);
            }
        }
        sort(edges.begin(), edges.end(), cmp);
        int ans = 0;
        int cnt = 1;
        for (auto i : edges)
        {
            int u = i.u;
            int v = i.v;
            if (unionSet(u, v))
            {
                cnt++;
                ans += i.val;
            }
            if (cnt == n)
                break;
        }
        return ans;
    }
}; */
// @lc code=end