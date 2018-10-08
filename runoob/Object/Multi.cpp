#include <iostream>

using namespace std;

//#define BASIC
#define VIRTUAL

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

class PaintCost
{
    public:
        int getCost(int area)
        {
            return area * 70;
        }
};

class Rectangle: public Shape, public PaintCost
{
    public:
        int getArea()
        {
            return (width * height);
        }
};
#endif

#ifdef VIRTUAL
class D
{
    public:
        D(){cout << "D()" << endl;}
        ~D(){cout << "~D()" << endl;}
    protected:
        int d;
};

class B:virtual public D
{
    public:
        B(){cout << "B()" << endl;}
        ~B(){cout << "~B()" << endl;}
    protected:
        int b;
};
class A:virtual public D
{
    public:
        A(){cout << "A()" << endl;}
        ~A(){cout << "~A()" << endl;}
    protected:
        int a;
};

class C: public B, public A
{
    public:
        C(){cout << "C()" << endl;}
        ~C(){cout << "~C()" << endl;}
    protected:
        int c;
        
};
#endif
int main(void)
{
#ifdef VIRTUAL
    cout << "Hello World!" << endl;
    C c;
    cout << sizeof(c) << endl;
    return 0;
#endif
#ifdef BASIC
    Rectangle Rect;
    int area;

    Rect.setWidth(5);
    Rect.setHeight(7);

    area = Rect.getArea();
    
    cout << "Toral area: " << Rect.getArea() << endl;

    cout << "Total paint cost: $" << Rect.getCost(area) << endl;

    return 0;
#endif
}
