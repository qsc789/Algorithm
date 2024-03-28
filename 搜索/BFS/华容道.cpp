//https://www.lanqiao.cn/problems/125/learning/?page=1&first_category_id=1&tags=BFS
#include <iostream>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;
string s;
queue<string> q;
unordered_map<string, int>ans;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int x, y;
int res;
int a, b;


void bfs()
{
    q.push(s);
    ans[s] = 0;
    while (!q.empty())
    {
        string temp = q.front();
        int cnt = ans[temp];
        q.pop();
        int flag = temp.find(' ');
        x = flag / 3;
        y = flag % 3;
        for (int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 0 && tx <= 1 && ty >= 0 && ty < 3)
            {
                swap(temp[flag], temp[tx * 3 + ty]);
                if (ans.count(temp)==0)
                {
                    ans[temp] = cnt + 1;
                    if (temp.find('A') == b && temp.find('B') == a)
                    {
                        //res = ans[temp];
                        cout << ans[temp] << endl;
                        return;
                    }
                    q.push(temp);
                }
                swap(temp[flag], temp[tx * 3 + ty]);
            }
        }
    }

}
int main()
{
    string t;
    for (int i = 0; i < 2; i++)
    {
        getline(cin, t);
        s += t;
    }
    a = s.find('A');
    b = s.find('B');
    bfs();
    //cout << res << endl;
    return 0;
}