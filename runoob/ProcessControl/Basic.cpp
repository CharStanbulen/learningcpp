#include <iostream>
#include <string>

using namespace std;
//#define BASIC
//#define TRILAY
//#define ROLAY
//#define IF
//#define SWITCH
//#define COLOR
//switch允许256个嵌套层次
#define SWITCHNEST

#ifdef COLOR
void printcolor(string color, string str)
{
    int clr;
    string head;
    string tail;
    string display;
    if (color == "red") clr = 1;
    if (color == "green") clr = 2;
    switch (clr) {
        case 1: {
            head = "\033[31m";
            tail = "\033[0m";
            display = head + str + tail;
            break;
        }
        case 2: {
            head = "\033[32m";
            tail = "\033[0m";
            display = head + str + tail;
            break;
        }
        default: {
            display = str;
            break;
        }
    }
    cout << display << endl;
}
#endif

int main () {
#ifdef BASIC
    int a, b;
    cout << "intput two number: ";
    cin >> a >> b;
    a > b ? cout << a << "gt" << b << endl:cout << b << "gt" << a << endl;
#endif
#ifdef TRILAY
    int a,b,c,d,max;
    cout << "pls input three numbers:";
    cin >> a >> b >> c;
    max = (d=a>=b?a:b)>=c?d:c;
    cout<<"max value is: "<<max<<endl;
#endif
#ifdef ROLAY
    int a[5], max;
    cout << "input four number: ";
    cin >> a[1] >> a[2] >> a[3] >> a[4];
    max = a[a[a[a[1] > a[2] ? 1 : 2] > a[a[3] > a[4] ? 3 : 4]] ? a[1] > a[2] ? 1 : 2 : a[3] > a[4] ? 3 : 4];
    cout << "max value is: " << max << endl;
#endif

#ifdef IF
    int a = 10;
    if (a < 20){
        cout << "a lt 20" << endl;
    }
    cout << "value of a is: " << a << endl;
#endif

#ifdef SWITCH
    char grade = 'D';

    switch(grade)
    {
        case 'A':
            cout << "great!" << endl;
            break;
        case 'B':
        case 'C':
            cout << "nice!" << endl;
            break;
        case 'D':
            cout << "pass!" << endl;
            break;
        case 'F':
            cout << "pls try again!" << endl;
            break;
        default:
            cout << "unactive score!" << endl;
    }
    cout << "your score is " << grade << endl;
#endif
#ifdef COLOR
    printcolor("red", "helloworld!\n");
    printcolor("green", "hellworld\n");
#endif

#ifdef SWITCHNEST
    int a = 100;
    int b = 200;
    
    switch(a) {
        case 100:
              cout << "This is one part of switch outside." << endl;
            switch (b) {
                case 200:
                    cout << "This is one part of switch internel" << endl;
            }
    }
    cout << "value of a is " << a << endl;
    cout << "value of b is " << b << endl;
#endif

    return 0;
}
