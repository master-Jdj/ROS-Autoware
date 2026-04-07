//复习--条件编译" # "--预处理器处理
/*
#开头的内容，是预处理器处理的内容，即满足某个条件才会被编译器编译，
否则就会被预处理器直接忽略掉，不会被编译器编译。

条件编译的指令的闭环结构：（以#if为例）
#if 
···
#endif

常用的条件编译指令：
{
    #if 条件表达式   
        若条件满足，则执行 ···   
    #endif
}**********************
{
    #ifdef XXX      
        若定义了XXX这个“宏”，则执行条件编译的代码
    #endif
}***********************
{   //" ifndef " 换成其他条件编译指令同样适用
    #ifndef XXX     
        若没有定义XXX这个“宏”，则执行条件编译的代码
    #else
        若定义了XXX这个“宏”，则执行条件编译的代码
    #endif
}************************
{   // 多条件编译 
    #if 条件表达式1
        ···
    #elif 条件表达式2
        ···
    #endif        
}

*/
//条件编译，为one==1则编译,0则不编译
#if 0
#include <cstdio>    //标准输入输出库
#include <cmath>
#include <cstring>   //字符串处理库

int main()
{
    printf("hello world\n");
    double x =3.14;  
    //%lf输出double类型的数据，%f输出float类型数据
    printf("%lf %lf\n", sqrt(x), sin(x));  //cmath定义了函数
    //下面有关字符串的函数，定义在cstring头文件中
    //s[]字符串空间至少六个字符，不足补\0
    char s[10] = "hello";  
    puts(s);  //puts函数可以输出字符串，并且自动换行

    //char s2[2];  //s2[]是非法的，空间2字符不足6字符
    char s2[16];
    strcpy(s2, s);  //strcpy函数可以将字符串s复制到s2中或"str"
    puts(s2);
    strcat(s2, " world");  //strcat函数可以将字符串" world"连接到s2的末尾

    //计算字符串长度 strlen()   %d输出整数
    printf("%d %d\n",strlen(s), strlen(s2));
    return 0;
}
#endif

#if 1     //改为有效代码
#include <cstdio>
#include <cstring>
#include <malloc.h>    //特殊的未变成cXXX形式，保留原C语言库的头文件名

int main()
{

#if 0   //无效代码,else采用动态分配的字符串,需要头文件<malloc.h>
  
    char s[10];  
    strcpy(s, "hello");  
    puts(s);
#else
    //采用动态分配的字符串，必须使用指针变量来接收返回的地址
    char *s = (char*)malloc(12 * sizeof(char));  //动态分配字符串空间，12个字符
    strcpy(s, "hello world");
    puts(s);
    free(s);  //释放动态分配的字符串空间
#endif

    return 0;
}

#endif