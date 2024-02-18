//leetcode673
//https://leetcode.cn/problems/number-of-longest-increasing-subsequence/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int num = nums.size();
        int maxLen = 0;
        int ans = 0;
        vector<int> dp(num, 1), cnt(num, 1);
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])//出现更长的，个数重置
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[j] + 1 == dp[i])//长度相等，个数相加
                    {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if(dp[i]>maxLen)//出现更长的，更新maxLen,同时更新ans
            {
                maxLen=dp[i];
                ans=cnt[i];
            }
            else if(dp[i]==maxLen)
            {
                ans+=cnt[i];
            }
        }
        return ans;
    }
};