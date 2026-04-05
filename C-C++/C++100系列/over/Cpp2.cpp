#include <bits/stdc++.h>

/*
题目解释：小数运算
已知一个圆的半径，求解该圆的面积area和周长perimeter

分析：
input: 输入一个圆的半径 R
output: 输出该圆的周长和面积;保留2位小数，pi取3.1415926
*/

using namespace std;

int main()
{   
    const double pi = 3.1415926;  // 定义常量pi

    double R;
    cin >> R;   // 输入'cin'圆的半径

    double perimeter = 2 * pi * R;  // 圆的周长公式：C=2πR
    double area = pi * R*R;  // 圆的面积公式：S=πR² 
    //采用C的办法控制输出格式，保留两位小数
    printf("%.2f\n", (double)pi * pow(R,2));   //pow函数计算R的平方
    printf("%.2f\n", (double)R * 2 * pi);
    
    
    //cout << perimeter << " " << area << endl;  //output
    return 0;
}