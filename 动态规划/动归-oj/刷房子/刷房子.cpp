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
        return *min_element(dp.begin(),dp.end());//algorithm头文件接口函数
        //https://blog.csdn.net/weixin_38505045/article/details/88656453?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522170782990816800182113756%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=170782990816800182113756&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-88656453-null-null.142^v99^pc_search_result_base7&utm_term=min_element&spm=1018.2226.3001.4187
    }
};