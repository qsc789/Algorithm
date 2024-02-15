//leetcode152
//https://leetcode.cn/problems/maximum-product-subarray/
//题解https://leetcode.cn/problems/maximum-product-subarray/solutions/250015/cheng-ji-zui-da-zi-shu-zu-by-leetcode-solution/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int num=nums.size();
        vector<int> maxF(nums),minF(nums);
        for(int i=1;i<num;i++)
        {
            //同时找最大值和最小值，最小值负负得正也可能是最大值
            //找maxF[i-1]*nums[i],minF[i-1]*nums[i],nums[i]中的最值
            maxF[i]=max(maxF[i-1]*nums[i],max(nums[i],minF[i-1]*nums[i]));
            minF[i]=min(minF[i-1]*nums[i],min(nums[i],maxF[i-1]*nums[i]));
        }
        return *max_element(maxF.begin(),maxF.end());
    }
};