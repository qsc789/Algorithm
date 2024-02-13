//leetcode LCR 091
//链接：https://leetcode.cn/problems/JEj789/solutions/1621250/fen-shua-fang-zi-by-leetcode-solution-q0kh/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {

        int num=costs.size();//只有string类里有length
        vector<int> dp(3);
        for(int i=0;i<3;i++)
        {
            dp[i]=costs[0][i];
        }
        for(int i=1;i<num;i++)
        {
            //int[] Newdp=new int[3];//java版本
            vector<int> Newdp(3);
            for(int j=0;j<3;j++)
            {
                Newdp[j]=min(dp[(j+1)%3],dp[(j+2)%3])+costs[i][j];
            }
            dp=Newdp;
        }
        return *min_element(dp.begin(),dp.end());
    }
};