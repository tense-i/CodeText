/*
 * @lc app=leetcode.cn id=1489 lang=cpp
 *
 * [1489] 找到最小生成树里的关键边和伪关键边
 */

// @lc code=start
class Solution
{
private:
    vector<int> parent;
    vector<vector<int>> edgesCopy;

public:
    void init(int n)
    {
        if (parent.empty())
            parent.resize(n); // n 个节点
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i; // 每个顶点看作一个树（集合），根节点初始化为其自身
        }
    }

    int find(int i)
    {
        while (parent[i] != i)
        {
            i = parent[i];
            parent[i] = parent[parent[i]];
        }
        return parent[i];
    }
    bool union_(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        { // 不相同，则合并
            parent[rootX] = rootY;
            return true;
        }
        return false;
    }
    int kruskal(vector<vector<int>> &edges, int n, int index, bool giveOrTake)
    { /* 初始化并查集 */
        init(n);
        // 边的权重，
        int mstWeightSum = 0, mstEdgeCount = 0;
        /* 伪关键边 */
        if (!giveOrTake && index >= 0)
        {
            parent[edgesCopy[index][1]] = edgesCopy[index][0];
            mstWeightSum += edgesCopy[index][2];
            mstEdgeCount++;
        }
        /* 遍历每条边，合并不在同一个树（集合）的节点 */
        for (int i = 0; i < edges.size() && mstEdgeCount < n - 1; i++)
        {
            // 关键边
            if (giveOrTake && edges[i] == edgesCopy[index])
            {
                continue; // 跳过
            }
            if (union_(edges[i][0], edges[i][1]))
            {
                mstWeightSum += edges[i][2];
                mstEdgeCount++; // 优化：最小生成树中，边的数量 = n-1
            }
        }

        // 可能会发生去掉关键边之后，不连通的情况
        if (mstEdgeCount == n - 1)
            return mstWeightSum;
        return INT_MAX;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        edgesCopy = edges; // 复制一份原始边数组
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[2] < b[2]; });

        int minSum = kruskal(edges, n, -1, false);
        vector<vector<int>> result(2);
        vector<int> &keyEdge = result[0];  // 关键边
        vector<int> &pseudoKE = result[1]; // 伪关键边

        for (int i = 0; i < edgesCopy.size(); ++i)
        {
            if (kruskal(edges, n, i, true) > minSum)
            {
                // 关键边
                keyEdge.push_back(i);
            }
            else if (kruskal(edges, n, i, false) == minSum)
            {
                // 伪关键边
                pseudoKE.push_back(i);
            }
        }
        return result;
    }
};

// @lc code=end
