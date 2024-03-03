#include<iostream>
using namespace std;
int f(int n,int k)
{
  if(n==0||k==0||n<k)
  {
    return 0;
  }
  if(k==1||n==k)
  {
    return 1;
  }
  else
  {
    return f(n-k,k)+f(n-1,k-1);//f(n,k)表示把n划分为k份的方法数
    //不考虑1+考虑1
  }
}
int main()
{
  int n,k;
  cin>>n>>k;
  cout<<f(n,k)<<endl;
  return 0;
}