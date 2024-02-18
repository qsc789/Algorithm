//leetcode646
//https://leetcode.cn/problems/maximum-length-of-pair-chain/
//sort https://blog.csdn.net/qq_41575507/article/details/105936466?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170825730116800184199136%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=170825730116800184199136&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-105936466-null-null.142^v99^pc_search_result_base7&utm_term=C%2B%2Bsort&spm=1018.2226.3001.4187
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int num=pairs.size();
        sort(pairs.begin(),pairs.end());//默认升序
        vector<int> dp(num,1);
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0]>pairs[j][1])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return dp[num-1];
    }
};