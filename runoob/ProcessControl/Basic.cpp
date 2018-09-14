#include <iostream>
using namespace std;
//#define BASIC
//#define TRILAY
//#define ROLAY
//#define IF

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

    return 0;
}
