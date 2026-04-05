#include <bits/stdc++.h>

using namespace std;

/*
题目描述：判断成绩等级
题目分析：{
score >=86:VERY GOOD, 
85 >= score >= 60 :GOOD,
score < 60 :BAD
}

input: soure
*/

int main()
{
    int score;
    cin >> score;
    if(score >= 86 ) cout << "VERY GOOD";
    else if(score >= 60) cout << "GOOD";
    //由于if else结构，当>=86的情况为Ture，不会继续判断;
    else cout << "BAD";

    return 0;
}
