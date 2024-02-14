//leetcode121
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf=1e9;//较大数
        int minprice=inf,maxprofit=0;
        for(int price:prices)//遍历数组
        {
            maxprofit=max(maxprofit,price-minprice);//minprice为当前天数之前最小价格
            minprice=min(minprice,price);
        }
        return maxprofit;
    }
};