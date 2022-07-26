#include "dictionary.h"
#include <iostream>

using namespace std;

// Assignment operator overload for deep copy
Dictionary& Dictionary::operator=(const Dictionary& dictIn)
{
    if(this != &dictIn)
    {
        // Delete the old arrays
        delete [] pairs;
        delete [] keys;
        delete [] values;

        // Copy the current and max sizes
        currentSize = dictIn.currentSize;
        maxSize = dictIn.maxSize;

        // Allocate space for the new arrays
        pairs = new KeyValue[maxSize];
        keys = new char*[maxSize];
        values = new char*[maxSize];

        // Copy everything over
        for(int i = 0; i < currentSize; i++)
        {
            pairs[i] = dictIn.pairs[i];
            strcpy(keys[i], dictIn.keys[i]);
            strcpy(values[i], dictIn.values[i]);
        }
    }
    // Return this object
    return *this;    
}

// Default constructor
Dictionary::Dictionary()
{
    // Arbitrary starting and max values
    currentSize = 0;
    maxSize = 2;
    // Allocating space needed for arrays
    pairs = new KeyValue[maxSize];
    keys = new char*[maxSize];
    values = new char*[maxSize];
}

// Copy constructor
Dictionary::Dictionary(const Dictionary& dictIn)
{
    // Copy max and current size values
    maxSize = dictIn.maxSize;
    currentSize = dictIn.currentSize;

    // Allocate space based on max size
    pairs = new KeyValue[maxSize];
    keys = new char*[maxSize];
    values = new char*[maxSize];

    // Copy each pair over to the new object
    for(int i = 0; i < currentSize; i++)
    {
        pairs[i] = dictIn.pairs[i];
        strcpy(keys[i], dictIn.keys[i]);
        strcpy(values[i], dictIn.values[i]);
    }
}

// Destructor
Dictionary::~Dictionary()
{
    // De-allocate everything
    delete [] pairs;

    // Loop through each keys list to de-allocate each key, then the whole list
    for(int i = 0; i < currentSize; i++)
    {
        delete [] keys[i];
    }
    delete [] keys;

    // Loop through each values list to de-allocate each value, then the whole list
    for(int j = 0; j < currentSize; j++)
    {
        delete [] values[j];
    }
    delete [] values;
}

// Returns the list of keys when called
char** Dictionary::Keys()
{
    // Handles potential memory issues
    if(currentSize > 0)
    {
        delete [] keys;
    }
    // Allocate space for the array of values based on the current size of the array of key-value pairs
    keys = new char*[currentSize];

    // Allocate each individual element of the array space based on each key's string length
    // then copy the string over
    for(int i = 0; i < currentSize; i++)
    {
        keys[i] = new char[(strlen(pairs[i].GetKey()))];
        strcpy(keys[i], pairs[i].GetKey());
    }
    // Returns the list of keys
    return keys;
}

// Returns the list of values when called
char** Dictionary::Values()
{
    // Handles potential memory issues
    if(currentSize > 0)
    {
        delete [] values;
    }
    // Allocate space for the array of values based on the current size of the array of key-value pairs
    values = new char*[currentSize];

    // Allocate each individual element of the array space based on each value's string length
    // then copy the string over
    for(int i = 0; i < currentSize; i++)
    {
        values[i] = new char[(strlen(pairs[i].GetValue()))];
        strcpy(values[i], pairs[i].GetValue());
    }
    // Returns the list of values
    return values;  
}

// Returns the current size of the array of pairs
int Dictionary::Count() const
{
    return currentSize;
}

// Returns the value for the given key
char* Dictionary::Get(const char* _key)
{
    // Search the array for a pair with the given key
    for(int i = 0; i < currentSize; i++)
    {
        if((strcmp(_key, pairs[i].GetKey())) == 0)
        {
            // Return the value if the key exists
            return pairs[i].GetValue();
        }
        else if(((strcmp(_key, pairs[i].GetKey())) != 0) && (i == currentSize - 1))
        {
            // Print an exception if it doesn't exist
            cout << "No pair found for the key " << _key << endl;
        }
    }
    // Returns a blank string, not sure how else to do this
    return "";
}

// Adds the provided key-value pair or doesn't do anything if there is already a pair with the given key
void Dictionary::Add(const char* _key, const char* _value)
{    
    cout << "Attempting to add the pair " << _key << " - " << _value << " to the list." << endl;

    // Compare the input key to existing keys. If it exists, return from the function and print an exception
    for(int i = 0; i < currentSize; i++)
    {
        if(strcmp(pairs[i].GetKey(), _key) == 0)
        {
            cout << "Key exists, cannot add the pair." << endl << endl;
            return;
        }
    }

    // If the array isn't large enough, grow it
    if(currentSize == maxSize)
    {
        Grow();
    }

    // Temporary pair to copy into the array
    KeyValue tempPair(_key, _value);

    // Put the new key-value pair into the top-most space in the array
    pairs[currentSize] = tempPair;

    cout << "Pair adding successful." << endl << endl;

    // Increment the current size
    currentSize++;
}

// Adds the provided key-value pair or replaces the existing pair with the given key
void Dictionary::Replace(const char* _key, const char* _value)
{
    // Find the key and return the index
    int keyFound = FindKey(_key);

    // If no key found, it returns -1 and moves forward to adding the key to the array
    if(keyFound == -1)
    {
        Add(_key, _value);
    }
    // If the key is found, use the index to replace the key via temporary pair assignment
    else
    {
        KeyValue tempPair(_key, _value);

        cout << "Replacing value associated with " << pairs->GetKey() << " from " << pairs->GetValue() << " to " << tempPair.GetValue() << endl << endl;
        pairs[keyFound] = tempPair;
    }
}

// Removes the key-value pair with the given key
void Dictionary::Remove(const char* _key)
{
    // Find the key and return the index
    int keyFound = FindKey(_key);

    // If the key isn't found print an exception
    if(keyFound == -1)
    {
        cout << "No matching key found." << endl;
    }
    // If the key is found, handle logic
    else
    {
        // Start from the keyFound + 1 position, while it's less than the current size we keep
        // looping and overwriting pairs until we've reached the end of the array
        for(int i = keyFound + 1; i < currentSize; i++)
        {
            pairs[i - 1] = pairs[i];
        }
        // Decrement the size
        currentSize--;
        cout << "The key " << _key << " was removed from the list." << endl;
    }
}

// Find a key in an array, returns the index
int Dictionary::FindKey(const char* key)
{
    // Compare the key that was input
    for(int i = 0; i < currentSize; i++)
    {
        // If the key is found, return the index
        if(strcmp(pairs[i].GetKey(), key) == 0)
        {
            return i;
        }
    }
    // If the key is not found, return -1
    return -1;
}

// Grows the pairs array if needed
void Dictionary::Grow()
{
    // Increase max size of the array
    maxSize = currentSize + 1;
    // Create a new temporary pair array with the size of the new max size
    KeyValue* tempPair = new KeyValue[maxSize];

    // Can use malloc if desired
    // KeyValue* tempPair = (KeyValue*) malloc(maxSize * sizeof(KeyValue));

    // Copy all elements from old array to the new array
    for(int i = 0; i < currentSize; i++)
    {
        tempPair[i] = pairs[i];
    }

    // De-allocate the old array
    delete [] pairs;
    // Re-point to the newly sized array
    pairs = tempPair;
}