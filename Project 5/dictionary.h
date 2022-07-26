#include <cstring>
#include "KeyValue.h"

class Dictionary
{
    public:
        // Assignment operator overload for deep copy
        Dictionary& operator=(const Dictionary&);

        // Constructors and destructor
        Dictionary();
        Dictionary(const Dictionary&);
        ~Dictionary();

        // Dynamically allocated arrays for keys, containing char* dynamically allocated CStrings. Returns the list of keys
        char** Keys();
        // Dynamically allocated arrays for values, containing char* dynamically allocated CStrings. Returns the list of values
        char** Values();

        // Returns the current size of the array of pairs
        int Count() const;
        
        // Returns the value for the given key
        char* Get(const char* _key);
        // Adds the provided key-value pair or doesn't do anything if there is already a pair with the given key
        void Add(const char* _key, const char* _value);
        // Adds the provided key-value pair or replaces the existing pair with the given key
        void Replace(const char* _key, const char* _value);
        // Removes the key-value pair with the given key
        void Remove(const char* _key);

        // Find a key in an array, returns the index
        int FindKey(const char*);

    private:
        // Current size of the array
        int currentSize;
        // Max size of the array
        int maxSize;

        // Dynamically allocated list of keys
        char** keys;
        // Dynamically allocated List of values
        char** values;
        // Dynamically allocated list of pairs
        KeyValue* pairs;

        // Grows the pairs array if needed
        void Grow();
};