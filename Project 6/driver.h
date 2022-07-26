#include "shapes.h"
#include <iostream>

class Driver
{
    public:
        // Assignment operator overload
        Driver operator=(const Driver&);

        // Default constructor
        Driver();
        // Destructor
        ~Driver();
        // Copy constructor
        Driver(const Driver&);
    
        void PrintMenu();
        void AddShape();
        // Sums up the perimeters of all shapes in the list
        double TotalPerimeter();
        // Sums up the areas of all shapes in the list
        double TotalArea();

    private:
        // List of shapes, has DMA
        Shape** shapeList;

        int currentSize;
        int maxSize;

        // Grow function to be called internally
        void Grow();
};