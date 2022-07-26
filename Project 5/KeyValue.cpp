#include "KeyValue.h"
#include <iostream>

using namespace std;

// Assignment operator overload for deep copy
KeyValue& KeyValue::operator=(const KeyValue& keyIn)
{
    if(this != &keyIn)
    {
        // De-allocate the original key and value
        delete [] key;
        delete [] value;

        // Allocate new space for the key and value being copied
        key = new char[strlen(keyIn.GetKey()) + 1];
        value = new char[strlen(keyIn.GetValue()) + 1];

        // Copy the key and value over
        strcpy(key, keyIn.GetKey());
        strcpy(value, keyIn.GetValue());
    }
    // Return this object
    return *this;
}

// Default constructor
KeyValue::KeyValue()
{
    // Allocate a blank space for a key and value
    key = new char;
    value = new char;
}

// Parameterized constructor
KeyValue::KeyValue(const char* _key, const char* _value)
{
    int keySize = strlen(_key);
    int valueSize = strlen(_value);

    key = new char[keySize + 1];
    value = new char[valueSize + 1];

    strcpy(key, _key);
    strcpy(value, _value);
}

// Copy constructor
KeyValue::KeyValue(const KeyValue& keyIn)
{
    // Find the sizes of the key and value and store them
    int keySize = strlen(keyIn.key);
    int valueSize = strlen(keyIn.value);

    // Allocate new space for the key and value being copied
    key = new char[keySize];
    value = new char[valueSize];

    // Copy the key and value over
    strcpy(key, keyIn.GetKey());
    strcpy(value, keyIn.GetValue());
}

// Destructor
KeyValue::~KeyValue()
{
    // De-allocate the key and value for the destructed object
    delete [] key;
    delete [] value;
}

// Key getter
char* KeyValue::GetKey() const
{
    return key;
}

// Value getter
char* KeyValue::GetValue() const
{
    return value;
}