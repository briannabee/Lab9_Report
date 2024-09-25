#include <iostream>
#include "Stack.h"

using namespace std;

double Stack::top()
{
    //cout << "Top() ran" << endl;
    if (is_empty())
    {
    throw StackEmptyException(); //no catch block, immediately return
    }
    return top_node->data;
}

void Stack::push(double data)
{
    try
    {
        //cout << "Push() ran" << endl;
        dNode* new_node = new dNode(data); //if new fails, bad_alloc occurs
        new_node->next = top_node;
        top_node = new_node;
    }
    catch (const bad_alloc& e) 
    {
        cout << "memory allocation exception: " << e.what() << endl;
        exit(1);
    }
}

//additional implementations to make it run

void Stack::pop()
{
    //cout << "Pop() ran" << endl;
    dNode* temp = top_node;
    top_node = top_node->next;
    delete temp;
}

bool Stack::is_empty()
{
    return top_node == nullptr;
}