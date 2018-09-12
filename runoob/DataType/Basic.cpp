#include <iostream>
using namespace std;
//#define BASIC
#define EXPLICIT

#ifdef EXPLICIT
class Test1
{
public:
    Test1(int n)
    {
        num = n;
    }
private:
    int num;
};

class Test2
{
    public:
        explicit Test2(int n)
        {
            num = n;
        }
    private:
        int num;

};
#endif

int main()
{
#ifdef BASIC
    short int i;
    short unsigned int j;

    j = 50000;

    i = j;
    cout << i << " " << j << endl;
#endif

#ifdef EXPLICIT
    Test1 t1 = 12;
    //Test2 t2 = 12;//编译错误，不能调用显示构造函数
    Test2 t2(12);
#endif
    int x = 10;
    //这里相当于x-- > 0
    while (x --> 0)
    {
        printf("%d ", x);
        printf("\n");
    }
    x = 10;

    //相当于0 < ----x，x每次累减2
    while(0 <---- x)
    {
        printf("%d ", x);
        printf("\n");
    }

    x = 100;
    // x每次累减10
    while(0 <-------------------- x)
    {
        printf("%d ", x);
    }

    return 0;
}
