#include<iostream>
#include<algorithm>
using namespace std;
const int Maxn=1e5+50;
int a[Maxn],b[Maxn];
int n,m;
int main()
{
	cin>>n>>m;
	while(m--)
	{
		int left,right,value;
		cin>>left>>right>>value;
		//因为从0开始，下标右移
		left++;
		right++;
		b[left]+=value;//对b做改动
		b[right+1]-=value; 
	}
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=b[i]+a[i-1];//相邻项相加
		sum+=a[i];
	}
	cout<<sum;
	return 0;
 } 