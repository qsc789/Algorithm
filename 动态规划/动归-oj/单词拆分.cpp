//leetcode139
//https://leetcode.cn/problems/word-break/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto wordDicSet = unordered_set <string> ();
        //unordered_set<string> hash;
        for(auto word:wordDict)
        {
            wordDicSet.insert(word);//把词典中的词插入哈希表
        }

        auto dp=vector<bool> (s.size()+1);//默认是false
        dp[0]=true;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]&&wordDicSet.find(s.substr(j,i-1))!=wordDicSet.end())//wordDicSet.count(s.substr(j,i-1))
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};