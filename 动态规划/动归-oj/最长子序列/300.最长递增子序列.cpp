//leetcode300
//https://leetcode.cn/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int num=nums.size();
        if(num==0)
        {
            return 0;
        }
        vector<int> dp(num,1);//dp初始化为1
        //定义dp[i] 为考虑前 i个元素，以第 i个数字结尾的最长上升子序列的长度
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])//如果有小的
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};