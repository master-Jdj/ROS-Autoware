//为了解决同一种函数不同参数类型的函数重载问题，C++引入了函数模板，即函数的数据类型为可设置

/*
传统：1+1
    int add(int a, int b)
    double add(double a, double b)
模板：是一种泛型算法，采用关键字 template，将数据类型转为类型模板参数
模板实例化：模板本身不是函数，在传入实际参量时才会生成函数，
    template <typename T>  //声明一个模板，T是一个占位符，代表任意数据类型
    T add(T a, T b) {···}  //函数模板，T是一个占位
*/

#if 0   //示例1
#include <iostream>
using namespace std;
template <typename T>  //声明一个模板，T是一个占位符，代表任意数据类型
T add(T a, T b) {  //函数模板，T是一个占位符
    return a + b;
}
int main() {
    cout << add<int>(5, 3) << endl;  //调用add函数，T可以被指定int
    cout << add(5.3, 7.8) << endl;  //调用add函数，自动根据实参类型推断出T的类型为double
  //cout << add<double>(5.3, 7.8) << endl;
    cout << add<double>(5, 7.7) <<  endl; //参数列表有歧义，必须指定T的类型（double）
    cout << add(string("Hello, "), string("World!")) << endl;  //调用add函数，T被推断为string
    cout << add<string>("Hello, ", "World!") << endl;

    return 0;
}
#endif