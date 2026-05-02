// 类模板 用户自定义的类型模板
// 1、模拟vector类模板

#include <iostream>
#include <string> // string类
// #include <vector>
using namespace std;

class student {
  string name;
  double score;

public:
  student(string n = "?", double s = 0) : name(n), score(s) {}
  friend ostream &operator<<(ostream &o, student s);
};
ostream &operator<<(ostream &o, student s) {
  cout << s.name << ":" << s.score << endl;
  return o;
}
// 方法二，定义类模板(类似函数模板)
// 1、 自定义vector类模板
template <typename T> class Vector {
  //
  T *data; // 存储动态数组元素的指针，方法2
  // int *data;    // 存储动态数组元素的指针，方法1
  int capacity; // 当前分配的内存容量
  int n;

  // 方法1中 T = int
public:
  // 构造函数，默认容量为5
  Vector(int cap = 5) {
    data = new T[cap];
    if (data == 0) { // 申请内存失败，初始化为空
      cap = 0;
      n = 0;
      return;
    }
    capacity = cap; //
    n = 0;
  }

  void push_back(T e) {
    if (n == capacity) {
      cout << "增加容量！\n";
      T *p = new T[2 * capacity];
      if (p) {
        for (int i = 0; i < n; i++)
          p[i] = data[i];
        delete[] data;
        data = p;
        capacity *= 2;
      } else {
        return;
      }
    }
    data[n] = e;
    n++;
  }
  T operator[](int i) const {
    if (i < 0 || i >= n)
      throw "下标非法！";
    return data[i];
  }
  // int &operator[](int i) { return 0; }
  int size() { return n; }
};

int main() {
#if 0 // 课程前部分 int string
#if 1 // 方法1 int型
  Vector<int> v; // 内置类型创建动态数组v

  v.push_back(8);
  // v.push_back("hsoo");  //错误，--方法1--
  //   v是一个存储int类型元素的动态数组 v.push_back(5);
  v.push_back(4);
  v.push_back(7);
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << '\t';
  cout << endl;

  v.push_back(8);
  v.push_back(5);
  v.push_back(3);

  for (int i = 0; i < v.size(); i++)
    cout << v[i] << '\t';
  cout << endl;

#else
  // vector<int> v;   // 内置类型创建动态数组v
  Vector<string> v; // 类模板实例化产生一个类Vector，创建动态数组v
                    //   v.push_back(13);    //方法1
                    //   v.push_back(0);
                    //   // v.push_back("hsoo");  //错误，--方法1--
  //   v是一个存储int类型元素的动态数组 v.push_back(5);
  v.push_back("hello");
  v.push_back("world");
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << '\t';
  cout << endl;

  v.push_back("7987");
  v.push_back("abc");

  for (int i = 0; i < v.size(); i++)
    cout << v[i] << '\t';
  cout << endl;
#endif

#else // 课程结尾

  Vector<student> v;
  v.push_back(student("张三", 89.5));
  v.push_back(student("李四", 92.0));
  for (int i = 0; i < v.size(); i++)
    cout << v[i];
  cout << endl;

#endif
}