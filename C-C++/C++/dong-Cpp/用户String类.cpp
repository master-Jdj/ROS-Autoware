// 本章目的：内置string ---->> 用户自定义String类
// 实现一个String类，模仿内置string的功能，明白string的功能
/*  1、判断字符s是否有内容，即 s ！= 0  或'\0'(不同表达)
    2、计算字符串长度
    3、为字符串分配内存空间
    4、将字符串内容复制到分配的内存空间中
    5、在字符串末尾添加结束字符'\0'
*/
// 涉及知识点：析构函数，拷贝构造函数
/* 释疑解难
1#  什么是结束字符'\0'？为什么要在字符串末尾添加结束字符？
    作用是告诉程序“字符串到这里结束了”。没有它，程序就不知道字符串读到哪里停
2#  拷贝构造函数
    拷贝构造函数是“用一个已有对象来初始化新对象”的函数。
--默认是浅拷贝，两个对象的data指针指向同一块内存空间
--用户定义，进行深拷贝，每个对象都有自己独立的内存空间
3#  重载输出流运算符<< ，是如何输出String对象的内容的？
    关键在于<<是拷贝构造函数的参数，调用了拷贝构造函数，输出了String对象的内容
4#  什么是析构函数,什么作用，何时调用
--析构函数是对象销毁时自动执行的函数，名字是~String()（这里String是不固定的名字）
--作用是释放对象占用的资源，尤其是堆内存
--在对象生命周期结束时调用，离开对象作用域
解释了为什么每次输出String对象时，都会执行析构函数中的输出语句。
*/
#if 1
#include <iostream>

using namespace std;

class String {
  // data常用于 存储字符数组的首地址 的指针名字
  // 用于字符串
  char *data; // C风格字符串
  int n;

public:       // 首先要有构造函数
              // 4#  默认 ~String(){}
  ~String() { // 析构顺序：后创建，先析构（是合理的-堆栈）
    cout << "~析构函数~\n";
    if (data) { // 事实上data！=0，也可以delete
      delete[] data;
    }
    // 如果多个data指针指向同一块内存空间，析构函数会多次delete同一块内存空间，导致程序崩溃
    // 默认拷贝构造函数，又说会使data指向同一地址，所以不应随意执行默认拷贝构造函数，采用自定义
  }
#if 0
//编译器自动生成-->默认的拷贝构造函数
  String(const String &s) {   //硬拷贝
    // 3#
    cout << "调用了拷贝构造函数" << endl;
    // data = s.data; //被注释内容为默认的拷贝构造函数
    // n = s.n;    //下面是用户定义的拷贝构造函数
    data = new char[s.n + 1];
    n = s.n;  //构造函数里定义了n为字符串长度
    for (int i = 0; i < n; i++)
      data[i] = s.data[i];
    data[n] = '\0';
  }
#endif
  // 参数构造函数加入了默认值
  String(const char *s = 0) { // 使用const，保护s指向的字符串内容不被修改

    cout << "构造函数！\n";
    // 1
    if (s == 0) {
      cout << "s == 0\n";
      data = 0;
      n = 0;
      return;
    }
    // 2  计算字符串长度 ，s是字符串的首地址，p是字符串的结束位置地址
    const char *p = s;
    while (*p) // 如果*p不为0，说明字符串没有结束
      p++;
    n = p - s; // 字符串长度=字符串结束位置-字符串开始位置
    // 3  为字符串分配内存空间
    data = new char[n + 1]; // 多加一个字节存储结束字符'\0'
    // for (int i = 0; i <= n; i++)
    //  4 将字符串内容复制到分配的内存空间中
    for (int i = 0; i < n; i++)
      data[i] = s[i];
    // 5
    data[n] = '\0'; // 前面放置字符串内容，最后n放置结束字符
  }
  int size() { return n; };
  // 下标访问运算符重载必须是成员函数
  char operator[](int i) const { // const函数 用于查询
    if (i < 0 || i >= n)         // 为了规范访问，越界访问抛出异常
      throw "下标非法";
    return data[i]; // 返回字符串中第i个字符
  }
  char &operator[](int i) { //
    if (i < 0 || i >= n)
      throw "下标非法";
    return data[i];
  }
};
ostream &operator<<(ostream &o, String &s) {
  for (int i = 0; i < s.size(); i++) {
    o << s[i];
  }
  return o;
}

// int main()
void f() {
  // str使用默认，str2传入字符串参数
  String str, str2("hello world");
  // int a;
  str2[1] = 'E';

  // 重载输出流代替
  //  for (int i = 0; i<str2.size(); i++) {
  //      cout << str2[i] << endl;
  //  }
  cout << str2 << endl;

  // int i = 0;
#if 0
  String s3 = str2; // 这里执行了默认的拷贝构造函数（用户无定义）
  //s3是str2的一个副本，存储完全一致，s3.data和str2.data指向同一块内存空间，s3.n和str2.n相等
  cout << s3;
//对s3的修改会影响str2，因为它们指向同一块内存空间，
//避免这种问题，需要定义一个拷贝构造函数
  s3[3] = 'L';
  cout << s3 << endl;
  cout << str2 << endl;
#endif
  // return 0;
}

int main() { f(); }

#endif