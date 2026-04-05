
#include <bits/stdc++.h>

using namespace std;

/*
题目解释：温度转换问题 
摄氏度与华氏度的转换公式为：f = c * 9 / 5 + 32
其中c表示摄氏度，f表示华氏度。


分析:
input: c 摄氏度
output: f 华氏度 保留两位小数

*/

int main()
{

    double c, f;
    cin >> c;
    //f = c * 9 / 5 + 32;   //方式1
    //printf("华氏度：%.2f\n",f);

    //方式2 C++方式    << endl; 代表换行
    cout << fixed << setprecision(2); //设置输出格式为小数点后两位
    cout << c * 9/5 + 32 << endl;

    return 0;

}