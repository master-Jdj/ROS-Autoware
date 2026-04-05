#include <bits/stdc++.h>

/*
题目解释: 玫瑰花圃
  有一块n*n（n>=5,且n是奇数）的玫瑰花圃，现要求花圃
  最中间一行和一列，以及四个顶点处种植粉色玫瑰，其余种植
  红玫瑰，问粉色玫瑰占整个玫瑰花圃总面积的百分之多少？
分析：
input：n
output：per


*/

using namespace std;
//数学计算法

int main()
{
    int n;
    double per;

    cout << "请输入n>=5的奇数:" << endl;
    cin >> n;
    if(n%2==0)
    {
        n = n - 1;
    }

    per = (double)(2 * n - 1 + 4) / (n * n); 
    cout << fixed << setprecision(2);  //设置输出小数点后两位
    cout << "粉色玫瑰占比=" << per * 100 << "%" << endl;

    return 0;
}