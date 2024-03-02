#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
  long long num;
  long long sum;
  cin>>num>>sum;
  vector<int> mon(num);
  for(int i=0;i<num;i++)
  {
  	cin>>mon[i];
  }
  sort(mon.begin(),mon.end());
  double avg=sum*1.0/num;
  double ans = 0;
  for(int i = 0 ;  i < num; i++){
    if(mon[i]*(num-i) <sum)//不到新的avg 
	{
        ans += (avg - mon[i]) * (avg - mon[i]);
        sum -= mon[i];
    }
    else{
      double cur = sum*1.0/(num-i);//更新avg 
      ans += (cur-avg)*(cur-avg)*(num-i);
      break;
    }
  }
  printf("%.4lf", sqrt(ans/num));
  return 0;
}