#include <cstring>

class KeyValue
{
	public:
		// Assignment operator overload for deep copy
		KeyValue& operator=(const KeyValue&);		

		// Constructors and destructor
		KeyValue();
		KeyValue(const char* _key, const char* _value);
		KeyValue(const KeyValue&);
		~KeyValue();

		// Getter for this object's key
		char* GetKey() const;
		// Getter for this object's value
		char* GetValue() const;
		
	private:
		// Dynamic arrays for this object's key
		char* key;
		// Dynamic arrays for this object's value
		char* value;
};