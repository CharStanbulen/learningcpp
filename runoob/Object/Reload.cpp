#include <iostream>
using namespace std;
//#define BASIC
#define OPR

#ifdef BASIC
class printData
{
    public:
        void print(int i) {
            cout << "Integer is: " << i << endl;
        }
        void print(double f) {
            cout << "float is: " << f << endl;
        }
        void print(char c[]) {
            cout << "string is: " << c << endl;
        }
};
#endif
#ifdef OPR
class Box
{
    public:
        double getVolume(void)
        {
            return length * breadth * height;
        }
        void setLength(double len)
        {
            length = len;
        }
        void setBreadth(double bre)
        {
            breadth = bre;
        }
        void setHeight(double hei)
        {
            height = hei;
        }
        Box operator+(const Box& b)
        {
            Box box;
            box.length = this->length + b.length;
            box.breadth = this->breadth + b.breadth;
            box.height = this->height + b.height;
            return box;
        }
    private:
        double length;
        double breadth;
        double height;
};
#endif

int main(void)
{
#ifdef OPR
    Box Box1;
    Box Box2;
    Box Box3;
    double volume = 0.0;

    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);

    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);
    
    volume = Box1.getVolume();
    cout << "Volime of Box1 : " << volume << endl;

    volume = Box2.getVolume();
    cout << "Volime of Box2 : " << volume << endl;

    Box3 = Box1 + Box2;
    
    volume = Box3.getVolume();
    cout << "Volime of Box3 : " << volume << endl;

#endif
#ifdef BASIC
    printData pd;
    
    pd.print(5);
    pd.print(500.263);
    char c[] = "Hello c++";
    pd.print(c);
#endif

    return 0;
}
