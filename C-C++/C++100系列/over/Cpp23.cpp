
#include <iostream>
using namespace std;

/*
题目描述：输入范围1~n，反向输出范围内的所有整数，每行一个
input: n

*/

int main()
{
    int n;
    cin >> n;
    for (int i = n ; i >=1 ; i--)
    {
        cout << i << endl;
    }

    return 0;
}