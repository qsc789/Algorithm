//leetcode72
//https://leetcode.cn/problems/edit-distance/
//题解https://leetcode.cn/problems/edit-distance/solutions/188223/bian-ji-ju-chi-by-leetcode-solution
class Solution {
    public int minDistance(String word1, String word2) {
     int n=word1.length();
     int m=word2.length();

     if(n==0||m==0)//一个空字符串
     {
         return n+m;
     }

     int[][] dp=new int [n+1][m+1];
     //dp[x][y]代表word1前x个字母到word2前x个字母修改次数
     for(int i=0;i<n+1;i++)
     {
         dp[i][0]=i;
     }
     for(int i=0;i<m+1;i++)
     {
         dp[0][i]=i;
     }
     for(int i=1;i<n+1;i++)
     {
         for(int j=1;j<m+1;j++)
         {
             int down=dp[i-1][j]+1;
            int left=dp[i][j-1]+1;
            int left_down=dp[i-1][j-1];
            if(word1.charAt(i-1)!=word2.charAt(j-1))
            {
                left_down++;
            }
            dp[i][j]=Math.min(left,Math.min(down,left_down));//选三个里最小的
         }
     }
     return dp[n][m];
    }
}