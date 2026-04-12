程序流程：{
		源代码

		编译器{g++ clang VS C++_Compiler}
		在线C++编译器：online c++ compiler
		

		目标代码

		链接程序（启动代码）（库代码）

		可执行代码
		}

g++ 编译流程：{
	1.编译源文件，生成二进制的目标文件(.obj )
？十进制文件是哪个？ 可执行文件win上生成.exe ; Linux上生成.out
`$ g++ -c file.cpp   # file.obj ; a.out`
或者
`$ g++ -std=c++17 -c file.cpp -o pro  #file.obj ; pro.out`
	2.链接目标文件，生成可执行文件
`$ g++ file.obj -o file.exe`

}win一步流程：$ g++ file.cpp -o file.exe

编程建议：函数头要明确参数。具体如下{
$:	int main(void)  而不是 main（）
在括号中使用关键字void明确地指出，函数不接受任何参数。在C++（不是C）中，让括号空着与在括号中使用void等效（在C中，让括号空着意味着对是否接受参数保持沉默）。
	}

main（）函数是C++程序的通道口，必须含有。
例外：DLL模块动态库，单片机（依赖于地址）

注释方式：  // （推荐）  /*  */ (不推荐）