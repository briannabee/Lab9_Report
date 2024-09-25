#ifndef STACK_H
#define STACK_H

struct dNode
{
    double data;
    dNode* next;
    dNode(double newData) : data(newData), next(nullptr) {}
};

class Stack
{
private:
    dNode* top_node;

public:
    class StackEmptyException {};

    double top();
    void push(double);
    void pop();
    bool is_empty();
};

#endif