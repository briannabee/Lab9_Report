#ifndef FINITE_QUEUE_H
#define FINITE_QUEUE_H

template <typename T> //typename: keyword, T: symbol indicating a generic data type
                    //can be replaced by symbol of your choice
                    //some people use typename replaced by class
class FiniteQueue //FIRST IN, FIRST OUT
//template <typename T> class FiniteQueue --> FiniteQueue<T>: class name
{
private:
    T* array;
    int first; //the index of the array where the first element is located
    int last; //last element
    int capacity; //the capacity of the array
    int size; //how many values actually occupies the array
public:
    FiniteQueue();
    FiniteQueue(int); //capacity of an array
    FiniteQueue(const FiniteQueue<T>&);
    virtual ~FiniteQueue();

    //empty inner class for exception handling
    //The definition of a class A cannot contain a definition of another class;
    //except when B's body is empty
    class QueueEmptyException {};
    class QueueFullException {};

    void push(T value); //enqueue
    void pop(); //dequeue
    bool is_empty();
    bool is_full();

    //index operator
    T& operator[](int);
    int get_capacity();
    int get_size();
    int get_first();
    int get_last();
    
};

template <typename T>
FiniteQueue<T>::FiniteQueue()
{
    capacity = 5;
    array = new T[capacity];
    first = 0;
    last = capacity - 1;
    size = 0;
}
template <typename T>
FiniteQueue<T>::FiniteQueue(int c)
{
    capacity = c;
    array = new T[capacity];
    first = 0;
    last = capacity - 1;
    size = 0;
    
}
template <typename T>
FiniteQueue<T>::FiniteQueue(const FiniteQueue<T>& right)
{
    capacity = right.capacity;
    array = new T[capacity];
    first = right.first;
    last = right.last;
    size = right.size;
    //copy the array of right
    //do it: add
}
template <typename T>
FiniteQueue<T>::~FiniteQueue()
{
    delete[] array;
}
template <typename T>
void FiniteQueue<T>::push(T value) //last index 
{
    if(is_full())
        throw QueueFullException();
    //normal situation where the queue is not full
    last = (++last) % capacity;
    array[last] = value;
    size++;
    std::cout << "push() called: " << &array[last] << std::endl;
}
template <typename T>
void FiniteQueue<T>::pop() //first
{
    if(is_empty())
    {
        throw QueueEmptyException(); //the call of the defauly constructor
                                    //when the throw statement is executed, immediately returns to main() function, like break;
    }
    //normal situation where the queue is not empty
    //if (first == capacity)
    std::cout << "pop() called: " << &array[first] << std::endl;
    first = (++first) % capacity;
    size--;
}
template <typename T>
bool FiniteQueue<T>::is_empty()
{
    return (size == 0);
}
template <typename T>
bool FiniteQueue<T>::is_full()
{
    return (size == capacity);
}

template <typename T>
T& FiniteQueue<T>::operator[](int index)    //q1[2] = 10
{
    return array[index];
}

template <typename T>
int FiniteQueue<T>::get_capacity()
{
    return capacity;
}

template <typename T>
int FiniteQueue<T>::get_size()
{
    return size;
}

template <typename T>
int FiniteQueue<T>::get_first()
{
    return first;
}

template <typename T>
int FiniteQueue<T>::get_last()
{
    return last;
}

#endif