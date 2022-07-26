#include "dictionary.h"
#include <iostream>

using namespace std;

int main()
{
    Dictionary dictionary;

    // Testing the adding of a pair
    dictionary.Add("first", "cat");
    // Testing that it won't add a pair if a key exists
    dictionary.Add("first", "dog");
    // Testing that Replace will add a key if it doesn't exist
    dictionary.Replace("second", "frog");
    // Testing that Replace will overwrite a key's value if it exists
    dictionary.Replace("first", "bat");
    // Testing add further
    dictionary.Add("third", "cow");
    // Testing add further
    dictionary.Add("fourth", "fish");

    // Testing get with a valid and invalid key
    cout << "Get test: " << dictionary.Get("first") << endl;
    cout << dictionary.Get("tenth");
    
    // Testing the array once
    cout << endl << "Testing the array prior to the removal." << endl << endl;
    for(int i = 0; i < dictionary.Count(); i++)
    {
        cout << "Entry #" << i + 1 << ": " << dictionary.Keys()[i] << " - " << dictionary.Values()[i] << endl;
    }

    cout << "The number of key-value pairs in the array is: " << dictionary.Count() << endl << endl;
    
    // Removing a key-value pair
    dictionary.Remove("third");

    // Testing the array again post-removal
    cout << endl << "Testing the array after the removal." << endl << endl;
    for(int i = 0; i < dictionary.Count(); i++)
    {
        cout << "Entry #" << i + 1 << ": " << dictionary.Keys()[i] << " - " << dictionary.Values()[i] << endl;
    }
    cout << "The number of key-value pairs in the array is: " << dictionary.Count() << endl;
}