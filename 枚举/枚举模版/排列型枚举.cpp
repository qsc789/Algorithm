
#include<bits/stdc++.h>
using namespace std;
int n;
int order[20];
bool chosen[20];
void calc(int k)
{
	if(k==n+1)
	{
		for(int i=0;i<sizeof(order)/sizeof(order[0]);i++)
		{
			if(order[i]!=0)
			cout<<order[i]<<" ";		
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(chosen[i])
		{
			continue;
		}
		order[k]=i;
		chosen[i]=1;
		calc(k+1);
		chosen[i]=0;
		order[k]=0;
	 } 
}
int main()
{
	cin>>n;
	calc(1);
	return 0;
}