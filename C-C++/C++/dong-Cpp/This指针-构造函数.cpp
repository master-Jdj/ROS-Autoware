// this指针 ：成员函数实际上隐含一个this指针，指向当前对象 ，" 1、"后为本内容
// 访问权限
#if 0
#include <iostream>
#include <string>
using namespace std;

/* class  和 struct 的区别：
    class默认成员访问权限是private，
    struct默认成员访问权限是public

*/
class student
// struct student

{
  // 成员变量一般放在private里保护起来，成员函数放在public里提供接口
private:
  string name;
  int age;

public:
  void print() // 1、成员函数的本质：普通函数 + 隐含参数this
  { // 1、会将成员函数外化成外部函数，成员函数的调用会将当前对象的地址作为实参传递给外部函数
    cout << this->name << this->age << endl;
    // 1、this-> 在成员函数中可以不写，默认就是当前对象的成员变量
  }
  // 提供接口访问或修改成员变量
  string get_name() { return name; } // 访问接口
  int get_age() { return age; }
  void set_name(string n) { name = n; } // 修改接口
  void set_age(int a) { age = a; }
};
//  1、
// void print(stu *this)  
// {
//     cout << this->name << this->age << endl;
// }

int main() {
  student stu;
  stu.set_name("Lee");
  stu.set_age(20);

  stu.print(); //==> print(&stu);  这里是引用stu
  // 1、 为什么要通过对象stu调用成员函数？因为成员函数需要知道当前对象是谁，
  //  才能访问对象的成员变量，所以成员函数隐含一个this指针，指向当前对象stu的地址。
  cout << stu.get_name() << stu.get_age() << endl;
  return 0;
}

#endif

// 构造函数 ：函数名和类名相同，且无返回类型的函数成员
// 创建对象是首先调用 构造函数，给对象的成员变量进行初始化
/*  构造函数的功能：
    1、可以设置 含参构造函数，通过外部传入的参数来初始化对象的成员变量
    2、支持多个构造函数重载，提供不同的初始化方式
    3、
*/
#if 0
#include <iostream>
#include <string>
using namespace std;

class student {
private:
  string name;
  int age;

public:
  //
  //student() {} // 默认的 构造函数 ，无定义情况下自动生成，无参构造函数；随意初始化
  // 2、根据需要重载多个构造函数{student() ; student(string n, int a)}，提供不同的初始化方式
  student()  //属于默认构造函数
  {
    name = "Lee";
    age = 20;
  }
                              // 不属于默认构造函数，属于含参构造函数
  student(string n, int a)    // 1、含参构造函数，提供外部传入参数来初始化对象的成员变量
  {   
    name = n;
    age = a;
  }
// -------------------------------------------------------------------------------------
  void print() {
    cout << name << " " << age << endl;
  }
};

int main() {
  cout << "请输入学生的姓名和年龄：" << endl;
 
  student stu("Wang" , 19); //在实例类(创建对象)时会首先自动调用 “构造函数”的函数成员，给对象的成员变量进行初始化
  student stu2; //调用默认构造函数，随意初始化
//------------------------------------------------------------------------------------
//数组类型的对象，只能调用默认构造函数，所以必须提供默认构造函数  
  student stus[3];
  
  stu.print();
  stu2.print();
  stus[1].print();
  return 0;
}

#endif