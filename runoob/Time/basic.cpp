#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

//#define BASIC
//#define TM
#define FORMAT

using namespace std;
#ifdef FORMAT
string Get_Current_Date()
{
    time_t nowtime;
    nowtime = time(NULL);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&nowtime));
    return tmp;
}
#endif

int main()
{
#ifdef FORMAT
    cout << Get_Current_Date().c_str() << endl;

    getchar();
    return 0;
#endif
#ifdef TM
    time_t now = time(0);

    cout << "seconds have passed after 1970:" << now << endl;

    tm *ltm = localtime(&now);

    cout << "year: " << 1900 + ltm->tm_year << endl;
    cout << "month: " << 1 + ltm->tm_mon << endl;
    cout << "date: " << ltm->tm_mday << endl;
    cout << "time: " << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;
#endif
#ifdef BASIC
    //获取系统当前时间日期
    time_t now = time(0);

    char* dt = ctime(&now);
    
    cout << "local date and time: " << dt << endl;

    //转换时间格式结构
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC date and time: " << dt << endl;
#endif

    return 0;
}
