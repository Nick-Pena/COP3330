#include "shapes.h"
#include "driver.h"

using namespace std;

Driver Driver::operator=(const Driver& driverIn)
{
    // If the object being assigned to is not the same as the one being
    // passed in, continue
    if(this != &driverIn)
    {
        // De-allocate the current list of shapes
        delete [] shapeList;

        // Copy values over
        currentSize = driverIn.currentSize;
        maxSize = driverIn.maxSize;

        // Allocate space needed for the list
        shapeList = new Shape*[maxSize];

        // Copy the list over element by element
        for(int i = 0; i < currentSize; i++)
        {
            shapeList[i] = driverIn.shapeList[i];
        }
    }
    // Return a dereferenced object
    return *this;
}

Driver::Driver(const Driver& driverIn)
{
    // Copy values over
    maxSize = driverIn.maxSize;
    currentSize = driverIn.currentSize;

    // allocate space needed for the list
    shapeList = new Shape*[maxSize];

    // Copy the list over element by element
    for(int i = 0; i < currentSize; i++)
    {
        shapeList[i] = driverIn.shapeList[i];
    }
}

Driver::Driver()
{
    currentSize = 0;
    maxSize = 2;
    shapeList = new Shape*[maxSize];
}

Driver::~Driver()
{
    // De-allocate each individual shape in the list
    for(int i = 0; i < currentSize; i++)
    {
        delete [] shapeList[i];
    }

    // De-allocate the entire list afterwards
    delete [] shapeList;
}

void Driver::PrintMenu()
{
    // Simply prints a menu with choices
    cout << "The menu options is as follows." << endl;
    cout << "Enter 'S' to add a shape to the list." << endl;
    cout << "Enter 'A' to add the areas of all shapes currently in the list." << endl;
    cout << "Enter 'P' to add the perimeters of all shapes currently in the list." << endl;
    cout << "Enter 'Q' to exit the menu." << endl;
}

