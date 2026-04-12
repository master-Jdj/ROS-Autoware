#include <iostream>

using namespace std;

//问题描述：找出满足条件的2位整数。
//2位数的十位比个位大，十位+个位之和是偶数。

int main()
{
    for (int i = 10 ; i<=99; i++)
    {
        if ((i/10 > i%10) && ((i/10 + i % 10)%2 ==0))
        {
            cout << i << endl;
        }
    }


    return 0;
}