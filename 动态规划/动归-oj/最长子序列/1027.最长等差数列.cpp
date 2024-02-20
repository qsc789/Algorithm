//leetcode1027
//https://leetcode.cn/problems/longest-arithmetic-subsequence/
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int num=nums.size();
        vector<vector<int>> dp(num,vector<int>(1001,1));
        int maxLen=0;
        for(int i=1;i<num;i++)//从1开始，i与j不重合
        {
            for(int j=0;j<i;j++)
            {
                int d=nums[i]-nums[j]+500;//统一加偏移量，使下标非负
                dp[i][d]=dp[j][d]+1;
                maxLen=max(maxLen,dp[i][d]);
            }
        }
        return maxLen;
    }
};
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        auto [minit, maxit] = minmax_element(nums.begin(), nums.end());
        //minmax_element返回一个pair对象，包含了最小值和最大值，其中最小值在前，最大值在后。
        int diff = *maxit - *minit;//迭代器加*
        int ans = 1;
        for (int d = -diff; d <= diff; d++)
        {
            vector<int> f(*maxit + 1, -1);
            for (int num: nums)
            {
                if (int prev = num - d; prev >= *minit && prev <= *maxit && f[prev] != -1)
                {
                    f[num] = max(f[num], f[prev] + 1);
                    ans = max(ans, f[num]);
                }
                f[num] = max(f[num], 1);
            }
        }
        return ans;
    }
};
