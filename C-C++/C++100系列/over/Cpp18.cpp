#include <bits/stdc++.h>

using namespace std;

/*
问题描述： 找四个数的最大数
input: a,b,c,d
output: max(a,b,c,d)
*/

//采用打擂台方法
int main()
{
    int a, b, c, d, maxn;
    cin >> a >> b >> c >> d;
    maxn = a;
    if (b > maxn)
        maxn = b;
    if (c > maxn)
        maxn = c;
    if (d > maxn)
        maxn = d;

        cout << maxn << endl;

    return 0;
}