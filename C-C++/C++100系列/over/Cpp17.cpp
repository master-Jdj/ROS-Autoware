#include <bits/stdc++.h>

using namespace std;

/*
问题描述：读入一个三位数，计算最大数和最小数的差值
input：n

*/
int TC(int a, int b, int c)
{
    int MAX ,MIN;
    MAX = a;
    MIN = a; 
    if (b>MAX) //b一定不是最小数，a一定不是最大数（唯一）
    {
        MAX =c;
        //MIN = a;  已经初始化为a了
        if (b>MAX){  //b最大成立，否则c最大成立
            MAX =b;
            if (c<MIN) MIN = c; //c最小成立,否则a最小成立
        }
    }
    //否则情况：b一定不是最大数,a一定不是最小数
    else if (c>MAX)//判断c是否最大
    {
        MAX = c;
        MIN = b; //前面判断b<a,现在c>a
    }
    else //c<a,b<a,前面已经判断出
    {
        //MAX = a;//前面已经初始化为a了
        MIN = b;
        if (c<MIN) MIN = c; //c最小成立，否则b最小成立
    }
    
    return abs(MAX-MIN);    

}


int main()
{
    int n, Max, Min, ge, shi, bai;
    cin >> n; // 读入
    ge = n%10;
    shi = n/10%10;
    bai = n/100;

    //采用内置函数max和min来计算最大值和最小值
    // Max = max(ge,max(shi,bai));
    // Min = min(ge,min(shi,bai));
    // cout << Max-Min;
    //方法2，自定义3位比大小函数，输出最大值和最小值
    cout << TC(ge,shi,bai);
    return 0;
}