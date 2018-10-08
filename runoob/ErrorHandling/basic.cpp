#include <iostream>
#include <exception>
using namespace std;
//#define BASIC
//#define DEMO1
//#define DEMO2
#define DEMO3

#ifdef BASIC
double division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return (a / b);
}
#endif

#ifdef DEMO1
struct MyException : public exception
{
    const char * what () const throw ()
    {
        return "C++ Exception";
    }
};
#endif

#ifdef DEMO3
class MyException
{
public:
    MyException(const char *message)
        : message_(message)
    {
        cout << "Copy MyException..." << endl;
    }
    virtual ~MyException ()
    {
        cout << "~MyException ..." << endl;
    }

    const char *what() const
    {
        return message_.c_str();
    }
private:
    string message_;
}
class MyExceptionD : public MyException
{
public:
    MyExceptionD(const char *message)
        : MyException(message)
    {
        cout << "Copy MyExceptionD ..." << endl;
    }
    ~MyExceptionD()
    {
        cout << "~MyExceptionD ..." << endl;
    }
}

void fun(int n) throw(int, MyException, MyExceptionD)
{
    if (n == 1)
    {
        throw 1;
    }
    else if (n == 2)
    {
        throw MyException("test Exception");
    }
    else if (n == 3)
    {
        throw MyExceptionD("test ExceptionD");
    }
}

void fun2() throw()
{

}
#endif
int main()
{
#ifdef DEMO3
    try
    {
        fun(2)
    }
    catch (int n)
    {
        cout << "catch int ..." << endl;
        cout << "n=" << n << endl;
    }
    catch (MyException &e)
    {
        cout << "catch MyExceptionD ..." << endl;
        cout << e.what() << endl;
    }
    catch (MyException &e)
    {
        cout << "catch MyException ..." << endl;
        cout << e.what() << endl;
    }
#endif
#ifdef DEMO1
    try
    {
        throw MyException();
    }
    catch (MyException& e)
    {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
    
    }
#endif
#ifdef BASIC
    int x = 50;
    int y = 0;
    double z = 0;

    try {
        z = division(x, y);
        cout << z << endl;
    } catch (const char* msg) {
        cerr << msg << endl;
    }

   return 0;
#endif
}

