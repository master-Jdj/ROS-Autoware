#include <bits/stdc++.h>

using namespace std;

/*
问题描述：判断正方形Y/N，且一定输出面积
input: a ,b
output: area

*/

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == b) cout << "Y" << endl;
    else cout << "N" << endl;
    cout << a*b; 


    return 0;
}
