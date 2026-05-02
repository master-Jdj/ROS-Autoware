// 继续上一节程序，分析运算符重载
// 问题：能不能直接使用 <<运算符 来输出用户定义对象的成员变量？
/*
自然是不能的，因为<<运算符是内置运算符，不能够识别用户定义类型
解决方法：重载<<运算符，参考“函数参数、重载.cpp”基础铺垫
· << :本质上是一个函数，完整函数名为 operator<< ，“<<是二元运算符”
· operator 关键字，在C++中常用于定义和重载*已存在*运算符函数
· friend 关键字，确保外部函数能够访问类的私有成员变量
· operator<<(ostream &o, T x) :输入含有两个参数;返回输出类型为 ostream &
    ostream &o 是输出流对象的*引用*，
    T x 表示 T(数据)类型的变量x  (可以是用户定义类型的对象)
--- --- -- ---- ----- --- --  --- - -- - --- -
同样的 ，重载输入流运算符 operator>>
operator>>(istream &in, T &x){return in;}

tip：解释重载 istream & operator>>(istream &in, student &s)
- istream 是函数类型，表示输入流对象类型
#######函数语法框架：返回类型 函数名(参数列表){函数体}#######
- istream & 组成了返回类型，表示返回一个输入流对象的引用*类型*
- operator>> 是函数名，表示重载输入流运算符
- (istream &in, student &s) 是参数列表，包含两个参数
注：由于重载函数中只有in是输入流引用类型，返回值只能return in;
*/

#if 0
#include <iostream>
#include <string>
using namespace std;

// ==========================
// 1) 类定义（含友元声明）
// ==========================
class student {
private:
  string name;
  int age;

public:
  // 默认构造
  student() {
    name = "Lee";
    age = 20;
  }

  // 有参构造
  student(string n, int a) {
    name = n;
    age = a;
  }

  // 采用友元函数，允许外部重载函数访问 private 成员
  friend ostream &operator<<(ostream &o, const student &s);
  friend istream &operator>>(istream &in, student &s);
};

// ==========================
// 2) 运算符重载实现区
// ==========================
// ostream & operator<<(ostream &o, student
// s)功能相似但，该过程先拷贝对象s，效率较低，还存在风险（有些禁止拷贝）
ostream &operator<<(ostream &o, const student &s) {
  // 输出学生信息
  o << s.name << " " << s.age; // 输出到指定流对象，而不写死 cout
  return o;                    // 返回输出流对象引用，支持链式输出
}
// 这里写student
// s只会将传入的值存在另一内存地址，而非对象s的地址，无法达到修改作用
istream &operator>>(istream &in, student &s) {
  // 输入学生信息
  cout << "请输入学生的姓名和年龄：" << endl;
  in >> s.name >> s.age; // 写入对象成员
  return in;             // 返回输入流对象引用，支持链式输入
}

// ==========================
// 3) 测试主函数
// ==========================
int main() {
  cout << "请输入学生的姓名和年龄：" << endl;

  student stu("Wang", 19);

  // 重载前：cout << stu 会报错（不识别自定义类型）
  cin >> stu;  // 等价于 operator>>(cin, stu)
  cout << stu; // operator<<(cout, stu);

  return 0;
}

#endif

#if 0
#include <iostream>

using namespace std;

class Point {
private:
  double x, y;

public:
  // 下标运算符重载，必须是类的成员函数，不能是外部函数
  double operator[](int index) const {
    if (index == 0)
      return x; // 返回的是x的拷贝值，不能修改x的值
    else if (index == 1)
      return y;
    throw "下标非法"; // 抛出异常
  }

  double &operator[](int index) {
    if (index == 0)
      return x; // 返回的是x的拷贝值，不能修改x的值
    else if (index == 1)
      return y;
    throw "下标非法"; // 抛出异常
  }

  Point(double x_, double y_) : x(x_), y(y_) {} // 构造函数,x_初始化x, y_初始化y

  Point operator+(const Point &other) const {
    return Point(this->x + other.x, this->y + other.y);
  } // 调用时，p.operator+(q)，this指针指向p，other参数指向q，返回一个新的Point对象
    //        Point s = p + q;
  // 采用友元函数，允许外部重载函数访问 private 成员
  friend ostream &operator<<(ostream &o, const Point &p);
  friend istream &operator>>(istream &i, Point &p);
};

ostream &operator<<(ostream &o, const Point &p) {
  o << p.x << " " << p.y << endl;
  return o; // 返回输出流对象引用，支持链式输出
}

istream &operator>>(istream &i, Point &p) {
  i >> p.x >> p.y; // 写入对象成员，Point类的成员变量x和y
  return i;        // 返回输入流对象引用，支持链式输入
}

// +运算 外部定义方法 ;调用时：operator+(p,q) p,q地位一致
// Point operator+ (const Point& p, const Point& q){
//   //Point类型的加法
//   return Point(p[0] + q[0],p[1] + q[1]);
// }

int main() {
  Point p(3.5, 4.5), q(2.0, 3.11);
  cout << p[0] << "," << p[1] << endl; // p.operator[](0)

  Point s = p + q; // 调用operator+函数，返回一个新的Point对象
  // cin >> p;
  cout << p << " " << q;
  cout << s;

  // 修改p的坐标值
  p[0] = 3.14;
  p[1] = 2.67; //
  cout << p;
}

#endif
