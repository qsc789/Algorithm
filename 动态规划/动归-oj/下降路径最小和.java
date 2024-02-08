//leetcode931
//https://leetcode.cn/problems/minimum-falling-path-sum/
//0x3f3f3f3f常用较大数
//1e9+7常用较大质数
class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int num1=matrix.length;
        int num2=matrix[0].length;
     int[][] res=new int[num1][num2];
     for(int i=0;i<num2;i++)
     {
         res[0][i]=matrix[0][i];
     }
     for(int i=1;i<num1;i++)
     {
         for(int j=0;j<num2;j++)
         {
             if(j==0)
             {
                 res[i][j]=Math.min(res[i-1][j+1],res[i-1][j])+matrix[i][j];
             }
             else if(j==num2-1)
             {
                 res[i][j]=Math.min(res[i-1][j-1],res[i-1][j])+matrix[i][j];
             }
             else
             {
                 res[i][j]=Math.min(res[i-1][j+1],Math.min(res[i-1][j-1],res[i-1][j]))+matrix[i][j];
             }
             
         }
     }
     int min=0x3f3f3f3f;//常用较大数
     for(int i=0;i<num2;i++)
     {
         if(res[num1-1][i]<min)
         {
             min=res[num1-1][i];
         }
     }
     return min;
    }
}