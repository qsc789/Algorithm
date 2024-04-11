//https://www.lanqiao.cn/courses/31015/learning/?id=1926987&compatibility=false
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
LL DP[3100][3100],mod;
int n,k;
int main()
{
    cin>>n>>k>>mod;
    DP[3][1]=2;
    for(int i=4;i<=n;i++)
    {

        for(int j=1;3*j<=i&&j<=k;j++)
        {

            DP[i][j]=DP[i-1][j]*(i-1)%mod;//i-1个人的圈里有n-1个空，插空

            DP[i][j]=(DP[i][j]+DP[i-3][j-1]*(i-1)*(i-2))%mod;//拿出两个人和新加的人凑成一个新圈，有(n-1)*(n-2)种三元圈
        }
    }
    cout<<DP[n][k];
    return 0;
}