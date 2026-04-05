#include <bits/stdc++.h>

using namespace std;

/*
问题解释：加密四位数
加密方式，每一位数先加上5然后对10取余，再将得到的新数据颠倒输出

分析： 拆位
输入：num
输出：inversion


*/

int main()
{
    int num, ge, shi, bai, qian, inversion;

    cin >> num;
    ge = (num % 10 + 5)%10;
    shi = (num / 10 % 10 + 5)%10;
    bai = (num / 100 % 10 + 5)%10;
    qian = (num /1000 % 10 + 5)%10;

    inversion = ge * 1000 + shi * 100 + bai * 10 + qian;
    cout << inversion << endl;
    
    return 0;
}