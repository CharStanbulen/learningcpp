#include <iostream>
#include <malloc.h>
using namespace std;
//#define BASIC
//#define DEMO1
//#define DEMO2
//#define DEMO3
//使用new和malloc分配内存的最大不同之处在于
//malloc一个是固定分配内存
//而c++中的new则是在内存区中创建一个对象处理
#define DIFFMEMO

#ifdef DEMO2
class Box
{
	public:
		Box() {
			cout << "use constru func" << endl;
		}
		~Box() {
			cout << "use destroy func" << endl;
		}
};
#endif

#ifdef DIFFMEMO
class TEST
{
private:
	int num1;
	int num2;
public:
	TEST()
	{
		num1 = 10;
		num2 = 20;
	}
	void Print()
	{
		std::cout << num1 << " " << num2 << std::endl;
	}
};
#endif
int main ()
{
#ifdef DIFFMEMO
	//pObj1会将对象强制转换为内存空间，num1和num2会变成垃圾值
	TEST* pObj1 = (TEST *)malloc(sizeof(TEST));
	pObj1->Print();

	TEST* pObj2 = new TEST;
	pObj2->Print();
#endif
#ifdef DEMO2
	Box* myBoxArray = new Box[4];
	delete [] myBoxArray;
#endif
#ifdef BASIC
	double* pvalue = NULL;
	pvalue = new double;

	*pvalue = 29494.99;
	cout << "Value of pvalue : " << *pvalue << endl;

	delete pvalue;
#endif

#ifdef DEMO1
	int **p;
	int i, j;
	p = new int *[4];
	for (i = 0; i < 4; i++) {
		p[i] = new int[8];
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			p[i][j] = j * i;
		}
	}

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			if(j == 0) cout << endl;
			cout << p[i][j] << "\t";
		}
	}
	for (i = 0; i < 4; i++) {
		delete [] p[i];
	}
	delete [] p;
#endif

#ifdef DEMO3
	int i, j, k;
	int ***p;
	p = new int **[2];
	//给二维和三维数组分配内存
	for (i = 0; i < 2; i++)
	{
		p[i] = new int *[3];
		for (j = 0; j < 3; j++)
			p[i][j] = new int[4];
	}

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 4; k++)
			{
				p[i][j][k] = i + j + k;
				cout << p[i][j][k] << " ";
			}
			cout << endl;
		}
	}

	for(i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			delete [] p[i][j];
		}
	}

	for (i = 0; i < 2; i++)
	{
		delete [] p[i];
	}
	delete [] p;
#endif

	return 0;
}
