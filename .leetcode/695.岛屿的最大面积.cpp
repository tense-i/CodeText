/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
/* class Solution
{
public:
    int ans = 0;
    vector<int> dx{0, -1, 0, 1};
    vector<int> dy{-1, 0, 1, 0};
    void bfs(vector<vector<int>> &grid, int n, int m)
    {
        queue<pair<int, int>> que;
        que.push({n, m});
        grid[n][m] = 0;
        int tot = 1;
        while (!que.empty())
        {
            int u = que.front().first;
            int v = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = u + dx[i];
                int y = v + dy[i];
                if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1)
                {
                    tot++;
                    que.push(make_pair(x, y));
                    grid[x][y] = 0;
                }
            }
        }
        ans = max(ans, tot);
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    bfs(grid, i, j);
                }
            }
        }
        return ans;
    }
}; */
// @lc code=end
