//leetcode LCR 091
//链接：https://leetcode.cn/problems/JEj789/solutions/1621250/fen-shua-fang-zi-by-leetcode-solution-q0kh/
class Solution {
    public int minCost(int[][] costs) {
        int n = costs.length;
        int[] dp = new int[3];
        for (int j = 0; j < 3; j++) {
            dp[j] = costs[0][j];//第一个房子dp，等于costs
        }
        for (int i = 1; i < n; i++) {
            int[] dpNew = new int[3];//每个房子都有一个dp
            for (int j = 0; j < 3; j++) {
                dpNew[j] = Math.min(dp[(j + 1) % 3], dp[(j + 2) % 3]) + costs[i][j];
            }
            dp = dpNew;//存储
        }
        return Arrays.stream(dp).min().getAsInt();//返回第n个房子三种颜色中最小的
    }
}

