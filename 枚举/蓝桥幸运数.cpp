https://www.lanqiao.cn/problems/613/learning/?page=1&first_category_id=1&problem_id=613
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	long long n=59084709587505;
	int ans=0;
	for(int i=0;pow(7,i)<n;i++)
	{
		for(int j=0;pow(5,j)<n;j++)
		{
			for(int k=0;pow(3,k)<n;k++)
			{
				if(pow(7,i)*pow(5,j)*pow(3,k)<=n)
				{
					ans++;
				}
			}
		}
	}
	cout<<ans-1;
	return 0;
}