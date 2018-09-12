#include <iostream>
using namespace std;
//#define BASIC
//#define STATIC
//#define ASSIGNMENT
#define DOMAIN
#ifdef BASIC
//声明了变量
extern int a, b;
extern int c;
extern float f;
// 函数声明
int func();
#endif

#ifdef STATIC
//全局变量
int count1 = 1;
int fun()
{
    //局部static变量，生命周期为整个程序。
    static int count1 = 10;
    return count1--;
}
#endif

#ifdef DOMAIN
int a = 10;
#endif
int main ()
{
#ifdef BASIC
    int a, b;
    int c;
    float f;

    a = 10;
    b = 20;
    c = a + b;

    cout << c << endl;
    
    f = 70.0 / 3.0;
    cout << f << endl;

    //转换长度朝涨肚增加的方向进行
    //长度高的变量转换为长度低的变量精度会降低
    //声明并且定义了变量a1
    int a1 = 1;
    double b1 = 2.5;
    a1 = b1;
    cout << a1 << endl;

    int a2 = 1;
    double b2 = 2.1;
    cout << "a2 + b2 = " << a2 + b2 << endl;
    return func();
#endif
#ifdef ASSIGNMENT
    int *a = NULL;
    if (a = NULL) //赋值语句
    {
        return  false;
    }
    if (NULL = a) //错误，'='的右边不能为变量名
    {
        return false;
    }
    if (a == NULL)//可行，判断指针是否为空
    {
        return false;
    }
    if (NULL == a)
    {
        return false;
    }
#endif

#ifdef STATIC
    cout << "global " << "local static" << endl;
    for(; count1 <= 10; ++count1)
        cout << count1 << "   " << fun() << endl;
#endif


#ifdef DOMAIN
    int a = 20;
    //为变量加上::可以访问全局变量
    cout << ::a << endl;
    cout << a << endl;
#endif
    return 0;
}
#ifdef BASIC

int func()
{
    return 0;
}
#endif
