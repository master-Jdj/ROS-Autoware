#include <iostream>

using namespace std;

/*
题目解释：使用循环求出三位对称数
*/

int main()
{
    int ge, bai;
    for(int i = 100; i<=999; i++)
    {
        ge = i % 10;
        bai = i / 100;
        if (ge == bai) cout << i << endl;
    }

    return 0;
}