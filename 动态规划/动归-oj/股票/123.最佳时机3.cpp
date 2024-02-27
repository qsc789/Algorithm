//leetcode123
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num=prices.size();
        int buy1=-prices[0],sell1=0;//两次交易
        int buy2=-prices[0],sell2=0;
        for(int i=1;i<num;i++)
        {
            //每天可能的四种状态
            buy1=max(buy1,-prices[i]);
            sell1=max(sell1,buy1+prices[i]);
            buy2=max(buy2,sell1-prices[i]);
            sell2=max(sell2,buy2+prices[i]);
        }
        return sell2;
    }
};
//dp四种状态
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int num=prices.size();
    vector<vector<int>> dp(num,vector<int>(4));
    dp[0][0]=-prices[0];//买入了第一次
    dp[0][1]=0;//第一次卖出
    dp[0][2]=-prices[0];//第二次买入
    dp[0][3]=0;//第二次卖出
    for(int i=1;i<num;i++)
    {
        dp[i][0]=max(dp[i-1][0],-prices[i]);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]);
        dp[i][2]=max(dp[i-1][2],dp[i-1][1]-prices[i]);
        dp[i][3]=max(dp[i-1][3],dp[i-1][2]+prices[i]);
    }
    return dp[num-1][3];
    }
};