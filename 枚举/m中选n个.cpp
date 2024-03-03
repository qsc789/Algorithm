#include<bits/stdc++.h>
using namespace std;
int n;
int m;
vector<int> chosen;
void calc(int x)
{
	if(chosen.size()>m||chosen.size()+(n-x+1)<m)
	{
		return ;
	}
	else if(x==n+1)
	{
		for(int i=0;i<chosen.size();i++)
		{
			cout<<chosen[i]<<" ";
		}
		return ;
	}
	chosen.push_back(x);
	calc(x+1);
	chosen.pop_back();//走到这说明不选这个数 
	calc(x+1);
}
int main()
{
	cin>>n>>m;
	calc(1);
	return 0;
 } 