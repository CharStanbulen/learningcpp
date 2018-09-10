#include <iostream>
#include <string>
#include <limits>
#include "stdio.h"

using namespace std;

int main ()
{
    cout << "Hello World\n";

    //c++特殊的标识符
    int $8 = 0x99;
    printf("$8%d\n", $8);
    int _2a$ = 0x99;
    printf("_2a$%d\n", _2a$);
    int $a = 0x99;
    printf("$a%d\n", $a);

    cout << "type: \t\t" << "**********size************" << endl;
    cout << "bool: \t\t" << "Byte size: " << sizeof(bool);
    cout << "\tmax value: " << (numeric_limits<bool>::max)();
    cout << "\tmax value: " << (numeric_limits<bool>::min)() << endl;
    cout << "char: \t\t" << "Byte size: " << sizeof(char);
    cout << "\tmax value: " << (numeric_limits<char>::max)();
    cout << "\tmax value: " << (numeric_limits<char>::min)() << endl;
    cout << "signed char: \t\t" << "Byte size: " << sizeof(signed char);
    cout << "\tmax value: " << (numeric_limits<signed char>::max)();
    cout << "\tmax value: " << (numeric_limits<signed char>::min)() << endl;
    cout << "unsigned char: \t\t" << "Byte size: " << sizeof(unsigned char);
    cout << "\tmax value: " << (numeric_limits<unsigned char>::max)();
    cout << "\tmax value: " << (numeric_limits<unsigned char>::min)() << endl;
    cout << "wchar_t: \t\t" << "Byte size: " << sizeof(wchar_t);
    cout << "\tmax value: " << (numeric_limits<wchar_t>::max)();
    cout << "\tmax value: " << (numeric_limits<wchar_t>::min)() << endl; 
    cout << "short: \t\t" << "Byte size: " << sizeof(short);
    cout << "\tmax value: " << (numeric_limits<short>::max)();
    cout << "\tmax value: " << (numeric_limits<short>::min)() << endl; 
    cout << "int: \t\t" << "Byte size: " << sizeof(int);
    cout << "\tmax value: " << (numeric_limits<int>::max)();
    cout << "\tmax value: " << (numeric_limits<int>::min)() << endl; 
    cout << "unsigned: \t\t" << "Byte size: " << sizeof(unsigned);
    cout << "\tmax value: " << (numeric_limits<unsigned>::max)();
    cout << "\tmax value: " << (numeric_limits<unsigned>::min)() << endl; 
    cout << "long: \t\t" << "Byte size: " << sizeof(long);
    cout << "\tmax value: " << (numeric_limits<long>::max)();
    cout << "\tmax value: " << (numeric_limits<long>::min)() << endl; 
    cout << "unsigned long: \t\t" << "Byte size: " << sizeof(unsigned long);
    cout << "\tmax value: " << (numeric_limits<unsigned long>::max)();
    cout << "\tmax value: " << (numeric_limits<unsigned long>::min)() << endl; 
    cout << "double: \t\t" << "Byte size: " << sizeof(double);
    cout << "\tmax value: " << (numeric_limits<double>::max)();
    cout << "\tmax value: " << (numeric_limits<double>::min)() << endl; 
    cout << "long double: \t\t" << "Byte size: " << sizeof(long double);
    cout << "\tmax value: " << (numeric_limits<long double>::max)();
    cout << "\tmax value: " << (numeric_limits<long double>::min)() << endl; 
    cout << "float: \t\t" << "Byte size: " << sizeof(float);
    cout << "\tmax value: " << (numeric_limits<float>::max)();
    cout << "\tmax value: " << (numeric_limits<float>::min)() << endl; 
    cout << "size_t: \t\t" << "Byte size: " << sizeof(size_t);
    cout << "\tmax value: " << (numeric_limits<size_t>::max)();
    cout << "\tmax value: " << (numeric_limits<size_t>::min)() << endl; 
    cout << "string: \t\t" << "Byte size: " << sizeof(string);
    cout << "\tmax value: " << (numeric_limits<string>::max)();
    cout << "\tmax value: " << (numeric_limits<string>::min)() << endl; 
    cout << "type: \t\t" << "**********size************" << endl;
    
#if 0
    cout << "This can not be printed.";
#endif

    return 0;
}
