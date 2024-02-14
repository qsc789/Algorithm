//leetcode122
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
    public int maxProfit(int[] prices) {
    int len=prices.length;
    if(len<2)
    {
        return 0;
    }
    //0是持有股票，1是持有现金
    int[][] dp=new int[len][2];
    dp[0][0]=0;//第一天未买入，现金为0
    dp[0][1]=-prices[0];//第一天买入，现金为-股票价
    for(int i=1;i<len;i++)
    {
        dp[i][0]=Math.max(dp[i-1][0],dp[i-1][1]+prices[i]);//第i天手里没有股票
        dp[i][1]=Math.max(dp[i-1][1],dp[i-1][0]-prices[i]);//第i天手里没股票
    }
    return dp[len-1][0];
    }
}