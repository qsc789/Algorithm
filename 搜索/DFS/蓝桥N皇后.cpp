
#include <iostream>
#include <cstdio>
using namespace std;
int x[15] = {0};
int sum,n;

int PD(int k)
{

    for(int i=1; i<k; i++)
    {
        if(abs(k-i)==abs(x[k]-x[i]))
            return 0;
        else if (x[k]==x[i])
            return 0;
        //即判断是否符合条件来放,i表示皇后所在的行数，x[i]表示所在的列数，
        //所以前面那个条件用来判断两个皇后是否在对角线上,后面用来判断是否在同一列上。
        //行数不需要判断，因为他们本身的i就代表的是行数
    }
    return 1;
}

bool check(int a)
{

    if(a>n)
        sum++;
    else
        return 0;
    return 1;
}

void DFS(int a)
{
    if(check(a))
        return ;
    else
        for(int i=1; i<=n; i++)
        {
            x[a]=i;
                //第a个皇后放的列数
            if(PD(a))
                    //判断是否能放这步
                DFS(a+1);
                    //能的话进行下一个皇后的放置
            else continue ;
                    //不能就下一列
        }
}
int main()
{
    cin>>n;
    //表示几个皇后
    DFS(1);
    //每次都从第一个皇后开始
    cout<<sum<<endl;
    return 0;
}