//进入简单的循环结构
#include <iostream>
using namespace std;

/*
题目描述：输入范围，输出范围内的所有整数，每行一个
input: min max

*/

int main()
{
    int min, max;
    cin >> min >> max;
    for (int i = min ; i <= max; i++)
    {
        cout << i << endl;
    }
    
    return 0;
}