#include <iostream>
using namespace std;
//#define BASIC
//#define DEFAULT
//#define LAMBDA
//#define LAMBDATHIS
//#define DELIVERVAL
//#define POINTER
#define QUOTE

#ifdef BASIC
//在函数中参数数据类型是必须的
//也可以写成
//int max(int, int);
//函数声明
int max(int num1, int num2);
#endif

#ifdef DEFAULT
int sum(int a, int b = 20)
{
    int result;

    result = a + b;

    return (result);
}
#endif
#ifdef LAMBDATHIS 
class test
{
    public:
        void hello() {
            cout << "test hello!\n";
        };
        void lambda () {
            auto fun = [this] { //捕获class this的指针
                this->hello();
            };
            fun();
        };
};
#endif

#ifdef DELIVERVAL
void swap(int x, int y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;
    cout << "value of a in swap: " << x << endl;
    cout << "value of b in swap: " << y << endl;
    
    return;
}
// 也可以不用临时变量
void swap1(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "value of a in swap: " << a << endl;
    cout << "value of b in swap: " << b << endl;

    return;
}

// 使用异或运算
void swap2(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "value of a in swap: " << a << endl;
    cout << "value of b in swap: " << b << endl;
    return;
}
#endif

#ifdef POINTER
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;

    return;
}
#endif

#ifdef QUOTE
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;

    return;
}
#endif

int main ()
{
#ifdef QUOTE
    
    int a = 100;
    int b = 200;

    cout << "before exchange, value of a: " << a << endl;
    cout << "before exchange, value of b: " << b << endl;

    //引用传值用变量名直接传入
    swap(a, b);

    //传值调用实际上并没有改变传入变量的值
    cout << "after exchange, value of a: " << a << endl;
    cout << "after exchange, value of b: " << b << endl;
    
#endif
#ifdef POINTER
    int a = 100;
    int b = 200;

    cout << "before exchange, value of a: " << a << endl;
    cout << "before exchange, value of b: " << b << endl;

    //指针传递需在变量前加上'&'运算符
    swap(&a, &b);

    //传值调用实际上并没有改变传入变量的值
    cout << "after exchange, value of a: " << a << endl;
    cout << "after exchange, value of b: " << b << endl;
    
#endif
#ifdef DELIVERVAL
    int a = 100;
    int b = 200;

    cout << "before exchange, value of a: " << a << endl;
    cout << "before exchange, value of b: " << b << endl;
   
    swap(a, b);
    swap1(a, b);
    swap2(a, b);

    //传值调用实际上并没有改变传入变量的值
    cout << "after exchange, value of a: " << a << endl;
    cout << "after exchange, value of b: " << b << endl;

#endif
#ifdef LAMBDATHIS
    test t;
    t.lambda();
#endif

#ifdef BASIC
    int a = 100;
    int b = 200;
    int ret;

    ret = max(a, b);

    cout << "Max value is : " << ret << endl;
#endif
#ifdef DEFAULT
    int a = 100;
    int b = 200;
    int result;

    //函数将使用传入的参数b
    result = sum(a, b);
    cout << "Total value is : " << result << endl;

    //未传入参数，函数将使用b的默认值20
    result = sum(a);
    cout << "Total value is :" << result << endl;
#endif
#ifdef LAMBDA
    //匿名函数是在c++中开始采用的，在编译的时候需要加上-std=c++11
    //c++的匿名函数采用闭包的形式，但是和javascript不一样，c++的匿名函数可以传递指针
    auto basicLambda = [] {cout << "Hello, world!" << endl;};
    basicLambda();
    
    auto add = [](int a, int b) -> int {return a + b;};
    
    //若不指定返回的数据类型，lambda会自动推断返回类型
    auto multiply = [](int a, int b) {return a * b;};
    cout << "addition result is " << add(2, 5) << endl;
    cout << "multiply result is " << multiply(2, 5) << endl;
    
    //未指定捕获模式Lambda函数无法使用外部变量
    //如下会引起报错
    //int i = 1024;
    //auto func = [] {cout << i;};
    //func();
    int i = 1024;
    auto func = [=] { // =[] 表明将外部所有的变量拷贝一份到lambda函数内部
        cout << i << endl;
    };
    //引用捕获
    auto func1 = [&] {
        cout << "guild : " << &i << endl;
    };
    func1();

    //复制引用捕获
    int m = 1024, n = 2048;
    cout << "m:" << &m << endl;
    cout << "n:" << &n << endl;

    auto fun2 = [=, &n] {
        //m为调用外部变量，lambda会给一个新的内存地址。
        cout << "m:" << &m << endl;
        //n为拷贝外部变量，lambda函数内和函数外n内存地址是一样的。
        cout << "n:" << &n << endl;
    };
    fun2();

    int k = 1024;
    cout << "outside i value:" << i << " addr:" << &i << endl;
    
    auto fun3 = [i]{
        cout << "inside i value:" << i << " addr:" << &i << endl;
    };
    fun3();

    //在lambda函数中传入的变量是cont类型，需要使用mutable函数。
    //mutable函数取消传入参数的const属性。
    int x = 10;
    //注意：这里a为传入参数，x为捕获的外部变量。
    auto add_x = [x](int a) mutable {x *= 2; return a + x;};

    cout << add_x(10) << endl;
    return 0;
#endif

    return 0;
}

#ifdef BASIC
int max (int num1, int num2)
{
    int result;

    if(num1 > num2)
        result = num1;
    else
        result = num2;
    
    return result;
}
#endif
