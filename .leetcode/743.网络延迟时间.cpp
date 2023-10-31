/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */
// @lc code=start
 class Solution
{
public:
    struct node
    {
        int u;
        int dis;
        bool operator>(node &a) const
        {
            return this->dis > a.dis;
        };
    };
    vector<int> dis;
    vector<bool> vis;
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        dis.resize(n + 1, 0x3f3f);
        vis.resize(n + 1, false);
        dis[k] = 0;
        priority_queue<node, vector<node>, greater<node>> q;
        q.push({0, k});
        while (!q.empty())
        {
            int u = q.top().u;
            q.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            for (auto i : times[u])
            {
                if (dis[i[0]] > dis[u] + i[2])
                {
                    dis[i[0]] = dis[u] + i[2];
                }
            }
        }
        return *(max_element(dis.begin(), dis.end()));
    }
}; 
// @lc code=end
