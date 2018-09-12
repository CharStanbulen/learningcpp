#include <iostream>
using namespace std;
#define BASIC
//#define CONST

#ifdef BASIC
//define只是在编译的时候替换字符串
//不会分配内存
#define LENGTH 10
#define WIDTH 5
#define NEWLINE '\n'
#endif

int main()
{
#ifdef BASIC
    int area;
    area = LENGTH * WIDTH;
    cout << area;
    cout << NEWLINE;
//定义的宏是可以取消的
#define N 12
#undef N
#ifdef N
    cout << "undef: " << N << endl;
#endif
#define N 18
    cout << "redef: " << N << endl;
#endif
#ifdef CONST
    //const定义的常量不能对其再进行赋值
    //如下使用const关键字错误
    //const double pi;
    //pi = 3.14159265;
    //const关键字声明的变量会分配内存，并且赋予的值不能改变。
    const int LENGTH = 10;
    const int WIDTH = 5;
    const char NEWLINE = '\n';
    int area;
    
    area = LENGTH * WIDTH;
    cout << area;
    cout << NEWLINE;
    return 0;
#endif
    
    return 0;
}
