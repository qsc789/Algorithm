//https://www.lanqiao.cn/courses/31015/learning/?id=1927006&compatibility=false
//a^n mod m=(a mod m)^n mod m
#include<iostream>
using namespace std;
long long fastPow(long long a,long long n,long long mod)
{
  long long ans=1;
  a%=mod;
  while(n)
  {
    if(n&1==1)//按位与，取二进制最后一位 1011跳过a^4
    {
      ans=(ans*a)%mod;//每一步都取模
    }
    a=a*a%mod;//二次方
    n>>=1;//把n右移一位，去掉刚才的最后一位
  }
  return ans;
}
int main()
{
  long long b,p,k;
  cin>>b>>p>>k;
  cout<<fastPow(b,p,k)<<endl;
  return 0;
}