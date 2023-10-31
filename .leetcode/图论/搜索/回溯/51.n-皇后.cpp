/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> res;

    bool check(vector<string> &board, int row, int col)
    {
        int n = board.size();
        // 检查列是否有皇后互相冲突
        for (int i = 0; i <= row; i++)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        // 检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void bfs(vector<string> &path, int row)
    {
        if (row == path.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < res.size(); i++)
        {
            if (!check(path, row, i))
            {
                continue;
            }
            path[row][i] = 'Q';
            bfs(path, row + 1);
            path[row][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> path(n, string(n, '.'));
        bfs(path, 0);
        return res;
    }
};
// @lc code=end
