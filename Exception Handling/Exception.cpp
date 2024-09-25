// using standard exceptions
#include <iostream>
#include <exception>

using namespace std;

class MyException: public exception 
{
    virtual const char* what() const throw() 
    { //overriding
        return "MyException occurred";
        //Note that char* indicates a null-terminated character string called C-string
    }
};

int main () 
{
    try
    {
        throw MyException(); //an object created by calling the default constructor.
    }
        catch (exception& e) //catch by reference
    {
        cout << e.what() << '\n'; //Is this polymorphic code? Test it yourself
    }
    return 0;
}