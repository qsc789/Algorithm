//leetcode174
//https://leetcode.cn/problems/dungeon-game/
//Arrays.fill  https://blog.csdn.net/weixin_43613968/article/details/129379955?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170736914016800197054334%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=170736914016800197054334&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-1-129379955-null-null.142^v99^pc_search_result_base7&utm_term=arrays.fill%20%E5%A1%AB%E5%85%85%E4%BA%8C%E7%BB%B4%E6%95%B0%E7%BB%84&spm=1018.2226.3001.4187
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
     int num1=dungeon.length;
     int num2=dungeon[0].length;
     int[][] dp=new int[num1+1][num2+1];
     for(int i=0;i<=num1;i++)
     {
         Arrays.fill(dp[i],Integer.MAX_VALUE);//填充二维数组
     }
     dp[num1][num2-1]=dp[num1-1][num2]=1;//倒着推
     for(int i=num1-1;i>=0;i--)
     {
         for(int j=num2-1;j>=0;j--)
         {
             int min=Math.min(dp[i+1][j],dp[i][j+1]);
             dp[i][j]=Math.max(min-dungeon[i][j],1);//起码得有1
         }
     }
     return dp[0][0];
    }
}