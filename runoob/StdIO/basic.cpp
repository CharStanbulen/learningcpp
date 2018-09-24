#include <iostream>

using namespace std;

#define BASIC

int main()
{
#ifdef BASIC
    char str[] = "Hello C++";
    //标准输出流
    cout << "Value of str is : " << str << endl;

    char name[50];
    cout << "please enter your name: ";
    //标准输入流
    cin >> name;
    cout << "Your name is: " << name << endl;

    //错误输出，非缓冲
    char strerr[] = "Unable to read....";

    cerr << "Error message : " << strerr << endl;

    //标准日志输出，会刷入缓冲区。
    char strlog[] = "strlog unable to read....";
    
    clog << "Error message : " << strlog << endl;
#endif

    return 0;
}
