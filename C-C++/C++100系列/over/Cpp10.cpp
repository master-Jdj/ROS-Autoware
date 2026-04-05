#include <bits/stdc++.h>

using namespace std;

/*
题目解释：判断三位数是否对称
  回复输出：Y   N
分析：
input：
output：


*/

int main()
{
    int n, ge, shi, bai, res;
    //采用倒置输出比较的方法,输入必须是三位数
    cin >> n;
    ge = n % 10; //个位
    shi = n/10 % 10; //十位
    bai = n/100; //百位
    res = ge * 100 + shi * 10 + bai; //倒置输出
    if(res == n) cout << "Y" << endl;
    else cout << "N" << endl;
    system("pause");//保持窗口




    return 0;
}