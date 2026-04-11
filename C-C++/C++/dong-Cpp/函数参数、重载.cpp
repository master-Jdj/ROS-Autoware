//主要介绍函数的默认形参和函数的重载

//函数默认形参，即函数的参数可以有默认值，如果调用函数时没有传入实参，则使用默认值。
/*  tip：
1、默认形参必须设置在非默认形参的右边 如：add(y,x=0) 不能设置成 add(x=0,y)
2、函数形参必须指明数据类型
*/

#if 0   //示例1
#include <iostream>
using namespace std;

void print(char ch, int n = 1){
    for (int i = 0; i<n; i++)
    cout << ch;
}
/* 错误示范 第一类 tip1
void print(int n = 1, char ch){
    for (int i = 0; i<n; i++)
    cout << ch;
}
*/

int main(){
    print('*'); cout << endl;  //调用函数时没有传入实参，使用默认值n=1
    print('*', 3); cout << endl;
    print('+', 5); cout << endl;

    //return 0;
}

#endif
/*-----------------------------------------------------------------------------*/
#if 0   //示例2
#include <iostream>
using namespace std;

void add(int a, int m =3, int n = 1){
    return a+m+n;
}

int main(){
    cout << add(1) << endl;  //调用函数时没有传入实参，使用默认值m=3,n=1
    cout << add(1,2) << endl;  //调用函数时,  m传入实参2，使用默认值n=1
    cout << add(1,2,3) << endl;  //调用函数时,  m传入实参2，n传入实参3
    //return 0;
}

#endif

//函数重载 C++允许同一个函数名，但是参数列表不同，即为函数重载。
//example:   int add(int a,int b);         double add(double a,double b);
/*  tip：
1、函数重载的函数名是相同，函数名都是add
2、函数重载的参数形参列表类型不同，
    如：int a，   double a， 
3、函数名和形参列表构成了函数签名，add(int a,int b)
4、函数重载不能根据返回类型区分，
    如：int add(int a)   double add(int a) 都是一个函数签名 add(int a)
5、不能出现形参列表混乱，
    如：add(5, 7.70) 参数混乱，无法区分调用哪个函数，编译器会报错
    可通过强制转换，add( (double)5, 7.70) 来调用 double add(double a, double b)
*/

#if 0   //示例3
#include <iostream>
using namespace std;
int add(int a, int b =2){
    return a+b;
}
double add(double a, double b = 2.0){
    return a+b;
}
int main(){
    cout << add(5, 3) << endl;  //调用add函数
    cout << add(5.3,7.8) << endl;  //前面已经调用过add函数，所以这里是重载add函数
    //cout << add(5,7.70) << endl;  //函数存在歧义性
    cout << add((double)5, 7.70) << endl;
    //return 0;
}
#endif