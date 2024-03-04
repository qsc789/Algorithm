#include<iostream>
#include<vector>
using namespace std;
int n;
int s[1000];
int order[100];
bool chosen[100];
void calc(int k)
{
	if (k == n + 1)
	{
		for (int i = 1; i <= n; i++)
		{
			cout << order[i] << " ";
		}
		cout << endl;
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (chosen[s[i]])
			{
				continue;
			}
		chosen[s[i]] = true;
		order[k] = s[i];
		calc(k + 1);
		chosen[s[i]] = false;
		order[k] = 0;
		}
		
	}


}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	calc(1);
	return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int n; //共计N个数
int order[20];
bool chosen[20];
void calc(int k)
{
   if (k == n + 1)
   {
       for (int i = 1; i <= n; i++)
           cout << order[i] << " ";

       puts("");

       return;
   }
   for (int i = 1; i <= n; i++)
   {
       if (chosen[i])
           continue;
       order[k] = i;
       chosen[i] = 1;
       calc(k + 1);
       chosen[i] = 0;
       order[k] = 0;
   }
}
int main()
{
   cin >> n;
   calc(1);
}