//leetcode873
//https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/


class Solution {
    public int lenLongestFibSubseq(int[] arr) {
    Map<Integer,Integer> indices=new HashMap<Integer,Integer>();
    int num=arr.length;
    for(int i=0;i<num;i++)
    {
        indices.put(arr[i],i);//添加对应关系
    }
    int[][] dp=new int[num][num];
    int ans=0;
    for(int i=0;i<num;i++)
    {
        for(int j=i-1;j>=0&&arr[j]*2>arr[i];j--)
        {
            int k=indices.getOrDefault(arr[i]-arr[j],-1);
            if(k>=0)
            {
                dp[j][i]=Math.max(dp[k][j]+1,3);
            }
            ans=Math.max(ans,dp[j][i]);
        }
    }
    return ans;
    }
}