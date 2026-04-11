/* 输出所有符合条件的整数
题目描述：一个4位数，qian + bai 为偶数；ge +shi 为奇数，
且 qian + bai > ge +shi ,且含有因数8，求出所有满足条件的整数


*/

#include <iostream>

using namespace std;

int main()
{
    for (int i=1000; i<=9999; i++)
    {
        if(i%8==0)
        {
            int qian = i/1000;
            int bai = i/100%10;
            int shi = i/10%10;
            int ge = i%10;
            if( (qian+bai)%2==0 && (ge+shi)%2==1 && qian+bai>ge+shi)
            {
                cout<<i<<" ";
            }
        }


    }
}
