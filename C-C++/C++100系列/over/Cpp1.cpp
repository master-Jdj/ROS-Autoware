#include <bits/stdc++.h>

/* 

题目解释：
键盘读入2个整数，分别代表一个长方形的长和宽，
输出这个长方形的面积 area 和周长 perimeter。
*/ 
using namespace std;

int main()
{
    int length, width;  //定义变量
    cin >> length >> width;  //读取 长 和 宽
    cout << (length + width) * 2 << endl;  //输出周长
    cout << length * width << endl;  //输出面积


    return 0;
}