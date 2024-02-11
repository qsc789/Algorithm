//leetcode740
//https://leetcode.cn/problems/delete-and-earn/
//题解https://leetcode.cn/problems/delete-and-earn/solutions/758416/shan-chu-bing-huo-de-dian-shu-by-leetcod-x1pu
class Solution {
    public int deleteAndEarn(int[] nums) {
      int MaxVal=0;
      int numsSize=nums.length;
      for (int i = 0; i < numsSize; i++)
    {
        MaxVal = Math.max(MaxVal, nums[i]);
    }
      int[] sum=new int[MaxVal+1];
     for (int i = 0; i < numsSize; i++) 
 {
        sum[nums[i]] += nums[i];
 }
      return rob(sum);
    }
 
    public int rob(int[] nums)
    {
        int size=nums.length;
        int first=nums[0],second=Math.max(nums[0],nums[1]);
        for(int i=2;i<size;i++)
        {
            int temp=second;
            second=Math.max(first+nums[i],second);
            first=temp;
        }
        return second;
    }
}