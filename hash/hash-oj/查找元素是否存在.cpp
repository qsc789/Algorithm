//leetcode268
//https://leetcode.cn/problems/missing-number/

// 查找某个元素是否在哈希表中，可以使用hash.find(x) != hash.end(),或者hash.count(x) > 0
// 注意：hash.count(x) 的数值只有 0 和 1。所以不能通过hash.count(x)来表示x在hash 中出现的次数。
class Solution {
        public:
        int missingNumber(vector<int>& nums) {
            unordered_set<int> hash;//哈希表声明
            int n=nums.size();
            for(int i=0;i<n;i++)
            {
                hash.insert(nums[i]);
            }
            int missing=-1;
            for(int i=0;i<=n;i++)
            {
                if(hash.count(i)==0)
                {
                    missing=i;
                    break;
                }
            }
            return missing;
        }
};