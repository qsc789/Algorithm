//leetcode213
//https://leetcode.cn/problems/house-robber-ii/
class Solution {
    public int rob(int[] nums) {
     int length=nums.length;
     if(length==1)
     {
         return nums[0];
     }
     else if(length==2)
     {
         return Math.max(nums[0],nums[1]);
     }
     return Math.max(robRange(nums,0,length-2)，robRange(nums,1,length-1));//因为第一家和最后一家相连，产生两种可能的区间
    }
    public int robRange(int[] nums,int start,int end)
    {
        int first=nums[start],second=Math.max(nums[start],nums[start+1]);//前两个里最大值
        for(int i=start+2,i<=end;i++)
        {
            int temp=second;
            second=Math.max(first+nums[i],second);//存最大值
            first=temp;
        }
        return second;
    }
}