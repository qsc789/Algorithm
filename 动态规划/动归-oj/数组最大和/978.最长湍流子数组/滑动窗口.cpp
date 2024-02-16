//leetcode978
//https://leetcode.cn/problems/longest-turbulent-subarray/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int num=arr.size();
        int res=1;
        int left=0,right=0;
        while(right<num-1)//right最后到num-2
        {
            if(left==right)//left,right重合
            {
                if(arr[left]==arr[left+1])
                {
                    left++;
                }
                right++;
            }
            else
            {
                if(arr[right-1]<arr[right]&&arr[right]>arr[right+1])
                {
                    right++;
                }
                else if(arr[right-1]>arr[right]&&arr[right]<arr[right+1])
                {
                    right++;
                }
                else
                {
                    left=right;//对齐
                }
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};