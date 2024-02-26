//leetcode376
//https://leetcode.cn/problems/wiggle-subsequence/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int num=nums.size();
        
        if(num<2)
        {
            return num;
        }
        vector<int> up(num),down(num);//多个容器声明方法
        up[0]=down[0]=1;
        //up[i] 表示以前 i 个元素中的某一个为结尾的最长的「上升摆动序列」的长度。
        //down[i] 表示以前 i 个元素中的某一个为结尾的最长的「下降摆动序列」的长度。
        //注意是某一个
        for(int i=1;i<num;i++)
        {
            if(nums[i]>nums[i-1])//上升
            {
                up[i]=max(up[i-1],down[i-1]+1);//i-1的上升或i-1的下降加1
                down[i]=down[i-1];
            }
            else if(nums[i]<nums[i-1])//下降
            {
                up[i]=up[i-1];
                down[i]=max(down[i-1],up[i-1]+1);//i-1的下降或i-1的上升加1
            }
            else
            {
                up[i]=up[i-1];
                down[i]=down[i-1];
            }
        }

        return max(up[num-1],down[num-1]);

    }
};