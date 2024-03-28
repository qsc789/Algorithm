//https://www.lanqiao.cn/problems/102/learning/?page=1&first_category_id=1&tags=BFS
#include <iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;
string str1,str2;
int n; 
int d[6]={-3,-2,-1,1,2,3};
map<string,int> ans;
int bfs()
{
	queue<string> q;
	q.push(str1);
	ans[str1]=0;
	while(!q.empty())
	{
		string temp=q.front();
		q.pop();
		int cnt=ans[temp];
		int x=temp.find('*');
		for(int i=0;i<6;i++)
		{
			int tx=x+d[i];
			if(tx>=0&&tx<n)
		    {
		    	swap(temp[x],temp[tx]);
		    	if(!ans.count(temp))//哈希表里有就不管
		    	{
		    		ans[temp]=cnt+1;
		    		if(temp==str2)
		    		{
		    			return ans[temp];
		    			
					}
					q.push(temp);
				}
				swap(temp[x],temp[tx]);
			 } 
		}
		
	}
	return -1;
	
}
int main()
{
  
  cin>>str1>>str2;
  n=str1.size();
  cout<<bfs()<<endl;
  
  return 0;
}