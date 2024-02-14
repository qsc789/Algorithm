//leetcode714
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int num=prices.size();
        if(num<2)
        {
            return 0;
        }
        vector<vector<int>> dp(num,vector<int>(2));
        dp[0][0]=-prices[0]-fee;//有股票
        dp[0][1]=0;//没股票
        for(int i=1;i<num;i++)
        {
            dp[i][0]=max(dp[i-1][1]-prices[i]-fee,dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]+prices[i],dp[i-1][1]);
        }
        return dp[num-1][1];
    }
};