#include <iostream>
#include <string>
#include <cctype>
#include <math.h>

using namespace std;
//#define BASIC
//#define WHILE
//#define FOR
//#define DOWHILE
//#define NEST
//#define BREAK
//#define CONTINUE
#define GOTO

int main()
{
#ifdef BASIC
    for (;;)
    {
        printf("This loop will run forever.\n");
    }
#endif

#ifdef WHILE
    int a = 10;

    while (a < 20)
    {
        cout << "value of a is: " << a << endl;
        a++;
    }
#endif

#ifdef FOR
    for (int a = 10; a < 20; a = a + 1)
    {
        cout << "value of a is: " << a << endl;
    }
    cout << "####################" << endl;
    //c++11定义的循环方式
    int my_array[5] = {1, 2, 3, 4, 5};
    for (int &x : my_array)
    {
        x *= 2;
        cout << x << endl;
    }
    cout << "####################" << endl;
    //auto 用来自动获取变量类型
    for (auto &x : my_array)
    {
        x *= 2;
        cout << x << endl;
    }
    cout << "####################" << endl;
    string str("some string");
    for (auto &c : str)
    {
        c = toupper(c);
    }
    cout << str << endl;
    //for循环表达式二前后的分号不能省略
    int sum;
    int i = 1;
    cout << "####################" << endl;
    //for的几种不同写法
    for (;i <= 100;)
    {
        sum += i;
        i++;
    }
    cout << "sum: " << sum << endl;
#endif

#ifdef DOWHILE
    int a = 10;
    //使用dowhile循环体至少执行一次
    do
    {
        cout << "value of a is: " << a << endl;
        a = a + 1;
        break;
    } while (a < 20);
#endif

#ifdef NEST
    int i, j;
    for(i = 2; i < 100; i++) {
        for (j = 2; j <= (i / j); j++) {
            if(! (i % j)) {
                break;
            }
        }
        if (j > (i / j)) {
            cout << i << " 是质数\n";
        }
    }
    cout << "###############################" << endl;

    int m, n;
    for (m = 2; m < 100; m++)
    {
        for (n = 2; n <= (double)sqrt((double)m); n++)
        {
            if (!(m%n))
                break;
        }
        if (n > (double)sqrt((double)m))
            cout << m << " 是质数\n";
    }
#endif

#ifdef BREAK
    int a = 10;
    do {
        cout << "value of a is: " << a << endl;
        a = a + 1;
        if (a > 15)
        {
            break;
        }
    } while (a < 20);
#endif

#ifdef CONTINUE
    int a = 10;

    do {
        if (a == 15) {
            a = a + 1;
            continue;
        }
        cout << "value of a is: " << a << endl;
        a = a + 1;
    } while (a < 20);
#endif

#ifdef GOTO
    int a = 10;

LOOP:do
     {
        if (a == 15)
        {
            a = a + 1;
            goto LOOP;
        }
        cout << "value of a is: " << a << endl;
        a = a + 1;
     } while (a < 20);
#endif

    return 0;
}
