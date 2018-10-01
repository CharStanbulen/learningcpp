#include <iostream>

using namespace std;

//#define BASIC
//如下三种情况会调用拷贝函数
//1、一个对象以值传递的方式传入函数体
//2、一个对象以值传递的方式从函数返回
//3、一个对象通过另一个对象初始化
//#define DEMO1
//#define FRIEND
//#define INLINE
//内联函数不允许使用循环和开关语句
#define THIS

#ifdef BASIC
class Line
{
    public:
        int getLength(void);
        Line(int len);//构造函数
        Line(const Line &obj); //拷贝构造函数
        ~Line();//析构函数

    private:
        int *ptr;
};

Line::Line(int len)
{
    cout << "use constru to alloc memo." << endl;
    //为指针分配内存
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "use copy constru to alloc memo." << endl;
    ptr = new int;
    *ptr = *obj.ptr;
}

Line::~Line(void)
{
    cout << "release memo." << endl;
    delete ptr;
}

int Line::getLength(void)
{
    return *ptr;
}

void display(Line obj)
{
    cout << "line size : " << obj.getLength() << endl;
}

#endif

#ifdef DEMO1
class CExample
{
    private:
        int a;
    public:
        CExample(int b)
        {
            a = b;
            cout << "creat: " << a << endl;
        }
        CExample(const CExample& C)
        {
            a = C.a;
            cout << "copy" << endl;
        }
        ~CExample()
        {
            cout << "delete: " << a << endl;
        }

        void show()
        {
            cout << a << endl;
        }
};

void g_Fun(CExample C)
{
    cout << "test" << endl;
}
#endif

#ifdef FRIEND
class Box
{
    double width;
    public:
        friend void printWidth(Box box);
        void setWidth(double wid);
};

void Box::setWidth(double wid)
{
    width = wid;
}

void printWidth(Box box)
{
    cout << "Width of box : " << box.width << endl;
}
#endif
#ifdef INLINE
inline int Max(int x, int y)
{
    return (x > y) ? x : y;
}
#endif
#ifdef THIS
class Box
{
    public:
        Box(double l=2.0, double b=2.0, double h=2.0)
        {
            cout << "Constructor called." << endl;
            length = l;
            breadth = b;
            height = h;
        }
        double Volume()
        {
            return length * breadth * height;
        }
        int compare(Box box)
        {
            return this->Volume() > box.Volume();
        }
    private:
        double length;
        double breadth;
        double height;
};
#endif
int main ()
{
#ifdef THIS
    Box Box1(3.3, 1.2, 1.5);
    Box Box2(8.5, 6.0, 2.0);

    if(Box1.compare(Box2))
    {
        cout << "Box2 is  smalled than Box1" << endl;
    }
    else
    {
        cout << "Box2 is equal to or larger than Box1" << endl;
    }
#endif
#ifdef INLINE
    cout << "Max (20,10): " << Max(20, 10) << endl;
    cout << "Max (0,200): " << Max(0, 200) << endl;
    cout << "Max (100,1010): " << Max(100, 1010) << endl;
#endif
    
#ifdef FRIEND
    Box box;
    box.setWidth(10);
    printWidth(box);
#endif
#ifdef DEMO1
    CExample test(1);
    g_Fun(test);
#endif
#ifdef BASIC
    Line line1(10);
   
    Line line2 = line1;//调用拷贝函数，为指针ptr*分配内存
    display(line1);//调用拷贝函数，为指针ptr*分配内存，并释放拷贝函数内存。
    display(line2);//调用拷贝函数，为指针ptr*分配内存，并释放拷贝函数内存。
    //释放Line1, Line2内存。
    return 0;
#endif
}
