#include <bits/stdc++.h>

using namespace std;

/*
问题解释：打电话，计算通话费用
简单题型，10分钟内（包含），每分钟1.5元；10分钟以上，所有时间每分钟1.2元


*/

int main()
{
    int time;
    cin >> time;
    if (time <= 10 ) cout << time * 1.5 << endl;
    else cout << time * 1.2;


    return 0;

}