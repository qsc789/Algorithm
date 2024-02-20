//leetcode873
//https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int> indices;
        int num=arr.size();
        for(int i=0;i<num;i++)
        {
            indices[arr[i]]=i;//对应关系
        }
        vector<vector<int>> dp(num,vector<int>(num));
        //dp[j][i] 表示以arr[j] 和arr[i] 作为最后两个数字的斐波那契子序列的最大长度
        int ans=0;
        for(int i=0;i<num;i++)
        {
            for(int j=i-1;j>=0&&arr[j]*2>arr[i];j--)//从大到小找
            {
                //arr[i],arr[j]是较大的两个元素
                int k=-1;
                if(indices.count(arr[i]-arr[j]))//存在差
                {
                    k=indices[arr[i]-arr[j]];//找下标
                }
                if(k>=0)
                {
                    dp[j][i]=max(dp[k][j]+1,3);//该序列最小长度为3,能到这一步说明已经找到3个了
                }
                ans=max(ans,dp[j][i]);
            }
        }
        return ans;
    }
};