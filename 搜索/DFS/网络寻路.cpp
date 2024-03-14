//https://www.lanqiao.cn/problems/263/learning/?page=1&first_category_id=1&tags=DFS
#include<iostream>
#include<vector>
using namespace std;
int n,m,ans;
vector<int>mp[10005];
void dfs(int last,int x,int num)
{
	if(num==3)
	{
		ans++;
		return ;
	}
	for(int i=0;i<mp[x].size();i++)
	{
		if(mp[x][i]!=last)//中间节点不能相同
		{
			dfs(x,mp[x][i],num+1);//mp[x][i]为前一个节点
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int num1,num2;
		cin>>num1>>num2;
		mp[num1].push_back(num2);
		mp[num2].push_back(num1);
	}
	for(int i=1;i<=n;i++)
	{
		dfs(-1,i,0);
	}
	cout<<ans;
}