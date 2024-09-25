#include <iostream>
#include "Stack.h"

using namespace std;

void StackEmptyException()
{
    Stack s;
    try
    {
        s.top();
        cerr << "Empty Top() did not throw StackEmptyException." << endl;
    }
    catch(const Stack::StackEmptyException& e)
    {
        cout << "Empty Top() threw StackEmptyException." << endl;
    }

    try
    {
        s.push(10);
        cout << "Push() did not throw MemoryAllocationException." << endl;
    }
    catch(const bad_alloc& e)
    {
        cerr << "Push() threw MemoryAllocationException." << endl;
        exit(1);
    }
}

int main()
{
    Stack o;
   
    cout << "Basic functionality: " << endl;

    o.push(1);
    o.push(3);
    o.push(5);
    cout << "Top element: " << o.top() << endl;
    o.pop();
    cout << "Top element after pop(): " << o.top() << endl;
    o.pop();
    cout << "Top element after pop(): " << o.top() << endl;
    o.pop();

    StackEmptyException();

    return 0;
}