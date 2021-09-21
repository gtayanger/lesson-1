#include <iostream>

using namespace std;
#pragma pack(push, 1)
class Shape
{
public:
    double x;
    double y;

    void PrintPosition()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }

    virtual void f1()
    {
        cout << "Shape::f1()" << endl;
    }

    void f2()
    {
    }

    virtual double Area() = 0;
    //double Area()
    //{
    //    return NAN; // NAN +INF -INF
    //}
};
#pragma pack(pop)

class Circle : public Shape
{
public:
    double r;

    void f1() override
    {
        cout << "Circle::f1()" << endl;
    }

    double Area() override
    {
        return r * r * 3.14;
    }
};

class Square : public Shape
{
public:
    double e;

    double Area() override
    {
        return e * e;
    }
};

struct Shape_C
{
    double x;
    double y;
};

void PrintPosition_C(Shape_C* pobj)
{
    cout << "(" << pobj->x << "," << pobj->y << ")" << endl;
}

double Area_C(Shape_C* pobj)
{
    return NAN;
}

int main_1()
{
    cout << sizeof(Shape) << endl;
    cout << sizeof(Shape_C) << endl;

    //Shape s;
    //s.x = 123;
    //s.y = 456;
    //s.PrintPosition();
    //cout << s.Area() << endl;

    Shape_C s2;
    s2.x = 123;
    s2.y = 456;
    PrintPosition_C(&s2);

    cout << sizeof(void*) << endl;
    //int32_t arr[4] = {0x00000102, 0x1a2b0304, 0x0506, 0x0708};
    //void* p = arr;
    //for (int i = 0; i < 8; i++)
    //    printf("%X\n", ((char*)p)[i]);

    cout << "===================" << endl;
    Circle circle0;
    circle0.x = 0;
    circle0.y = 0;
    circle0.r = 1;

    Square square0;
    square0.x = 100;
    square0.y = 100;
    square0.e = 5;

    circle0.PrintPosition();
    cout << circle0.Area() << endl;

    square0.PrintPosition();
    cout << square0.Area() << endl;

    Shape* pshape;

    pshape = &circle0;
    cout << "area of circle = " << pshape->Area() << endl;
    pshape->f1();
    //cout << "area of circle = " << Area_C(pshape) << endl;

    pshape = &square0;
    cout << "area of square = " << pshape->Area() << endl;
    pshape->f1();
    
    return 0;
}
