//leetcode53
//https://leetcode.cn/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre=0;
        int maxAns=nums[0];
        for(int x:nums)
        {
            pre=max(pre+x,x);//如果x更大，则从x处重新开始
            maxAns=max(maxAns,pre);
        }
        return maxAns;
    }
};
//内存超限
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int num=nums.size();
//        if(num==1)
//        {
//            return nums[0];
//        }
//        vector<vector<int>> dp(num,vector<int>(num));
//
//        int MAX=INT_MIN;
//        for(int i=0;i<num;i++)
//        {
//            for(int j=i;j<num;j++)
//            {
//                if(j==i)
//                {
//                    dp[i][j]=nums[i];
//                }
//                else
//                {
//                    dp[i][j]=dp[i][j-1]+nums[j];
//                }
//                if(dp[i][j]>MAX)
//                {
//                    MAX=dp[i][j];
//                }
//            }
//        }
//        return MAX;
//
//    }
//};