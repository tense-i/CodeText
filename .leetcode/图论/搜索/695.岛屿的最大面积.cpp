/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        int ans = 0;
        for (int r = 0; r < nr; r++)
        {
            for (int c = 0; c < nc; c++)
            {
                if (grid[r][c] == 1)
                {
                    int cnt = 1;
                    queue<pair<int, int>> q;
                    q.push(make_pair(r, c));
                    grid[r][c] = 0;
                    while (!q.empty())
                    {
                        auto rc = q.front();
                        int i = rc.first;
                        int j = rc.second;
                        q.pop();
                        if (i - 1 >= 0 && grid[i - 1][j] == 1)
                        {
                            cnt++;
                            q.push(make_pair(i - 1, j));
                            grid[i - 1][j] = 0;
                        }
                        if (j - 1 >= 0 && grid[i][j - 1] == 1)
                        {
                            cnt++;
                            q.push(make_pair(i, j - 1));
                            grid[i][j - 1] = 0;
                        }
                        if (i + 1 < nr && grid[i + 1][j] == 1)
                        {
                            cnt++;
                            q.push(make_pair(i + 1, j));
                            grid[i + 1][j] = 0;
                        }
                        if (j + 1 < nc && grid[i][j + 1] == 1)
                        {
                            cnt++;
                            q.push(make_pair(i, j + 1));
                            grid[i][j + 1] = 0;
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};

// @lc code=end

