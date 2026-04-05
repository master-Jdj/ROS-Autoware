#include <bits/stdc++.h>

using namespace std;

// 题目：有一n升水箱（n<=10L）,有一个x毫升的水杯（100~300），请问最多能倒几杯水

// 输入：n x       输出：最多能倒的杯数，不足一杯算一杯

int main()
{
    //分支题目
    int n, x;
    cin >> n >> x;
    n = n * 1000; //升转毫升
    cout << ceil(n*1.0/x) << endl; //采用函数向上取整，除以x得到杯数
    //条件判断
    if (n%x) cout << n/x+1  << endl; //如果有余数Ture，说明不足一杯，算一杯
    else cout << n/x << "整杯" << endl; //否则直接输出杯数


    return 0;
}