#include <iostream>
using namespace std;
//#define BASIC
#define CERR

#ifdef CERR
#define DEBUG
#define MIN(a, b) ((a) < (b) ? a : b)
#define MKSTR(x) #x
#define concat(a, b) a##b
#endif

#ifdef BASIC
#define PI 3.14159
#define MIN(a, b) (a < b ? a : b)
#endif

int main()
{
	cout << "Value of __LINE__: " << __LINE__ << endl;
	cout << "Value of __FILE__: " << __FILE__ << endl;
	cout << "Value of __DATE__: " << __DATE__ << endl;
	cout << "Value of __TIME__: " << __TIME__ << endl;
	
#ifdef CERR
	int xy = 100;
	cout << concat(x, y) << endl;

	cout << MKSTR(HELLO C++) << endl;
	cout << "##################################" << endl;
	int i, j;
	i = 100;
	j = 30;

#ifdef DEBUG
	cerr << "Trace: Inside main function" << endl;
#endif

#if 0
	cout << MKST(HELLO C++) << endl;
#endif

	cout << "The minimum is " << MIN(i, j) << endl;
#ifdef DEBUG
	cerr << "Trace: Coming out of main function" << endl;
#endif
#endif
#ifdef BASIC
	//编译时带-E参数重定向可以看到PI的值已经被替换
	cout << "Value of PI :" << PI << endl;
	int i, j;
	i = 100;
	j = 30;
	cout << "min value is: " << MIN(i, j) << endl;
#endif
	return 0;
}
