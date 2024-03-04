//https://www.lanqiao.cn/problems/1216/learning/?page=1&first_category_id=1&name=%E8%B5%B0%E8%BF%B7%E5%AE%AB
#include<iostream>
#include<queue>
using namespace std;
int a[100][100];
int v[100][100];
int n,m;
int sx,sy,ex,ey;
int flag=0;
struct point
{
	int x;
	int y;
	int step;
};
queue<point> r;
int dx[4]={0,1,0,-1};//背 
int dy[4]={1,0,-1,0};

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		 } 
	}
	cin>>sx>>sy>>ex>>ey;
	
	point start;
	start.x=sx;
	start.y=sy;
	start.step=0;
	
	r.push(start);
	v[sx][sy]=1;
	
	while(!r.empty())
	{
		int x=r.front().x;
		int y=r.front().y;
		if(x==ex&&y==ey)
		{
			flag=1;
			cout<<r.front().step<<endl;;
			break;
		}
	for(int k=0;k<4;k++)
	{
		int tx,ty;
		tx=r.front().x+dx[k];
		ty=r.front().y+dy[k];
		if(a[tx][ty]==1&&v[tx][ty]==0)
		{
			point temp;
			temp.x=tx;
			temp.y=ty;
			temp.step=r.front().step+1;
			r.push(temp);
			v[tx][ty]=1;//标记走过 
		}
	}
	r.pop();//pop掉队头直到无法插入但还在一直pop，直到队列为空跳出循环 
}
if(flag==0)
{
	cout<<-1<<endl;
}
	return 0;
}