// <iostream> C++的标准输入输出流头文件
/*
C++将输入/输出看作字符流的形式，输入流和输出流分别对应于输入设备和输出设备

cout 是标准名字空间std中的一个输出流对象，代表控制台窗口
{
cout (对象)，endl (std)换行符 使用必须加上名字空间限定符std::
<< 运算符，(输出流对象)O << (数据)x 表示将数据x输出到输出流对象O中
如： std::cout << "Hello World" << std::endl;
}
-------------------------------------
cin 是标准名字空间std中的一个输入流对象，代表键盘输入
{
>> 运算符，(输入流对象)I >> (数据)x 输入数据x到输入流对象I中
$ std::cin >> x;  //从键盘输入数据x
}
-------------------------------------
名字空间namespace 是C++引入的一个重要概念，主要用于解决命名冲突问题
为便于使用 std 或 其他名字空间，可添加： 
{
using namespace std;   //使用std名字空间中的所有成员
using std::cout;     //仅cout使用std名字空间中的对象
:::::
}
*/

#if 0    //置1 名字空间实验
#include <iostream>  //i输入，o输出，stream流
#if 0   //测试 名字空间，1：不加名字空间限定符，0：加名字空间限定符
//未使用名字空间限定符，编译器无法识别cout和endl
int main()
{
    cout << "hello";
    return 0;
}
#else 
//使用了名字空间限定符，编译器可以识别cout和endl
using std::cout;
using std::cin;
int main(){
    int x;
    cout << "必须采用名字空间！" << std::endl;
    cout << "全局或局部使用名字空间符std:: ，均可" << std::endl;
    cout << "输入 y ，返回："; 
    cin >> x;
    return 0;
}
#endif
//实验1结束
#endif
/*-----------------------------------------------------------*/
#if 1  //实验2，文件输出输入流
#include <fstream>  //文件输入输出流头文件
#include <string>   //字符串处理头文件,C++数据类型
#include <iostream>

using std::ofstream;  //输出文件流
using std::ifstream;  //输入文件流

#if 1
int main()
{
    ofstream oF("test.txt");  //创建一个输出文件流对象oF，并打开文件test.txt
    oF << 3.14159 << " " << "hello world\n";  //将数据写入文件
    oF.close();  //关闭文件流对象oF
    ifstream iF("test.txt");  //创建一个输入文件流对象iF，并打开文件test.txt
    double d;
    std::string s;
    iF >> d >> s;  //从文件中读取数据到变量d和s中
    std::cout << d << " " << s << std::endl;  //输出读取的数据
    return 0;
}

#endif

#endif