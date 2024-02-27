//leetcode118
//https://leetcode.cn/problems/pascals-triangle/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);//声明新数组
        for(int i=0;i<numRows;i++)
        {
            res[i].resize(i+1);//resize函数，替换字符串长度
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return res;
    }
};