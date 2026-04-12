//指针就是地址（指针变量），变量的指针就是变量的地址，指针变量存储地址变量，与int等只是数据类型不同
/* 运算符
&  取地址运算符：获取变量的地址，示例：&ver 就是获取变量ver的 地址
*  解引用(取内容)运算符：获取指针变量指向的地址的值，示例：*ptr  就是获取ptr指向的地址的 变量值
    数组指针采用偏移访问，p[i] 等价于  *(p + i)  即通过指针偏移访问数组元素
.  成员访问运算符：通过指针直接访问结构体或类的成员，示例：ptr.ber 就是通过结构体对象ptr访问成员ber
->  成员访问运算符：通过结构体指针访问成员，示例：ptr->member 就是通过结构体指针ptr访问成员member

*/

#if 0 
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    // T *ptr;  定义一个指针变量ptr，指向类型T的数据，需要定义指针变量的类型
    int *p = &a;  //定义一个指针变量p，存储变量a的地址
    cout << p << '\t' << &a << endl;  //输出指针变量p的值（地址）和变量a的地址，地址结果相同
    //取内容运算符 *  用于获取指针指向的变量（内存块）
    cout << *p << '\t' << a << endl;  //输出指针变量p指向的地址的值和变量a的值，值结果相同
    *p = 20;  //通过指针变量p修改指向地址的值，改变了变量a的值,*p就是a
    cout << *p << '\t' << a << endl;  
    //新指针获取旧指针的值
    int *q = p;   //此时 q 和 p 都存储了 变量a的地址
    cout << q << '\t' << p << '\t' << &a << endl;  //输出指针变量

    //char *s = &a;  //错误，指针类型要匹配
}
#endif 

#if 0 //指针指向内在数组
#include <iostream>
using namespace std;

int main()
{
    int a[] = {1,2,3,4,5};  //存放在堆栈中的内在数组
    int *p = a;  //数组名a表示数组的起始地址，即 a == &a[0]
    // p[i] 等价于  *(p + i)  即通过指针偏移访问数组元素
    cout << p[2] << '\t' << *(p+2) << '\t' << a[2] << endl;  //输出数组的第3个元素
    //p+5：尾后位置，可以存在但不能解引用(即访问)
    for (int *q = p + 5; q > p; p++)  //通过指针遍历数组，p从a的起始地址开始，直到超过数组末尾
        cout << *p << " ";
    cout << "\n";
}  
#endif

#if 0 //动态内存分配
//堆存储区（动态内存）和栈存储区（内在数组）

/* 堆存储区是共享的存储区，空闲内存
C 申请内存：malloc  释放内存：free
C++ 申请内存：new  释放内存：delete
T *p = new T  //申请一个类型为T的对象，返回指向该对象的指针
T *p = new T[n]  //申请一个类型为T的数组，包含n个元素，返回指向该数组首元素的指针

可见申请的对象没有名字，无法直接访问，只能通过指针访问

delete p  //释放指针p指向的对象
delete [] p  //释放指针p指向的数组

*/

#include <iostream>
using namespace std;
int main()
{
   int *p = new int;  // malloc  //申请一个int类型的对象
   *p = 10;  //通过指针p访问和修改该对象的值
   cout << p << endl;
   
   delete p;  //释放指针p指向的对象
   //多次，如果使用完后不释放内存会导致内存泄漏，即申请的内存无法再被使用，造成资源浪费
   p = new int; //前面已经定义了指针 p 
   *p = 20; //重新使用指针p访问和修改新申请的对象的值
   cout << p << endl;
   delete p;

//如果第一次申请使用后没有释放，一般第二次申请会与第一次地址不同。即会同时占用两个内存块
}
#endif

#if 0  //申请数组对象
#include <iostream>
using namespace std;

//类型转换图形演示
void drawTable() {
    const int rows = 5;
    const int cols = 4;
    const int cellWidth = 5;

    for (int r = 0; r < rows; ++r) {
        // 横线
        for (int c = 0; c < cols; ++c) {
            cout << "+";
            for (int i = 0; i < cellWidth; ++i) cout << "-";
        }
        cout << "+\n";

        // 空白内容行
        for (int c = 0; c < cols; ++c) {
            cout << "|";
            for (int i = 0; i < cellWidth; ++i) cout << " ";
        }
        cout << "|\n";
    }

    // 底线
    for (int c = 0; c < cols; ++c) {
        cout << "+";
        for (int i = 0; i < cellWidth; ++i) cout << "-";
    }
    cout << "+\n";
}
int main()
{   
    int n = 5;
    int *p = new int[n];  //申请一个长度为n的int数组
    
    // for (int i = 0; i < n; i++)
    //     p[i] = i + 1;  //通过指针p访问和修改数组元素，p[0]=*(p+0)
    // for (int *q = p+n; p<q; p++)  //都是 地址＋1
    // //同样使用尾后位置，遍历数组
    //     cout << *p << " ";
    // cout << "\n";

    //类型转换
    char *s = (char *)p;  //将指针p强制转换成char指针
    //int 4字节，char 1字节，在char类型看来会将1个int空间看作4个char空间，
    // 但实际内存分配并未改变。如：在本次申请了5个int单元，
    // 但转为char类后就等于4*5=20个char单元
    drawTable();  //调用函数绘制表格，演示类型转换后内存布局
    char ch = 'A';
    int n2 = n*sizeof(int)/sizeof(char);  //计算转换后数组的长度，n2=20=5*4/1
    for (int i = 0; i < n2; i++)  //先用指针赋值
        s[i] = ch + i;
    for (char *r = s + n2; s < r; s++)  //使用指针遍历数组
        cout << *s << " ";
    cout << "\n";

    delete [] p;  //释放指针p指向的所有数组对象

}

#endif
