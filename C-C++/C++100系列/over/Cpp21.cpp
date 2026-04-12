#include <bits/stdc++.h>

using namespace std;

/*
问题描述：闰年判断，输出Y/N
分析：条件2选一（1.能被4整除但不能被100整除 2.能被400整除）
input: year
output: Y/N
*/

int main()
{
    int year;
    cin >> year;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 ==0)
    {
        cout << "Y";
    }else{
        cout << "N";
    }



    return 0;
}
