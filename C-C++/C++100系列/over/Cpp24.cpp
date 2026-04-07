#include <iostream>
using namespace std;

/*
题目描述：在1~n中，输出带有特殊为数的数
题目分析：特殊尾数：2、3、7

*/
int main()
{
    int n;
    cin >> n;
    for (int i = 1 ; i <= n; i++)
    {
        if (i%10 == 2 || i%10 == 3 || i%10 == 7)
            cout << i << endl;
    }


    return 0;
}
