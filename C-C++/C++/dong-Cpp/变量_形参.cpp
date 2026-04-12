//引用变量
/*  引用变量是其他变量的别名
--被引用变量必须初始化,
--须指明被引用的变量,对应的数据类型
--不可重复引用，如：int &r = a; int &r = b; //错误，r只能引用一个变量
*/

#if 0
//实验验证 引用变量和被引用变量为统一体
#include <iostream>
using namespace std;
int main()
{   //a与r使用同一块内存地址，a和r是同一个变量的两个名字
    int a = 10;
    int &r = a;
    cout << "a = " << a << endl;
    cout << "r = " << r << endl;
    a = 20;
    cout << "a = " << a << endl;
    cout << "r = " << r << endl;
    r = 30; //通过引用变量r修改了a的值
    cout << "a = " << a << endl;
    cout << "r = " << r << endl;
    return 0;
}

#endif
//------------------------------------------------------------
//C函数的值形参，有自己的内存空间，函数调用结束后，形参的内存空间被释放
//值形参的修改不会影响实参的值；指针形参 ， 引用形参（C++）
if 0

#include <iostream>

using namespace std;

#if 0
//验证1 函数值形参（占用内存，调用结束free），并不会改变实参的值
void swap(int x, int y)  //交换函数的值形参
{
    int temp = x;
    x = y;
    y = temp;
    cout << "swap内交换后：x = " << x << ", y = " << y << endl;
}
int main()
{
    int a = 10, b = 20;
    cout << "main交换前：a = " << a << ", b = " << b << endl;
    swap(a, b);  //调用交换函数，传递实参a和b
    cout << "main交换后：a = " << a << ", b = " << b << endl; //a和b的值未改变
    return 0;
}
#endif
//-------------------------------------------------------------------
#if 0
//实验2  指针形参，占用内存（调用结束后free）
void swap(int *x, int *y)  //交换函数的指针形参
{
    int temp = *x;  //解引用指针，获取x指向的值
    *x = *y;        //将y指向的值赋给x指向的变量
    *y = temp;      //将temp的值赋给y指向的变量
}

int main()
{
    int a = 10, b = 20;
    cout << a << '\t' << b << endl;  //输出交换前的值
    swap(&a,&b);  //调用交换函数，传递实参a和b的指针
    cout << a << '\t' << b << endl;  //输出交换后的值

    return 0;
}
#endif
//-------------------------------------------------------------------
#if 0
//实验3  引用形参，此时形参是虚拟的没有内存空间，只是实参的别名
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{ 
    int a = 10, b = 20;
    cout << a << '\t' << b << endl;
    swap(a,b);
    cout << a << '\t' << b << endl;

    return 0;
}
#endif
//-------------------------------------------------------------------
#endif