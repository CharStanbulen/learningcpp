#include <iostream>
#include <cstring>
#include <string>

using namespace std;

//#define BASIC
//#define FUNC
//#define STR
//#define STRFUNC
#define GETLINE

int main()
{
#ifdef GETLINE
#define N 100
	char X[N];
	cin.getline(X, N);
	int a = 0, b = 0;
	for (int i = 0; i < N; i++)
	{
		if(X[i] == '#')
			break;
		if (X[i] >= '0' && X[i] <= '9')
			a++;
		if ((X[i] >= 'a' && X[i] <= 'z') || (X[i] >= 'A' && X[i] <= 'Z'))
			b++;
	}
	cout << a << endl << b << endl;
#endif

#ifdef BASIC
	 char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
	 cout << "Greeting message: ";
	 cout << greeting << endl;
#endif

#ifdef FUNC
	char str1[11] = "Hello";
	char str2[11] = "World";
	char str3[11];
	int len;

	strcpy(str3, str1);
	cout << "strcpy(str3, str1) : " << str3 << endl;

	strcat(str1, str2);
	cout << "strcat(str1, str2) : " << str1 << endl;

	len = strlen(str1);
	cout << "strlen(str1) : " << len << endl;
#endif

#ifdef STR
	string str1 = "Hello";
	string str2 = "World";
	string str3;

	int len;

	str3 =  str1 ;
	cout << "str3 : " << str3 << endl;

	str3 = str1 + str2;
	cout << "str1 + str2 : " << str3 << endl;

	len = str3.size();
	cout << "str3.size() : " << len << endl;
#endif

#ifdef STRFUNC
	string http = "www.runoob.com";
	cout << http.length() << endl;
	http.append("/C++");
	cout << http <<endl;

	int pos = http.find("/C++");
	cout << pos << endl;
	http.replace(pos, 4, "");
	cout << http << endl;

	int first = http.find_first_of(".");
	int last = http.find_last_of(".");
	cout << http.substr(first + 1, last - first - 1) << endl;

	cout << "######################" << endl;

	cout << strlen("123") << endl;
	cout << sizeof("123") << endl;
	string s = "123";
	cout << s.size() << endl;
#endif

	 return 0;
}
