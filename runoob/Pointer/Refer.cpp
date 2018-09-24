#include <iostream>
#define BASIC

using namespace std;

//不存在空引用，引用必须偶要有一块合法的内存
//一旦引用被初始化一个对象就不能指向另外一个对象，但指针可以任何时候指向另一个对象
//指针可以在任何时候被初始化，但是引用在创建时就必须被初始化。

int main()
{
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
