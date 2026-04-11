/* 输出满足条件的数
 * 条件：1~n中含有数字3或5，且能够被2整除的数
 * 输入：n = 50  （n <= 1000）

*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    bool flag1 = false;
    bool flag2 = false;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        int ge = i%10; // 个位
        int shi = i/10%10;
        int bai = i/100;
        
        if (ge==3 || ge==5 || shi==3 || shi==5 || bai==3 || bai==5)
            flag1 = true; 
        if (i%2==0)
            flag2 = true;
        if (flag1 && flag2)
            cout << i << " ";
        flag1 = false;
        flag2 = false;
    }

    return 0;
}