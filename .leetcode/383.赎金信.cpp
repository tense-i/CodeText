/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if(ransomNote.size()>magazine.size())
            return false;
        vector<int> cnt(26);
        for (auto &i : magazine)
        {
            cnt[i - 'a']++;
        }
        for (auto &i : ransomNote)
        {
            cnt[i - 'a']--;
            if (cnt[i - 'a'] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
