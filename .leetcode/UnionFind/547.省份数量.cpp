/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
/* class Solution
{
public:
    vector<int> fa;
    int find(int x)
    {
        if (x != fa[x])
            fa[x] = find(fa[x]);
        return fa[x];
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int r = isConnected.size();
        int c = isConnected[0].size();
        fa.resize(r);
        for (int i = 0; i < r; i++)
        {
            fa[i] = i;
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    int fi = find(i), fj = find(j);
                    if (fi != fj)
                        fa[fi] = fj;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < r; i++)
        {
            if (fa[i] == i)
            {
                ans++;
            }
        }
        return ans;
    }
}; */
// @lc code=end