void Driver::AddShape()
{
    // Grow the list as needed
    if(currentSize == maxSize)
    {
        Grow();
    }

    // Prints the menu for adding a shape
    char shapeSelection;
    cout << "What type of shape would you like to add?" << endl;
    cout << "This program supports decimal values! (i.e. 2.5, 6.9, etc.)" << endl << endl;
    cout << "Enter 'S' to add a square." << endl;
    cout << "Enter 'C' to add a circle." << endl;
    cout << "Enter 'T' to add a triangle." << endl;
    cout << "Enter 'Z' to add a trapezoid." << endl;

    // Takes input and converts it to an uppercase letter
    cout << "Enter your selection: ";
    cin >> shapeSelection;
    shapeSelection = toupper(shapeSelection);
    cout << endl;

    // Switch statement to handle each case possible
    switch(shapeSelection)
    {
        case 'S':
            {
                cout << "You have selected Square." << endl;
                double side;
                cout << "Please enter the length of the sides: ";
                cin >> side;

                // Make a new Square pointer and construct it with its own memory allocated
                Square* newSquare;
                newSquare = new Square(side);

                cout << "You have made a square with the side length of " << side <<". Its area is " << newSquare->GetArea()
                     << " and its perimeter is " << newSquare->GetPerimeter() << "." << endl << endl;

                // Set the new object to its respective location in the list
                shapeList[currentSize] = newSquare;
                // Increment the list's size
                currentSize++;

                // For testing
                /* for(int i = 0; i < currentSize; i++)
                    cout << (*shapeList[i]).GetPerimeter() << endl;*/

                break;
            }

        case 'C':
            {
                cout << "You have selected Circle." << endl;
                double radius;
                cout << "Please enter the radius of the circle: ";
                cin >> radius;

                // Make a new Circle pointer and construct it with its own memory allocated
                Circle* newCircle;
                newCircle = new Circle(radius);

                cout << "You have made a new circle with radius " << radius << ". Its area is " << newCircle->GetArea()
                     << " and its perimeter is " << newCircle->GetPerimeter() << "." << endl << endl;
 
                // Set the new object to its respective location in the list
                shapeList[currentSize] = newCircle;
                // Increment the list's size
                currentSize++;
                
                // For testing
                /* for(int i = 0; i < currentSize; i++)
                    cout << (*shapeList[i]).GetPerimeter() << endl;*/

                break;
            }
        
        case 'T':
            {
                cout << "You have selected Triangle." << endl;
                double sideOne, sideTwo, base, height;
                cout << "Please enter the length of the first side: ";
                cin >> sideOne;
                cout << "Please enter the length of the second side: ";
                cin >> sideTwo;
                cout << "Please enter the length of the base: ";
                cin >> base;
                cout << "Please enter the height of the triangle: ";
                cin >> height;

                // Make a new Triangle pointer and construct it with its own memory allocated
                Triangle* newTriangle;
                newTriangle = new Triangle(sideOne, sideTwo, base, height);

                cout << "You have made a new triangle with sides of length " << sideOne << " and " << sideTwo << ", a base of length " << base
                     << ", and a height of size " << height << "." << endl << endl;
                cout << "Its area is " << newTriangle->GetArea() << " and its perimeter is " << newTriangle->GetPerimeter() << "." << endl << endl;

                // Set the new object to its respective location in the list
                shapeList[currentSize] = newTriangle;
                // Increment the list's size
                currentSize++;

                // For testing
                /*for(int i = 0; i < currentSize; i++)
                    cout << (*shapeList[i]).GetPerimeter() << endl;*/

                break;
            }

        case 'Z':
            {
                cout << "You have selected Trapezoid." << endl;
                double baseTop, baseBottom, sideOne, sideTwo, height;
                cout << "Please enter the length of the top base: ";
                cin >> baseTop;
                cout << "Please enter the length of the bottom base: ";
                cin >> baseBottom;
                cout << "Please enter the length of the first side: ";
                cin >> sideOne;
                cout << "Please enter the length of the second side: ";
                cin >> sideTwo;
                cout << "Please enter the height of the trapezoid: ";
                cin >> height;

                // Make a new Trapezoid pointer and construct it with its own memory allocated
                Trapezoid* newTrapezoid;
                newTrapezoid = new Trapezoid(baseTop, baseBottom, sideOne, sideTwo, height);

                cout << "You have made a new trapezoid with the bases of length " << baseTop << " and " << baseBottom
                     << ", sides of length " << sideOne << " and " << sideTwo << ", and a height of size " << height << "." << endl;
                cout << "Its area is " << newTrapezoid->GetArea() << " and its perimeter is " << newTrapezoid->GetPerimeter() << "." << endl << endl;

                // Set the new object to its respective location in the list
                shapeList[currentSize] = newTrapezoid;
                // Increment the list's size
                currentSize++;

                // For testing
                /*for(int i = 0; i < currentSize; i++)
                    cout << (*shapeList[i]).GetPerimeter() << endl;*/

                break;
            }
    }
}

double Driver::TotalArea()
{
    double result = 0;

    // Adds each individual shape's area to a running total
    // Utilizes each shape's formula to accomplish this
    for(int i = 0; i < currentSize; i++)
    {
        result += (*shapeList[i]).GetArea();
        cout << "Running total: " << result << endl;
    }

    return result;
}

double Driver::TotalPerimeter()
{
    double result = 0;

    // Adds each individual shape's perimeter to a running total
    // Utilizes each shape's formula to accomplish this
    for(int i = 0; i < currentSize; i++)
    {
        result += (*shapeList[i]).GetPerimeter();
        cout << "Running total: " << result << endl;
    }
    
    return result;
}

void Driver::Grow()
{
    // Grows the pairs array if needed
    // Increase max size of the array
    maxSize = currentSize + 1;
    // Create a new temporary pair array with the size of the new max size
    Shape** tempList = new Shape*[maxSize];

    // Copy all elements from old array to the new array
    for(int i = 0; i < currentSize; i++)
    {
        tempList[i] = shapeList[i];
    }

    // De-allocate the old array
    delete [] shapeList;

    // Re-point to the newly sized array
    shapeList = tempList;
}