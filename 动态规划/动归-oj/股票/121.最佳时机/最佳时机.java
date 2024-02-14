//leetcode121
//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
class Solution {
    public int maxProfit(int[] prices) {
     int num=prices.length;
     int minprice=Integer.MAX_VALUE;//整形最大值
     int maxprofit=0;
     for(int i=0;i<num;i++)
     {
         if(prices[i]<minprice)
         {
             minprice=prices[i];
         }
         else if(prices[i]-minprice>maxprofit)
         {
             maxprofit=prices[i]-minprice;
         }

     }
     return maxprofit;
    }
}