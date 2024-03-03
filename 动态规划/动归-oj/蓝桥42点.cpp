#include <iostream>
using namespace std;
#include <vector>
 
/*思路：定义一个容器数组，即总共有五个容器，分别记录从第一次运算到第五次运算的所有值，然后遍历最后那个容器，看看有没有值为42的数*/
 
int main()
{
  char c;
  int a[10];         //保险起见就把空间给大一点
  vector<int> ans[10];
  for(int i = 0 ; i<6 ;i++)
  {  
    cin >> c;
    if(c=='A')
    a[i]=1;
    else if(c=='J')
    a[i]=11;
    else if(c=='Q')
    a[i]=12;
    else if(c=='K')
    a[i]=13;
    else
    a[i]=(c-'0');
  }
  
    ans[0].push_back(a[0]);
  
 
 
  for(int i = 1; i< 6; i++ )        //外层循环是每一个抽到的牌
  {
    for(int j = 0; j< ans[i-1].size() ;j++)   //内层循环是把每一轮操作的值都给压到容器里
    {
      ans[i].push_back(ans[i-1][j]+a[i]);
      ans[i].push_back(ans[i-1][j]-a[i]);
      ans[i].push_back(ans[i-1][j]*a[i]);
      ans[i].push_back(ans[i-1][j]/a[i]);
    }
  }
 
  for(int i = 0 ; i< ans[5].size() ; i++)
  {
    if(ans[5][i]==42)
    {
      cout << "YES" <<endl;
      return 0;
    }
  }
  cout << "NO" <<endl;
 
  // 请在此输入您的代码
  return 0;
}