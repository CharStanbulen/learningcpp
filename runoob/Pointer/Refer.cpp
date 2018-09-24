#include <iostream>
//#define BASIC
//#define PARAM
//#define RETURN
#define EXAMPLE

using namespace std;

//不存在空引用，引用必须偶要有一块合法的内存
//一旦引用被初始化一个对象就不能指向另外一个对象，但指针可以任何时候指向另一个对象
//指针可以在任何时候被初始化，但是引用在创建时就必须被初始化。

#ifdef PARAM
void swap(int& x, int& y)
{
    int temp;

    temp = x;
    x = y;
    y = temp;

    return;
}
#endif

#ifdef RETURN
double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
//返回一个隐式指针
double& setValues(int i)
{
    return vals[i];
}
#endif

#ifdef EXAMPLE
int func(int &x)
{
    x = 3;
    return 0;
}
#endif
int main()
{
#ifdef EXAMPLE
    int a = 1;
    func(a);
    cout << "value of a: " << a << endl;
    cout << "#########################" << endl;
    
    int rats = 100;
    int &rodent = rats;
    
    cout << "rats = " << rats << ", rosent = " << rodent << endl;
    cout << "rats address = " << &rats << endl;
    cout << "rosent address = " << &rodent << endl;

    int bunnies = 50;
    rodent = bunnies;
    cout << "rats = " << rats << ", rosent = " << rodent << ", bussiness = " << bunnies << endl;
    cout << "rats address = " << &rats << endl;
    cout << "rosent address = " << &rodent << endl;
    cout << "bunniess address = " << &bunnies << endl;
    
#endif
#ifdef EXAMPLE

#endif
#ifdef RETURN
    cout << "berfore change:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vals[" << i << "]=";
        cout << vals[i] << endl;
    }

    //为返回的指针赋值
    setValues(1) = 20.23;
    setValues(3) = 70.8;

    cout << "after change:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "vals[" << i << "]=";
        cout << vals[i] << endl;
    }
#endif
#ifdef PARAM
    int a = 100;
    int b = 200;

    cout << "a before exchange: " << a << endl;
    cout << "b before exchange: " << b << endl;

    swap(a, b);

    cout << "a after exchange: " << a << endl;
    cout << "b after exchange: " << b << endl;
#endif

#ifdef BASIC
	int i;
	double d;

	int& r = i;
	double& s = d;

	i = 5;
	cout << "Value of i: " << i << endl;
	cout << "Value of i reference" << r << endl;

	d = 11.7;
	cout << "Value of d: " << d << endl;
	cout << "Value of d reference: " << s << endl;
#endif

	return 0;
}
