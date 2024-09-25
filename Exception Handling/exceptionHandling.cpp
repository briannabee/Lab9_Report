#include <iostream>

using namespace std;

int main() 
{
    try 
    {
        int age = 15;
        if (age >= 18) 
    {
        cout << "Access granted - you are old enough.";
    } 
    else 
    {
        throw age; //throw by value
    }
    }
    catch (int& my_num) 
    { //catch by reference to avoid unnecessary copy.
        cout << "Access denied - you must be at least 18 years old.\n";
        cout << "Age is: " << my_num;
    }
}