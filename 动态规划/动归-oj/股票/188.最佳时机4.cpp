//leetcode188
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }
        int num=prices.size();
        k=min(k,num/2);//更新k，最多进行num/2次交易
        vector<vector<int>> buy(num, vector<int>(k + 1));
        vector<vector<int>> sell(num, vector<int>(k + 1));

        buy[0][0]=-prices[0];
        sell[0][0]=0;
        for(int i=1;i<=k;i++)
        {
            buy[0][i]=sell[0][i]=INT_MIN/2;
        }
        //我们用 buy[i][j]表示对于数组 prices中的价格而言，进行恰好 j 笔交易，并且当前手上持有一支股票，这种情况下的最大利润；
        //用 sell[i][j]表示恰好进行 j 笔交易，并且当前手上不持有股票，这种情况下的最大利润。
        for(int i=1;i<num;i++)
        {
            buy[i][0]=max(buy[i-1][0],sell[i-1][0]-prices[i]);
            for(int j=1;j<=k;j++)
            {
                buy[i][j]=max(buy[i-1][j],sell[i-1][j]-prices[i]);
                sell[i][j]=max(sell[i-1][j],buy[i-1][j-1]+prices[i]);
            }
        }
        return *max_element(sell[num - 1].begin(), sell[num - 1].end());
        // return Arrays.stream(sell[n - 1]).max().getAsInt();java找数组最小值



    }
};