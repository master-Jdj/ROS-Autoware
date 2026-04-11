//介绍用户定义类型string和vector

//string类，表示的是符串
/*
string s = "Hello", s2("world"), s3(s);  //string类的构造函数
成员访问运算符 " . "，访问string类的成员
如：s.size()    
   s.substr(0, 5)   //返回s中从0到5的字符串
   s.find("lo")    //返回s中第一次出现"lo"的位置
   s.insert(5, " ")  //在s的第5个位置插入一个空格
   s.erase(5, 1)    //删除s中从第5个位置
    
*/

#if 0  //example1
#include <iostream>
using namespace std;

int main()
{
    string s = "Hello", s2("world");
    //"."访问string类的成员
    cout << s.size() << endl;  //输出s的长度
    string s3 = s.substr(1, 3);  //返回s中从1到3的字符串
    cout << s3 << endl;
    string s4 = s + " " + s2;  //字符串连接
    cout << s4 << endl;
    //return 0;

    s4[0] = 'H';  //修改s4的第一个字符
    s4[6] = 'X';  //修改s4的第七个字符 X
    cout << s4 << endl;

    int pos = s4.find("orl");  //s.find返回s4中第一次出现"orl"的位置
    cout << pos << endl; // 7

    s4.insert(3, "ABCED");  //在s4的第3个位置插入字符串"ABCDE"
    //采用循环访问s的每个字符
    for (int i = 0; i < s4.size(); i++)    
        cout << s4[i] << " ";
    cout << "\n";

}
#endif

/*-----------------------------------------------------------------------------*/
//内在数组（静态数组）arr[] 和动态数组（vector）
#if 0   //静态数组示例
#include <iostream>
using namespace std;
//静态数组初始化后大小不可改变，访问越界会导致未定义行为，如下的arr[]数组大小为5
int main()
{
    int arr[] = {1, 2, 3, 4, 5};  //可根据初始化列表自动推断数组大小
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
#endif

//vector类（模板），表示的是动态数组，也称向量
//vector类模板，可以实例化产生一个类，如vector<int>表示一个存储int类型元素的动态数组（向量）
/*
    v.push_back(x)  //在v的结尾处添加一个元素x
    v.pop_back()    //删除v的结尾处的元素
    v.resize(n)     //调整v的大小为n，删除多余元素 或 补0
    
*/
#if 0   //动态数组示例
#include <iostream>
#include <vector>    //vector类模板头文件
using namespace std;
int main()
{
    vector<int> v = {7, 4, 3, 9};  //创建动态数组v
    v.push_back(13);  //数组结尾处添加 元素1   
    v.push_back(0);
    //成员函数size() 、 下标运算[]
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\t';
    cout << "\n";
    v.pop_back();  //删除数组结尾处的元素
    cout << v[v.size() - 1] << "\n";  //访问数组最后一个元素
    v.resize(2);  //调整v的大小为2，删除多余元素


}

#endif
