//https://www.lanqiao.cn/courses/31015/learning/?id=1926974&compatibility=false
#include <iostream>
using namespace std;
int a[100005];
int sum[100005];


int main()
{
    int n;
    int m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)//算前n项和 
    {
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
    }

    while (m > 0)
    {
        m--;
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
    }
}