//https://www.lanqiao.cn/problems/99/learning/
#include<bits/stdc++.h>
using namespace std;
int maxn=100010;
int h[maxn],w[maxn];
int n,k;
bool pd(int l)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=(h[i]/l)*(w[i]/l);
    }
    if(sum>=k)
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
  cin>>n>>k;
  int high=0;
  for(int i=0;i<n;i++)
  {
    cin>>h[i]>>w[i];
    high=max(high,max(h[i],w[i]));
  }
    int low=0;
    int mid=(high+low+1)/2;
    while(low<high)
    {
        if(pd(mid))
        {
            low=mid;
        }
        else
        {
            high=mid-1;
        }
        mid=(high+low+1)/2;
    }
  cout<<low;
  
}