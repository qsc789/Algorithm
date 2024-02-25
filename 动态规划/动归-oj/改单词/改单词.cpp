//leetcode72
//https://leetcode.cn/problems/edit-distance/
//题解https://leetcode.cn/problems/edit-distance/solutions/188223/bian-ji-ju-chi-by-leetcode-solution
class Solution {
public:
    int minDistance(string word1, string word2) {
        int num1=word1.length();
        int num2=word2.length();
        if(num1==0||num2==0)
        {
            return num1+num2;
        }
        vector<vector<int>> dp(num1+1,vector<int>((num2+1)));//格式
        for(int i=0;i<num1+1;i++)
        {
            dp[i][0]=i;
        }
        for(int i=0;i<num2+1;i++)
        {
            dp[0][i]=i;
        }
        for(int i=1;i<num1+1;i++)
        {
            for(int j=1;j<num2+1;j++)
            {
                int down=dp[i-1][j]+1;
                int left=dp[i][j-1]+1;
                int left_down=dp[i-1][j-1];
                if(word1[i-1]!=word2[j-1])
                {
                    left_down++;//如果字母不一样就加1，一样的话dp和左下方dp相同
                }
                dp[i][j]=min(left,min(down,left_down));
            }
        }
        return dp[num1][num2];
    }
};