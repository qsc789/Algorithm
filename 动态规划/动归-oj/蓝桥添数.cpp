//#include<iostream>
//using namespace std;
// int res=0;
// void DFS(int n)
// {
//     if(n==1)
//     {
//       return ;
//     }
//     else
//     {
//       for(int i=1;i<n/2;i++)
//       {
//         res++;
//         DFS(i);
//       }
//     }
// }
//int main()
//{
//    int num = 0;
//    cin >> num;
//    int f[1000] = { 0 };
//    for (int i = 1; i <= num; i++)
//    {
//        for (int j = 1; j <= i / 2; j++)
//        {
//            f[i] = f[i] + f[j];
//        }
//        f[i]++;
//    }
//    cout << f[num] << endl;
//
//    return 0;
//}
#include<iostream>
using namespace std;
int res = 1;
void DFS(int n)
{
    if (n == 1)
    {
        return;
    }
    else
    {
        for (int i = 1; i <= n / 2; i++)
        {
            res++;
            DFS(i);
        }
    }
}
int main()
{
    int num = 0;
    cin >> num;
    DFS(num);
    cout << res << endl;
}