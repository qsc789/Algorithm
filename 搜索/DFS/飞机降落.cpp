//https://www.lanqiao.cn/problems/3511/learning/?page=1&first_category_id=1&tags=2023&name=%E9%A3%9E%E6%9C%BA%E9%99%8D%E8%90%BD
#include <iostream>
#include <vector>
using namespace std;

struct plane
{
    int start;
    int last;
    int waste;
};
bool vis[15];  
int flag=0;  
vector<plane> p(15);

void dfs(int m, int cnt, int time) //time指前cnt-1个飞机降落需要的总时间
{
    if (cnt == m+1)
    {
        flag = 1;
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        if (!vis[i] && p[i].start + p[i].last >= time) 
        {
            vis[i] = true;
            dfs(m, cnt + 1, max(time, p[i].start) + p[i].waste);
            vis[i] = false;//还原现场
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        for (int i = 1; i <= N; ++i)
            cin >> p[i].start >> p[i].last >> p[i].waste;
        flag = 0;
        dfs(N, 1, 0);
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}