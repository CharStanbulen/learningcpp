#include <iostream>

using namespace std;

//#define BASIC
//#define MEMBER
#define PROTECT

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

int main()
{
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
