#include <bits/stdc++.h>

using namespace std;

/*
问题解释：输入一个4位数，颠倒输出

输入：num

输出：mun

*/

int main()
{

    int num;
    cin >> num;

    int a = num / 1000;
    int b = num / 100 % 10;
    int c = num / 10 % 10;
    int d = num % 10;

    cout << d << c << b << a << endl;


    return 0;
}