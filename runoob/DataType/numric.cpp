#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>

using namespace std;
//#define BASIC
//#define OPRATE
#define RANDOM
#ifdef RANDOM
#define random(x)(rand() % x)
#endif

int main()
{
#ifdef BASIC
	short s;
	int i;
	long l;
	float f;
	double d;

	s = 10;
	i = 1000;
	l = 1000000;
	f = 230.37;
	d = 30949.374;

	cout << "short s :" << s << endl;
	cout << "int 	 i :" << i << endl;
	cout << "long  l :" << l << endl;
	cout << "float f :" << f << endl;
	cout << "double d :" << d << endl;
#endif

#ifdef OPRATE
	short s;
	int i;
	long l;
	float f;
	double d;

	s = 10;
	i = -1000;
	l = 1000000;
	f = 230.37;
	d = 30949.374;

	cout << "sin(d):" << sin(d) << endl;
	cout << "abs(i):" << abs(i) << endl;
	cout << "floor(d)" << floor(d) << endl;
	cout << "sqrt(f):" << sqrt(f) << endl;
	cout << "pow(d, 2):" << pow(d, 2) << endl;
#endif

#ifdef RANDOM
	int i, j;
	srand((unsigned)time(NULL));

	for (i = 0; i < 10; i++)
	{
		j = rand();
		cout << "random num: " << j << endl;
	}
#define MAX 10
	int number[MAX] = {0};
	srand((unsigned) time(NULL));
	for (i = 0; i < MAX; i++)
	{
		//生成100以内的随机数
		//产生的随机数至少两位32767
		number[i] = rand() % 100;
		printf("%d ", number[i]);
	}
	printf("\n");

	srand((unsigned) time(NULL));
	//此处调用定义的宏函数
	srand((int)time(0));
	for (i = 0; i < 10; i++) {
		cout << random(100) << endl;
	};
#endif

	return 0;
}
