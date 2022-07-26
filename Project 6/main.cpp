#include "shapes.h"
#include "driver.h"

#include <iostream>

using namespace std;

int main()
{
    // Driver object to handle most things
    Driver mainDriver;
    char selection;

    cout << "Let's do some math with shapes!" << endl << endl;

    // Runs at least once. If the user inputs 'Q', we exit the program
    do
    {
        // Display the menu
        mainDriver.PrintMenu();

        // Prompt the user for what they would like to do
        // and convert their selection to uppercase
        cout << "Enter your selection: ";
        cin >> selection;
        selection = toupper(selection);
        cout << endl;

        // Switch statement to handle the cases
        switch(selection)
        {
            // Adds a shape
            case 'S':
                mainDriver.AddShape();
                break;

            // Prints the total of all shapes' areas in the list
            case 'A':
                cout << mainDriver.TotalArea() << endl;
                break;

            // Prints the total of all shapes' perimeters in the list
            case 'P':
                cout << mainDriver.TotalPerimeter() << endl;
                break;

            // Exits the program
            case 'Q':
                break;
        }
    } while (selection != 'Q');
}