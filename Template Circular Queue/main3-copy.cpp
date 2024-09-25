#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "FiniteQueue-copy.h"

using namespace std;

void displayTestCase(int count, string name)
{
    cout << string(18, '-') << " Test " << to_string(count) << " " << name << " " << string(18,'-') << endl;
}


//take inputs from the user until q is full
template <typename T>
istream& operator>>(istream& in, FiniteQueue<T>& q)
{
    //size: number of data items (existing)
    T data;
    int count = q.get_capacity() - q.get_size();
    cout << "Enter data " << count << " data items: ";
    for (int i = 0; i < count; i++)
    {
        if (!(in >> data))
        {
            break;
        }
        q.push(data);
    }
    return in;
}

template <typename T>
ostream& operator<<(ostream& out, const FiniteQueue<T>& q)
{
    /* MISTAKE ONE: 
    this code assumes that the first will be zero and the last is size -1
    for (int i = 0; i < q.set_size(); i++)
    {
        //important thing about a finite queue: never know where the first and last element ACTUALLY ARE
        //out << setw(3) << q.array[i]; //non-friend operator<< cannot access array
        out << setw(3) << q[i]; //q[i] --> q.operator[](i);
    }
    out << endl;
    
    MISTAKE TWO:
    last can be less than first. We can't assume that first is always less than last
    for (int i = q.get_first(); i < q.get_last(); i++)
    {
        out << setw(3) << q[i]; //q[i] --> q.operator[](i);
    }
    out << endl;
    */
    int first = q.get_first();
    for (int i = 0; i < q.get_size(); i++)
    {
        //first is not a member of q, local variable
        //range: 0 ~ capacity - 1;
        if (first + i >= q.get_capacity())
        {
            out << setw(3) << q[first + 1 - q.get_capacity()];
        }
        else
        {
            out << setw(3) << q[first + i];
        }
    }
    out << endl;
    return out;
}

int main()
{
    int count = 0;
    const int SIZE = 5; 
    
    FiniteQueue<int> q1(SIZE); //instantiation of the template class;
                        //the compiler will generate the code for FiniteQueue<int>
                        //makes all the code behind the scene
    FiniteQueue<string> q2(SIZE);
    displayTestCase(1, "FiniteQueue<int> push");
    //put a code under try if it may cause an exception
    try {
        for(int i = 0; i < 5; i++)
        {
            q1.push(rand() % 10); //QueueFullException
        }
    }
    catch(FiniteQueue<int>::QueueFullException& excep)
    {
        std::cout << "QueueFullException occured\n";
    }
    catch(FiniteQueue<int>::QueueEmptyException& excep)
    {
        std::cout << "QueueEmptyException occured\n";
    }
    catch (...) //ellipses
    {
        std::cout << "Exception occured\n";
    }
    displayTestCase(2, "FiniteQueue<string> push");
    try {
        for(int i = 0; i < 5; i++)
        {
            q2.push(to_string(rand() % 10)); //QueueFullException
        }
    }
    catch(FiniteQueue<string>::QueueFullException& excep)
    {
        std::cout << "QueueFullException occured\n";
    }
    catch(FiniteQueue<string>::QueueEmptyException& excep)
    {
        std::cout << "QueueEmptyException occured\n";
    }
    catch (...) //ellipses
    {
        std::cout << "Exception occured\n";
    }

    displayTestCase(3, "FiniteQueue<int> pop");
    try {
        for(int i = 0; i < 5; i++)
        {
            q1.pop(); //QueueEmptyException
        }
    }
    catch(FiniteQueue<int>::QueueEmptyException& excep)
    {
        std::cout << "QueueEmptyException occured\n";
    }
    displayTestCase(4, "FiniteQueue<string> pop");
    try {
        for(int i = 0; i < 5; i++)
        {
            q2.pop(); //QueueEmptyException
        }
    }
    catch(FiniteQueue<string>::QueueEmptyException& excep)
    {
        std::cout << "QueueEmptyException occured\n";
    }

    return 0;
}