#include <iostream>
#include <string>
#include <vector>

//#define BASIC
//#define CLASS 
//#define VECTOR 
#define SIZE
using namespace std;
using std::vector;

#ifdef BASIC
template <typename T>
inline T const& Max (T const& a, T const& b)
{
	return a < b ? b : a;
}
#endif

#ifdef CLASS
template <class T>
inline T const& Max (T const& a, T const& b)
{
	return a < b  ? b : a;
}
#endif

int main()
{
#ifdef SIZE
	vector<int> v;
	std::cout << "v.size() == " << v.size() << " v.capacity() = " << v.capacity() << endl;
	//resize会分配真正的内存空间
	//reserve只是修改了capacity的值为预留空间
	//此时若使用[i]访问会出现越界的报错
	v.reserve(10);
	std::cout << "v.size() == " << v.size() << " v.capacity() = " << v.capacity() << endl;
	v.resize(10);
	v.push_back(0);
	std::cout << "v.size() == " << v.size() << " v.capacity() = " << v.capacity() << endl;
#endif
#ifdef VECTOR
	vector<int> vec;
	int i;

	cout << "vector size = " << vec.size() << endl;
	
	for (i = 0; i < 5; i++) {
		//push_back()函数在向量末尾插入值，有必要会扩展向量大小。
		vec.push_back(i);
	}

	//size()函数显示向量大小
	cout << "extended vector size = " << vec.size() << endl;

	for (i = 0; i < 5; i++) {
		cout << "value of vec [" << i << "] = " << vec[i] << endl;
	}

	//使用迭代器iterator访问值
	//begin()函数指向向量的开头的迭代器
	vector<int>::iterator v = vec.begin();
	//end()函数指向向量末尾的迭代器
	while(v != vec.end()) {
		cout << "value of v = " << *v << endl;
		v++;
	}
#endif
#ifdef CLASS
	int i = 39;
	int j = 20;
	cout << "Max(i, j): " << Max(i, j) << endl;

	double f1 = 13.5;
	double f2 = 20.7;
	cout << "Max(f1, f2): "  << Max(f1, f2) << endl;

	string s1 = "Hello";
	string s2 = "World";
	cout << "Max(s1, s2): " << Max(s1, s2) << endl;
#endif

#ifdef BASIC
	int i = 39;
	int j = 20;
	cout << "Max(i, j): " << Max(i, j) << endl;

	double f1 = 13.5;
	double f2 = 20.7;
	cout << "Max(f1, f2): " << Max(f1, f2) << endl;

	string s1 = "Hello";
	string s2 = "World";
	cout << "Max(s1, s2): " << Max(s1, s2) << endl;
#endif

	return 0;
}


