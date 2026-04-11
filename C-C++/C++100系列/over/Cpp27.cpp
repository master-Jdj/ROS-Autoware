#include <iostream>

using namespace std;

//问题描述：找出满足条件的3位整数。
//3位数的十位+个位+百位之和是偶数。bai > shi > ge

int main()
{
    for (int i = 100 ; i<=999; i++)
    {
        int bai = i/100;
        int shi = i/10%10;
        int ge = i%10;
        if ((ge+shi+bai)%2 == 0 && bai>shi && shi>ge)
            cout << i << endl;
             
    }


    return 0;
}