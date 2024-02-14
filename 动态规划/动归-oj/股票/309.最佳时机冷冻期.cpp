//leetcode309
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/

//找每天有几种状态，找每种状态状态转移方程

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }
        int num=prices.size();
        //三种状态
        // f[i][0]: 手上持有股票的最大收益
        // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        vector<vector<int>> f(num,vector<int>(3));
        f[0][0]=-prices[0];
        for(int i=1;i<num;i++)
        {
            f[i][0]=max(f[i-1][0],f[i-1][2]-prices[i]);
            f[i][1]=f[i-1][0]+prices[i];
            f[i][2]=max(f[i-1][2],f[i-1][1]);

        }
        return max(f[num-1][1],f[num-1][2]);

    }
};