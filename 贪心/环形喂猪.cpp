//MT3032
//https://www.matiji.net/exam/dohomework/6230/6
#include<bits/stdc++.h> 

using namespace std;
const int N=4e5+10;
int n,m;
int l[N],r[N];
int ans;
int val[N],tot;//节点总数
bool mark[N];
struct Node{
    int id,v;
    bool operator<(const Node &b) const{return v<b.v;}
}temp;
priority_queue<Node> q;
int main( )
{
    return 0;
    cin>>n>>m;
    if(m>n/2)
    {
        cout<<"Error!";//前后的都不能喂
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    for(int i=2;i<n;i++)//从2到n-1
    {
        l[i]=i-1;//i左边是i-1
        r[i]=i+1;//i右边是i+1
        q.push({i,val[i]});
    }
    //构成环
    l[1]=n,r[1]=2;
    l[n]=n-1,r[n]=1;
    q.push({1,val[1]});
    q.push({n,val[n]});
    tot=n;
    for(int i=1;i<=m;i++)
    {
        temp=q.top();//取堆头
        q.pop();
        if(mark[temp.id])//判断有没有被标记
        {
            i--;
            continue;
        }
        ans+=temp.v;
        tot++;//增加新节点
        val[tot]=val[l[temp.id]]+val[r[temp.id]]-val[temp.id];
        q.push({tot,val[tot]});
        l[tot]=l[l[temp.id]];
        r[l[l[temp.id]]]=tot;
        r[tot]=r[r[temp.id]];
        l[r[r[temp.id]]]=tot;
        mark[temp.id]=mark[l[temp.id]]=mark[r[temp.id]]=1;
    }
    cout<<ans;
    return 0;
}