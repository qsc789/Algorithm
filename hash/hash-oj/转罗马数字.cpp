class Solution {
public:
    string intToRoman(int num) {
        int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};//模拟哈希表键值对
        string reps[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;

        for(int i=0;i<13;i++)
        {
            while(num>=values[i])
            {
                num-=values[i];
                res+=reps[i];//字符串可直接相加
            }
        }
        return res;
    }
};