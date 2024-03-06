//https://www.lanqiao.cn/problems/3494/learning/?page=1&first_category_id=1&tags=2023
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int sum[520];
int month,day,h,mi,s;
int Month[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    
int main()
{
	int ans=0;
	for(int i=0;i<520;i++)
	{
		string str;
		getline(cin,str);
		 month = (str[6] - '0') + (str[5] - '0') * 10;
        day = (str[9] - '0') + (str[8] - '0') * 10;
        h = (str[12] - '0') + (str[11] - '0') * 10;
        mi = (str[15] - '0') + (str[14] - '0') * 10;
        s = (str[18] - '0') + (str[17] - '0') * 10;
        sum[i] = (Month[month - 1] + day) * 86400 + h * 3600 + mi * 60 + s;
	}
	sort(sum,sum+520);
	
	for(int i=0;i<520;i+=2)
	{
		ans+=sum[i+1]-sum[i];
	}
	cout<<ans;
	return 0;
 } 