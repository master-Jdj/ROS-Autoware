#include <bits/stdc++.h>

using namespace std;

/*
题目描述：根据小组男m/女n的人数，分配任务
分析：   n+m<10 : water
        m+n>=10&&m>n : tree
        m+n>=10&&m<=n : tea
input: m n
output: water/tree/tea

*/
int main()
{
    int m, n, t;
    cin >> m >> n;
    t = m + n;
    if (t<10) cout << "water";
    else if (m>n) cout << "tree";
    else cout << "tea";


    return 0;
}