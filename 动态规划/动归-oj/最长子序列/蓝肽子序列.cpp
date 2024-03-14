//https://www.lanqiao.cn/problems/1030/learning/?page=1&first_category_id=1&tags=DFS
#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int dp[N][N];
string a,b;
vector<string>tmp;
vector<string>w;
int main()
{
	cin>>a>>b;
	//分割单词，放到vector里 
	for(int i=0,j=0;i<a.size();)
	{
		if(a[j]>='A'&&a[j]<='Z')
		{
			j++;
			while(a[j]>='a'&&a[j]<='z'&&j<a.size())
			{
				j++;
			}
			tmp.push_back(a.substr(i,j-i));
			i=j;
		}
	}
	for(int i=0,j=0;i<b.size();)
	{
		if(b[j]>='A'&&b[j]<='Z')
		{
			j++;
			while(b[j]>='a'&&b[j]<='z'&&j<b.size())
			{
				j++;
			}
			w.push_back(b.substr(i,j-i));
			i=j;
		}
	}
	int ans=0;
	int n=tmp.size(),m=w.size();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(tmp[i-1]==w[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
				
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<dp[n][m]<<endl;
 } 