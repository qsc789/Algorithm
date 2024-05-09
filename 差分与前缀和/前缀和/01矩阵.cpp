//码蹄集 MT2050
//https://www.matiji.net/exam/dohomework/6230/2
#include<bits/stdc++.h> 

using namespace std;
char a[110][110];
int b[110][110],sum[110][110];
int m,n;
int main( )
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        scanf("%s",a[i]+1);
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]=='1')
            {
                b[i][j]=1;
            }
        }
        }
// *****
// *****
// *****
// *****
// ****&
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+b[i][j];//看那个图
            }
            
        }
        for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=n;j++)
                {
                     cout<<sum[i][j]<<' ';
                }
                cout<<endl;
            }

    return 0;
}



