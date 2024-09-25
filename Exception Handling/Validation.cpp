#include <iostream>
#include <string>
#include <stdexcept> // For std::invalid_argument

using namespace std;

class InvalidDataException : public invalid_argument 
{
public:
 InvalidDataException(const string& message) : invalid_argument(message) {}
};

int main() 
{
    int value = -1;
    try
    {
        if (value < 0) 
        {
            throw InvalidDataException("Value cannot be negative");
        }
        // Process the valid value
    } 
    catch (const InvalidDataException& e)
    {
        cerr << "Invalid data: " << e.what() << endl;
    } 
    catch (const exception& e) 
    {
    // Handle other exceptions
        cerr << "An unexpected error occurred: " << e.what() << endl;
    }
    return 0;
}