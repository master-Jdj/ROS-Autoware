#include <bits/stdc++.h>
#include <cmath>

using namespace std;

/*
问题解释：求和
输入一个任意三位数，计算它的各位数字之和。

分析：
input: num
output: sum

提供一个区间比较方法compare ：如一个三位数，外环{m_init=最高位数3，m=-1，m_init+=m}，内环{可以让他先与10^3-i*10^m进行比较，
i=9-1（从大到小），当num>=10^3-i*10^m(m=2)时，说明这个三位数的百位数为i，},
记录为num_p+=i
*/

int compare(int num)  //有问题！！！ 编码格式未解决
{
    int sum = 0;
    int m_init;
    int m = -1;

    cout << "输入一位数" << endl;
    //cin >> num;  //由于main函数已经输入了num，所以这里注释掉
    for (int i=0,m_flag=1 ;m_flag==1;i++)
    {   //获取num位数，赋值给 m_init
        
        if (num-pow(10,i) <= 0)
        {
            m_init = i-1;
            m_flag = 0;
        }
    }

    // 得到m_init代表位数后，进行比较
    for (int i; m_init > 0; m_init += m)
    {
        for (i = 9; i >= 1; i--)
        {
            if (num >= pow(10,m_init) - i * pow(10,(m_init-1)))
            {
                sum += i;
                break;
            }
        }
    }
    
    return sum;
}


int main()
{

    int g, s, b, sum, num, num2;
    cin >> num;
    g = num % 10; // 个位数
    s = num / 10 % 10; // 十位数
    b = num / 100;
    sum = g + s + b;
    cout << sum << endl;

    num2 = compare(num);  // 方法二
    cout << "方法二：" << num2 << endl;



    return 0;
}