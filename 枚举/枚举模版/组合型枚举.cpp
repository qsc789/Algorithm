#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n, m;
vector<int> chosen;
string s[1000];
void calc(int k)
{
	if (chosen.size()>m || chosen.size() + (n - k + 1)<m)//已经判断chosen.size()了
	{
		return;
	}
	else if (k == n+1)//n个数都走完了
	{
		for (int i = 0; i < chosen.size(); i++)
		{
			cout << s[chosen[i]] << " ";
		}
		cout << endl;
		return;
	}
	else
	{
		chosen.push_back(k);
		calc(k + 1);
		chosen.pop_back();
		calc(k + 1);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	calc(1);
	return 0;
}