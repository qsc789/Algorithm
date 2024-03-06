//https://www.lanqiao.cn/problems/3498/learning/?page=1&first_category_id=1&tags=2023
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
  long long num=23333333;
  
  for(long long i=1;i<num;i++)
  {
    double p0=i*1.0/num;
    double p1=(num-i)*1.0/num;
    double sum=-i*1.0*p0*log2(p0)-(num-i)*1.0*p1*log2(p1);
    if(fabs(sum-11625907.5798)<0.0001)//double小数位数较多，这样来算四舍五入
    {
      cout<<i;
      break;
    }
  }
  return 0;
}