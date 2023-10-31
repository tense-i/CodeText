/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
/* class Solution
{
public:
    struct Status
    {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r)
    {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status){lSum, rSum, mSum, iSum};
    };
    // 在C++ 中，分号表示一条语句的结束。在这个函数中，最后一个字符是右括号 '}' 
    //，表示函数体的结束。加上分号只是为了告诉编译器这里是一条完整的语句，不是一个需要继续解析的代码块。
    //  实际上，即使没有加分号，编译器也可以正确处理这段代码。
    //在这个例子中，分号只是一种好的编码习惯，可以帮助减少不必要的错误和警告。
     Status get(vector<int> &a, int l, int r)
    {
        if (l == r)
        {
            return (Status){a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int> &nums)
    {
        return get(nums, 0, nums.size() - 1).mSum;
    }
}; */
              // @lc code=end
