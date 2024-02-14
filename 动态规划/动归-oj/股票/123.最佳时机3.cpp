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