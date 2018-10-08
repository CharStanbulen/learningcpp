#include <iostream>
using namespace std;
//#define BASIC
#define VAR

#ifdef BASIC
class Shape
{
    public:
        void setWidth(int w)
        {
            width = w;
        }
        void setHeight(int h)
        {
            height = h;
        }
    protected:
        int width;
        int height;
};

class Rectangle: public Shape
{
    public:
        int getArea()
        {
            return (width * height);
        }
};
#endif
#ifdef VAR
class Shape {
    protected:
        int width, height;
    public:
        Shape(int a = 0, int b = 0)
        {
            width = a;
            height = b;
        }
        virtual int area()
        {
            cout << "Parent class area : " << endl;
            return 0;
        }
};
//Rectangle和Triangle是Shape派生的两个类
class Rectangle: public Shape {
    public:
        Rectangle(int a = 0, int b = 0):Shape(a, b) {}
        int area()
        {
            cout << "Rectangle class area :" << endl;
            return (width * height);
        }
};
class Triangle: public Shape{
    public:
        //构造函数
        Triangle (int a = 0, int b = 0):Shape(a, b) {}
        int area()
        {
            cout << "Triangle class area :" << endl;
            return (width * height / 2);
        }
};
#endif

int main(void)
{
#ifdef VAR
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);

    shape = &rec;
    shape->area();

    shape = &tri;
    shape->area();
#endif
#ifdef BASIC
    Rectangle Rect;

    Rect.setWidth(5);
    Rect.setHeight(7);

    cout << "Total area: " << Rect.getArea() << endl;
#endif

    return 0;
}
