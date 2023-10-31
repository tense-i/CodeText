/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution
{
public:
    vector<int> dx{0, -1, 0, 1};
    vector<int> dy{-1, 0, 1, 0};

    void dfs(vector<vector<char>> &grid, int u, int v)
    {
        grid[u][v] = '0';
        for (int i = 0; i < 4; i++)
        {
            int x = u + dx[i];
            int y = v + dy[i];
            if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == '1')
            {
                dfs(grid, x, y);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
