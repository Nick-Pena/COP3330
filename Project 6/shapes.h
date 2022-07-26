#ifndef SHAPES_H    // Can probably ignore this
#define SHAPES_H    // And this, just trying it out
#include <iostream>
#include <math.h>   // For M_PI

// Base class
// Derived classes: Square, Circle, Triangle, Trapezoid
class Shape
{
    public:
        // Pure virtual function to return the perimeter
        virtual double GetPerimeter() = 0;
        // Pure virtual function to return the area
        virtual double GetArea() = 0;

    protected:
        // Area data member for derived classes
        double area;
        // Perimeter data member for derived classes
        double perimeter;
};

// Derived from: Shape
class Square: public Shape
{
    public:
        // Default constructor
        Square();
        // Parameterized constructor
        Square(double);

        // GetPerimeter override for Square
        double GetPerimeter();
        // GetArea override for Square
        double GetArea();

    private:
        double side;
};

// Derived from: Shape
class Circle: public Shape
{
    public:
        // Default constructor
        Circle();
        // Parameterized constructor
        Circle(double);

        // GetPerimeter override for Circle
        double GetPerimeter();
        // GetArea override for Circle
        double GetArea();

    private:
        double radius;
};

// Derived from: Shape
class Triangle: public Shape
{
    public:
        // Default constructor
        Triangle();
        // Parameterized constructor
        Triangle(double, double, double, double);

        // GetPerimeter override for Triangle
        double GetPerimeter();
        // GetArea override for Triangle
        double GetArea();

    private:
        double sideOne;
        double sideTwo;
        double base;
        double height;
};

// Derived from: Shape
class Trapezoid: public Shape
{
    public:
        // Default constructor
        Trapezoid();
        // Parameterized constructor
        Trapezoid(double, double, double, double, double);

        // GetPerimeter override for Trapezoid
        double GetPerimeter();
        // GetArea override for Trapezoid
        double GetArea();

    private:
        double baseTop;
        double baseBottom;
        double sideOne;
        double sideTwo;
        double height;
};
#endif  // Refer to comment on line 1 of shapes.h