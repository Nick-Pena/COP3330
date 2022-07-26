#include "shapes.h"

using namespace std;

Square::Square()
{
    side = 0;
}

Square::Square(double _side)
{
    side = _side;
}

double Square::GetArea()
{
    area = pow(side, 2);
    return area;
}

double Square::GetPerimeter()
{
    perimeter = side * 4;
    return perimeter;
}

Circle::Circle()
{
    radius = 0;
}

Circle::Circle(double _radius)
{
    radius = _radius;
}

double Circle::GetArea()
{
    area = pow((radius), 2) * M_PI;
    return area;
}

double Circle::GetPerimeter()
{
    perimeter = (radius * 2 * M_PI);
    return perimeter;
}

Triangle::Triangle()
{
    sideOne = 0;
    sideTwo = 0;
    base = 0;
}

Triangle::Triangle(double _sideOne, double _sideTwo, double _base, double _height)
{
    sideOne = _sideOne;
    sideTwo = _sideTwo;
    base = _base;
    height = _height;
}

double Triangle::GetArea()
{
    area = (height * base) / 2;
    return area;
}

double Triangle::GetPerimeter()
{
    perimeter = sideOne + sideTwo + base;
    return perimeter;
}

Trapezoid::Trapezoid()
{
    baseTop = 0;
    baseBottom = 0;
    sideOne = 0;
    sideTwo = 0;
    height = 0;
}

Trapezoid::Trapezoid(double _baseTop, double _baseBottom, double _sideOne, double _sideTwo, double _height)
{
    baseTop = _baseTop;
    baseBottom = _baseBottom;
    sideOne = _sideOne;
    sideTwo = _sideTwo;
    height = _height;
}

double Trapezoid::GetArea()
{
    area = ((baseTop + baseBottom) / 2) * height;
    return area;
}

double Trapezoid::GetPerimeter()
{
    perimeter = baseTop + baseBottom + sideOne + sideTwo;
    return perimeter;
}