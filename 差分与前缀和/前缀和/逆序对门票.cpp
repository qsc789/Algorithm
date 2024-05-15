//MT2057
//https://www.matiji.net/exam/dohomework/6317/1
//思路是输入数字，每个数据减去门票钱，找和>0的子序列，输入的时候算前缀和，i到j的序列和为sum[j]-sum[i-1],所以就是查找sum中后面元素比前面大的逆序对，用归并排序
#include<bits/stdc++.h> 

using namespace std;
long long n,t;
long long num[1000005];
long long sum[1000005];
long long temp[1000005];
const int N=1e9+7;
long long ans;
//降序归并
void merge_sort(int left,int right,long long* n)
{
    //分割阶段
    if(left>=right)
    {
        return;
    }
    int mid=(left+right)/2;
    merge_sort(left,mid,n);
    merge_sort(mid+1,right,n);
    //合并阶段
    int flag=0;
    int m=mid+1,l=left;
    while(l<=mid&&right>=m)//合并左右数组，挑大的放到temp里
    {
        if(n[l]<=n[m])
        {
            temp[flag]=n[m];
            flag++;
            m++;
            //需要交换说明是逆序对
            ans+=mid-l+1;//l到mid中间都是有序的，所以逆序数是中间的长度
            ans%=N;
        }
        else
        {
            temp[flag]=n[l];
            flag++;
            l++;
        }
    }
    while(l<=mid)
    {
        temp[flag]=n[l];
        flag++;
        l++;
    }
    while(m<=right)
    {
         temp[flag]=n[m];
        flag++;
        m++;
    }
    //再拷贝回来
    for(int i=left,m=0;i<=right;i++,m++)
    {
        n[i]=temp[m];
    }
}
int main( )
{
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        num[i]-=t;
        sum[i]=sum[i-1]+num[i];
    }
    merge_sort(0,n,sum);
    cout<<ans%N;
    return 0;
}