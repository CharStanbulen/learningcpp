#include <iostream>
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
    
    cout << "type: \t\t" << "**********size************" << endl;
    
#if 0
    cout << "This can not be printed.";
#endif

    return 0;
}
