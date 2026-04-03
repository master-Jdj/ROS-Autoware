#include <bits/stdc++.h>

using namespace std;

//判断6位数是否对称

int main()
{
    int n, a1, a2, a3, a4, a5, a6, res;
    cin >> n;
    a1 = n / 100000;
    a2 = n / 10000 % 10;
    a3 = n / 1000 % 10;
    a4 = n / 100 % 10;
    a5 = n / 10 % 10;
    a6 = n % 10;
    res = a6 * 100000 + a5 * 10000 + a4 * 1000 + a3 * 100 + a2 * 10 + a1;
    if (res == n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;



    return 0;
}