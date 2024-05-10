//MT3031
//https://www.matiji.net/exam/dohomework/6230/3
#include<bits/stdc++.h> 

using namespace std;
#define int long long
const int N=1e5+7;
struct Node{
    int x;
    int t;
}point[N];
int n,m,sum,ans;
priority_queue<int> q;//有空看看priority_queue是啥
bool cmp(Node a,Node b)
{
    return a.x<b.x;
}
signed main( )//int被define了
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>point[i].x>>point[i].t;
    }
    sort(point+1,point+n+1,cmp);//按距离升序
    for(int i=1;i<=n;i++)
    {
        if(sum+point[i].x+point[i].t<=m)
        {
            sum+=point[i].t;
            q.push(point[i].t);
        }
        else if(!q.empty()&&sum-q.top()+point[i].x+point[i].t<=m)//时间超了，试着舍弃上一个点
        {
            sum=sum-q.top()+point[i].t;
            q.pop();
            q.push(point[i].t);
        }
    }
    cout<<q.size()<<endl;
    return 0;
}