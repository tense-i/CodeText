/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 *
 * [1971] 寻找图中是否存在路径
 */

// @lc code=start
/* class Solution
{
public:
    bool dfs(int source, int destination, vector<vector<int>> &adj, vector<bool> &v)
    {
        if (source == destination)
            return true;
        v[source] = true;
        for(auto i:adj[source]){
            if(!v[i]&&dfs(i,destination,adj,v))
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<vector<int>> adj(n);
        for(auto i:edges){
            int x = i[0], y = i[1];
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
    }
}; */
// @lc code=end
