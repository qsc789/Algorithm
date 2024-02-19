//leetcode1218
//https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans=0;
        unordered_map<int,int> dp;//复杂哈希表，int，int型键值对
        for(int i:arr)
        {
            dp[i]=dp[i-difference]+1;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};