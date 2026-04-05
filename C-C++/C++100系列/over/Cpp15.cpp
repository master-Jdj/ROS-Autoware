#include <iostream>

using namespace std;

//题目：求三个数的最大值
//输入：一行，整数间隔一个空格  输出：一个整数，三个数的最大值

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    // //充要条件判断
    // if (a>=b && a>=c) cout << a;
    // else if (b>=a && b>=c) cout << b;
    // else cout << c;

    //遍历判断
    if (a>=b){
        if (b>=c) cout << a; 
        else if (a>=c) cout << a;
    }
    else if (b>=c) cout << b;
    else cout << c; 
    
    // //打擂台
    // int max = a;
    // if (b>max) max = b;
    // if (c>max) max = c;
    // cout << max;




    return 0;
}