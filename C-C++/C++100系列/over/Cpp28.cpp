/* 输出满足条件的整数
题目描述：有一个数列：{ 1 4 7 10 ···}，从键盘读入一个整数n，
求出1~n中满足条件的所有整数
input: n = 10  
output: 1 4 7 10
分析：Xn = 1+3*(n-1)
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i += 3)
    {
        cout << i << " ";
    }
    
    return 0;
}
