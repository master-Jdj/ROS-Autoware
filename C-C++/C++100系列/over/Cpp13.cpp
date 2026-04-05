#include <bits/stdc++.h>

using namespace std;

// 判断三角形 a b c 是否为三角形
//分析：数学中，a + b > c(max)判断简单；但在程序中找出最大值需要遍历，效率较低；
// 因此只需要满足 a + b > c && a + c > b && b + c > a 就可以了；
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a+b>c && a+c>b && b+c>a) cout <<  "Yes";
    else cout << "No";



    return 0;
}