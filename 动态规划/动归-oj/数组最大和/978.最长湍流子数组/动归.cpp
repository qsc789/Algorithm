//leetcode978
//https://leetcode.cn/problems/longest-turbulent-subarray/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int num=arr.size();
        vector<vector<int>> dp(num,vector<int>(2,1));//二维数组初始化为1
        //dp[i][0] 为以 arr[i]结尾，且arr[i−1]>arr[i] 的「湍流子数组」的最大长度
        //dp[i][1] 为以 arr[i] 结尾，且arr[i−1]<arr[i] 的「湍流子数组」的最大长度
        dp[0][0]=1;
        dp[0][1]=1;
        for(int i=1;i<num;i++)
        {
            if(arr[i-1]>arr[i])
            {
                dp[i][0]=dp[i-1][1]+1;
            }
            else if(arr[i-1]<arr[i])
            {
                dp[i][1]=dp[i-1][0]+1;
            }
        }
        int res=1;
        for (int i = 0; i < num; i++) {
            res = max(res, dp[i][0]);
            res = max(res, dp[i][1]);
        }
        return res;


    }
};