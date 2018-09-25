#include <iostream>
#include <string>

using namespace std;

//#define BASIC
//#define MEMBER
//#define PROTECT
//#define CONSTRU
//#define CONSTRU_PARAM
//#define DESCTRUCTOR
#define DEMO1

#ifdef BASIC
class Box
{
    public:
        double length;
        double breadth;
        double height;
};
#endif

#ifdef MEMBER
class Box
{
    public:
        double length;
        double breadth;
        double height;

        double getVolume(void);
        void setLength(double len);
        void setBreadth(double bre);
        void setHeight(double hei);
};

double Box::getVolume(void)
{
    return length * breadth * height;
}

void Box::setLength(double len)
{
    length = len;
}

void Box::setBreadth(double bre)
{
    breadth = bre;
}

void Box::setHeight(double hei)
{
    height = hei;
}

#endif

#ifdef PROTECT
//protect和private相似，但是可以被派生的子类访问
class Box
{
    protected:
        double width;
};

class SmallBox:Box
{
    public:
        void setSmallWidth(double wid);
        double getSmallWidth(void);
};

double SmallBox::getSmallWidth(void)
{
    return width;
}

void SmallBox::setSmallWidth(double wid)
{
    width = wid;
}
#endif

#ifdef CONSTRU
class Line
{
    public:
        void setLength (double len);
        double getLength(void);
        Line(); //这是构造函数
    private:
        double length;
};
Line::Line(void)
{
    cout << "Object is being created" << endl;
}

void Line::setLength(double len)
{
    length = len;
}

double Line::getLength(void)
{
    return length;
}
#endif

#ifdef CONSTRU_PARAM
class Line
{
    public:
        void setLength(double len);
        double getLength(void);
        Line(double len);

    private:
        double length;
};

Line::Line(double len)
{
    cout << "Object is being created, length = " << len << endl;
    length = len;
}

void Line::setLength(double len)
{
    length = len;
}

double Line::getLength(void)
{
    return length;
}
#endif

#ifdef DESCTRUCTOR
class Line
{
    public:
        void setLength(double len);
        double getLength(void);
        Line();
        ~Line();
    private:
        double length;
};

Line::Line(void)
{
    cout << "Object is being created" << endl;
}
Line::~Line(void)
{
    cout << "Object is being deleted" << endl;
}
void Line::setLength(double len)
{
    length = len;
}
double Line::getLength(void)
{
    return length;
}
#endif

#ifdef DEMO1
class Student
{
    public:
        string name;
        string number;
        char X;
        int year;
        Student(string, string, char, int);
        void xianshi(void);
};

Student::Student(string N, string n, char x, int y)
{
    name = N;
    number = n;
    X = x;
    year = y;
}

void Student::xianshi()
{
    cout << name << endl;
    cout << number << endl;
    cout << X << endl;
    cout << year << endl;
}
#endif

int main()
{
#ifdef DEMO1
    cout << "input name: ";
    string N;
    cin >> N;
    cout << "input no: ";
    string n;
    cin >> n;
    cout << "input sex (M or W) :";
    char x;
    cin >> x;
    cout << "input age: ";
    int y;
    cin >> y;
    
    Student S(N, n, x, y);
    S.xianshi();
#endif
#ifdef DESCTRUCTOR
//析构函数当对象被销毁释放时执行
    Line line;
    
    line.setLength(6.0);
    cout << "Length of line : " << line.getLength() << endl;
#endif

#ifdef CONSTRU_PARAM
    //给构造函数传入参数
    Line line(10.0);
    cout << "Length of line : " << line.getLength() << endl;
    line.setLength(6.0);
    cout << "Length of line : " << line.getLength() << endl;
#endif
#ifdef CONSTRU
    Line line;
    
    line.setLength(6.0);
    cout << "Length of line : " << line.getLength() << endl;
#endif
#ifdef PROTECT
    SmallBox box;

    box.setSmallWidth(5.0);
    cout << "Width of box : " << box.getSmallWidth() << endl;
#endif
#ifdef MEMBER
    Box Box1;
    Box Box2;
    double volume = 0.0;

    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);

    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);

    cout << "volume of Box1: " << Box1.getVolume() << endl;
    cout << "volume of Box1: " << Box2.getVolume() << endl;

#endif

#ifdef BASIC
    Box Box1;
    Box Box2;
    double volume = 0.0;

    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;
    
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth = 13.0;

    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "volume of Box1: " << volume << endl;
    
    volume = Box2.height * Box2.length * Box2.breadth;
    cout << "volume of Box2: " << volume << endl;
#endif

    return 0;
}
