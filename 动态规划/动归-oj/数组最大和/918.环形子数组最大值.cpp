//leetcode918
//https://leetcode.cn/problems/maximum-sum-circular-subarray/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int num=nums.size();
        vector<int> leftMax(n);
        leftMax[0]=nums[0];
        int leftSum=nums[0];
        int pre=nums[0];
        int res=nums[0];
        for(int i=1;i<num;i++)
        {
            //跟53一样的pre和res
            pre=max(pre+nums[i],nums[i]);
            res=max(res,pre);//持续保存最大值，类似53返回的*max_element
            //算左前缀
            leftSum+=nums[i];
            leftMax[i]=max(leftMax[i-1],leftSum);
        }
        //res为连续区间最大和

        int rightSum=0;
        for(int i=num-1;i>0;i--)
        {
            rightSum+=nums[i];
            res=max(res,rightSum+leftMax[i-1]);//考虑环形后重算最大值
            //leftMax[i-1]为i-1左侧位置最大值
        }
        return res;

    }
};