/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> edges(numCourses);
        vector<int> indeg(numCourses);
        for (auto i : prerequisites)
        {
            edges[i[1]].push_back(i[0]);
            ++indeg[i[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            cnt++;
            int u = q.front();
            q.pop();
            for(auto v:edges[u]){
                --indeg[v];
                if(indeg[v]==0)
                    q.push(v);
            }
        }
        return cnt == numCourses;
    }
};
// @lc code=end
