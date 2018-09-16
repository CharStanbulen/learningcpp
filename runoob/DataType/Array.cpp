#include <iostream>
using namespace std;

#include <iomanip>
//setw格式化在在输出第几个空格后输出
using std::setw;
//#define BASIC
//#define DYADIC
//数组名是一个指向数组中第一个元素的常量指针
//#define POINTER
#define FUNCTION
#ifdef FUNCTION
//数组作为参数传递可以是一个定长或不定长的数组，也可以是一个指针。
double getAverage(int arr[], int size)
{
	int i, sum = 0;
	double avg;

	//指针占用内存大小等于其数据类型占用的内存大小
	cout << "Inside getAverage sizeof(arr) = " << sizeof(arr) << endl;
	for (i = 0; i < size; ++i){
		sum += arr[i];
	}

	//除法在这里做了隐式转换
	avg = double(sum) / size;

	return avg;
}
#endif

int main()
{
#ifdef BASIC
	int n[10];

	for (int i = 0; i < 10; i++)
	{
		n[i] = i + 100;
	}
	cout << "Element" << setw(13) << "Value" << endl;

	for (int j = 0; j < 10; j++)
	{
		cout << setw(7) << j << setw(13) << n[j] << endl;
	}
#endif

#ifdef DYADIC
	int a[5][2] = {{0, 0}, {1, 2}, {2, 4}, {3, 6}, {4, 8}};

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 2; j++)
		{
			cout << "a[" << i << "][" << j << "]: ";
			cout << a[i][j] << endl;
		}
#endif

#ifdef POINTER
	double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
	double *p;

	p = balance;

	cout << "use pointer of array p to get value: " << endl;
	for (int i = 0; i <5; i++)
	{
		cout <<"*(p + " << i << ") : ";
		cout << *(p + i) << endl;
	}
	cout << "use pointer of array balance to get value: " << endl;
	for (int i = 0; i <5; i++)
	{
		cout <<"*(balance + " << i << ") : ";
		cout << *(balance + i) << endl;
	}

	const int MAX = 3;
	char var[MAX] = {'a', 'b', 'c'};
	char *ptr;
	//将字符串数组强制转换为指针
	ptr = var;
	for (int i = 0; i < MAX; i++)
	{
		cout << "Address of var[" << i << "] = ";
		cout << (int *) ptr << endl;

		cout << "Value of var[" << i << "] = ";
		//通过*ptr访问指针的值
		cout << *ptr << endl;

		ptr++;
	}
#endif

#ifdef FUNCTION
	int balance[5] = {1000, 2, 3, 17, 50};
	int *pt1 = balance;
	double avg;

	size_t balance_size = sizeof(balance) / sizeof(int);
	size_t pt1_size = sizeof(pt1);

	cout << "array size: " << balance_size << endl;
	cout << "pt1 size: " << pt1_size << endl;

	avg =getAverage(balance, 5);

	cout << "average value is: " << avg << endl;
#endif

	return 0;
}
