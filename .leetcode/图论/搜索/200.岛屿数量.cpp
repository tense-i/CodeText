/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
// 广度优先
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        int ans = 0;
        for (int r = 0; r < nr; r++)
        {
            for (int c = 0; c < nc; c++)
            {
                if (grid[r][c] == '1')
                {
                    ans++;
                    queue<pair<int, int>> q;
                    q.push(make_pair(r, c));
                    grid[r][c] = '0';
                    while (!q.empty())
                    {
                        auto rc = q.front();
                        int i = rc.first;
                        int j = rc.second;
                        q.pop();
                        if (i - 1 >= 0 && grid[i - 1][j] == '1')
                        {
                            q.push(make_pair(i - 1, j));
                            grid[i - 1][j] = '0';
                        }
                        if (j - 1 >= 0 && grid[i][j - 1] == '1')
                        {
                            q.push(make_pair(i, j - 1));
                            grid[i][j - 1] = '0';
                        }
                        if (i + 1 < nr && grid[i + 1][j] == '1')
                        {
                            q.push(make_pair(i + 1, j));
                            grid[i + 1][j] = '0';
                        }
                        if (j + 1 < nc && grid[i][j + 1] == '1')
                        {
                            q.push(make_pair(i, j + 1));
                            grid[i][j + 1] = '0';
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// 深度优先
/* class Solution
{
public:
    void dfs(vector<vector<char>> &grid,int r,int c)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r - 1][c] == '1')
        {
            dfs(grid, r - 1, c);
        }
        if (r + 1 < nr && grid[r + 1][c] == '1')
        {
            dfs(grid, r + 1, c);
        }
        if (c - 1 >= 0 && grid[r][c - 1] == '1')
        {
            dfs(grid, r, c - 1);
        }
        if (c +1 < nc && grid[r][c+1] == '1')
        {
            dfs(grid, r, c + 1);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        int nr = grid.size();
        int nc = grid[0].size();
        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid,i, j);
                }
            }
        }
        return ans;
    }
}; */
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
    }
};
// @lc code=end