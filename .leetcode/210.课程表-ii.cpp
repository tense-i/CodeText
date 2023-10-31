/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> edges(numCourses);
        vector<int> indeg(numCourses);
        for (auto i : prerequisites)
        {
            edges[i[1]].push_back(i[0]);
            ++indeg[i[0]];
        }
        queue<int> que;
        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
                que.push(i);
        }
        vector<int> ans;
        int cnt = 0;
        while (!que.empty())
        {
            cnt++;
            ans.push_back(que.front());
            int u = que.front();
            que.pop();
            for (auto v : edges[u])
            {
                --indeg[v];
                if (indeg[v] == 0)
                {
                    que.push(v);
                }
            }
        }
        if (cnt == numCourses)
            return ans;
        else
            return {};
        return {};
    }
};
// @lc code=end
