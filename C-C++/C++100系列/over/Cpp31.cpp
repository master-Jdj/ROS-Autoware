//求水仙花数100~999
//分析：各个数字的立方和等于这个数本身

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int *p = new int[4];  //申请一个长度为4的int数组
    for (int i=100; i<=999; i++)
    {
        p[0] = i%10;
        p[1] = i%100/10;
        p[2] = i/100;
        p[3] = pow(p[0],3) + pow(p[1],3) + pow(p[2],3);
        if(p[3] == i)
            cout << i << '\n';
        
    }
    delete []p;

    return 0;
}
