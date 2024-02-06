//leetcode242
//https://leetcode.cn/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int num1=s.size();//s.length也行
        int num2=t.size();
        if(num1!=num2)
        {
            return false;
        }
        vector<int> table(26,0);//数组26个元素，初始化为0
        for (auto& ch: s) //auto自动匹配类型（遍历）
        {
            table[ch - 'a']++;
        }
        for (auto& ch: t)
        {
            table[ch - 'a']--;
            if (table[ch - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};