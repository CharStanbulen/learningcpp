#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//#define BASIC
//#define OPR
//#define ARRPTR
//#define PARAM
//#define RE
#define PPTR

#ifdef ARRPTR
void pointerArray4Char();
const int MAX2 = 3;
void pointerArray4Char(){
	const char *names[MAX2] = {
		"sun", "bin", "sunbin"
	};

	for (int i = 0; i < MAX2; i++)
	{
		cout << "Value of name[" << i << "]=";
		cout << names[i] << endl;
		// name是数组指针，这里用*取到的是值是指针地址
		cout << "Value of *name[" << i << "]=";
		cout << *names[i] << endl;
		//name[i]本身是一个指向数组第一个元素的指针。
		cout << "Value of *(name[" << i << "] + 1)=";
		cout << *(names[i] + 1) << endl;
		//获取ascii码的值
		cout << "Value of *name[" << i << "]+1=";
		cout << *names[i] + 1 << endl;
	}
}
#endif

#ifdef BASIC
int a(int b)
{
	cout << b << endl;
	return ++b;
}
#endif

#ifdef PARAM
void getSecond(unsigned long *par);
void getSecond(unsigned long *par)
{
	cout << "Value of *par=" << *par << endl;
	cout << "Value of par=" << par << endl;
	cout << "Value of &par=" << &par << endl;

	*par = time(NULL);
	return;
}

double getAverage(int *arr, int size)
{
	int i, sum = 0;
	double avg;

	for (i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	avg = double(sum) / size;

	return avg;
}
#endif

#ifdef RE
//c++不支持在函数外返回局部变量的地址，除非定义局部变量为static
int *getRandom()
{
	static int r[10];
	srand((unsigned)time(NULL));
	for(int i = 0; i < 10; ++i)
	{
		r[i] = rand();
		cout << r[i] << endl;
	}

	return r;
}
#endif

int main ()
{
#ifdef PPTR
	//多级指针
	int var;
	int *ptr;
	//指向指针的指针地址
	int **pptr;

	var = 3000;
	ptr = &var;
	pptr = &ptr;
	
	cout << "value of var: " << var << endl;
	cout << "value of *ptr: " << *ptr << endl;
	cout << "value of **pptr: " << **pptr << endl;
#endif
#ifdef RE
	int *p;
	
	p = getRandom();
	for (int i = 0; i < 10; i++)
	{
		cout << "*(p + " << i << ") : ";
		cout << *(p + i) <<  endl;
	}
#endif
#ifdef PARAM
	unsigned long sec;
	cout << "Value of sec = :" << sec << endl;
	cout << "Value of &sec = :" << &sec << endl;

	getSecond(&sec);

	cout << "Number of seconds : " << sec << endl;
	
	cout << "###############################" << endl;

	int balance[5] = {1000, 2, 3, 17, 50};
	double avg;

	avg = getAverage(balance, 5);
	cout << "Average value is: "	<< avg << endl;
#endif

#ifdef ARRPTR
	const int MAX = 3;
	int var[MAX] = {10, 100, 200};
	int *ptr[MAX];

	for (int i = 0; i < MAX; i++)
	{
		ptr[i] = &var[i];//赋值为整数地址
	}
	for (int i = 0; i < MAX; i++)
	{
		cout << "Value of var[" << i << "]=";
		cout << *ptr[i] << endl;
	}

	cout << "###############################" << endl;
	const int MAX1 = 4;
	const char *names[MAX1] = {
		"Zara Ali",
		"Hina Ali",
		"Nuha Ali",
		"Sara Ali",
	};
	for (int i = 0; i < MAX; i++)
	{
		cout << "Value of names[" << i << "]=";
		cout << names[i] << endl;
	}
	//以下三种类型的指针需要严格区分
	//指针数组
	//int *ptr[3]
	//一个数组元素的指针，运算优先级[] > () > *
	//int *(ptr[3])
	//数组指针
	//int (*ptr)[3]
	
	cout << "###############################" << endl;
	pointerArray4Char();
#endif

#ifdef BASIC
	int var1;
	char  var2[10];

	cout << "address of var1: ";
	cout << &var1 << endl;

	cout << "address of var2: ";
	cout << &var2 << endl;

	cout << "###############################" << endl;

	int var = 20;
	int *ip;

	ip = &var;

	cout << "value of variable var: ";
	cout << var << endl;
	
	cout << "Value of variable ip: ";
	cout << ip << endl;

	cout << "value of *ip: ";
	cout << *ip << endl;

	cout << "###############################" << endl;
	
	//创建函数指针
	int(*p)(int);
	p=a;
	//调用指针函数
	int pVal = (*p)(5);
	cout << "value of pVal is: " << pVal <<endl;
	cout << "###############################" << endl;
	//良好的编程习惯，初始化指针
	int *ptr = NULL;
	cout << "value of ptr is " << ptr;
#endif

#ifdef OPR
	const int MAX = 3;
	int var[MAX] = {10, 100, 200};
	int *ptr;

	ptr = var;
	for (int i = 0; i < MAX; i++)
	{
		cout << "Address of var [" << i << "] = ";
		cout << ptr << endl;
	
		cout << "Value of var[" << i << "] = ";
		cout << *ptr << endl;

		ptr++;
	}

	cout << "###############################" << endl;
	int var1[MAX] = {10, 100, 200};
	int *ptr1;

	ptr1 = &var1[MAX - 1];
	for (int i = MAX; i > 0; i--)
	{
		cout << "Address of var[" << i < "]=";
		cout << ptr1 << endl;

		cout << "Value of var[" << i << "]=";
		cout << *ptr1 << endl;

		ptr--;
	}

	cout << "###############################" << endl;
	int var2[MAX] = {10, 100, 200};
	int *ptr2;

	ptr2 = var2;
	int i = 0;
	while (ptr <= &var[MAX - 1])
	{
		cout << "Address of var[" << i << "]=";
		cout << ptr << endl;

		cout << "Value of var[" << i << "]=";
		cout << *ptr << endl;

		ptr++;
		i++;
	}
#endif

	return 0;
}
