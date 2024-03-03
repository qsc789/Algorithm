//https://www.lanqiao.cn/problems/1372/learning/?page=1&first_category_id=1&problem_id=1372
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	int n,s;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	int ans=1e8;
	for(int i=0,j=0;i<n;)
	{
		if(sum<s)
		{
			sum+=a[i];
			i++;
		}
		else
		{
			ans=min(i-j,ans);
			sum-=a[j];
			j++;
		}
	}
	if(ans==1e8)
	{
		cout<<0;
	}
	else
	{
		cout<<ans;
	}
	return 0;
}