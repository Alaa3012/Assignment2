#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

template <class T>
class Stack
{
private:
    vector<T> array;

public:
    void push(T k);
    bool pop();
    T top();
    bool empty();
    T size();
    Stack<T> operator+(Stack<T> stack2);
};

template <class T>
Stack<T> Stack<T>::operator+(Stack<T> stack2)
{
    vector<T> temporary;
    Stack<T> newStack;
    int stack2Size = stack2.size();
    int stackSize = Stack<T>::size();

    for (int i = 0; i < stack2Size; i++)
    {

        temporary.push_back(stack2.top());
        stack2.pop();
    }

    for (int i = 0; i < stackSize; i++)
    {
        temporary.push_back(Stack<T>::top());
        Stack<T>::pop();
    }
    int size = temporary.size();
    for (int i = 0; i < size; i++)
    {
        newStack.push(temporary.back());
    std:
        temporary.pop_back();
    }
    return newStack;
}

template <class T>
void Stack<T>::push(T k)
{
    array.push_back(k);
}

template <class T>
bool Stack<T>::empty()
{
    return array.size() == 0;
}


template <class T>
bool Stack<T>::pop()
{
    if (empty() == true)
        return false;
    array.pop_back();
    return true;
}


template <class T>
T Stack<T>::top()
{
    return array[array.size() - 1];
}


template <class T>
T Stack<T>::size()
{
    return array.size();
}
int main()
{
    Stack<int> integer_stack;
    Stack<int> integer_stack2;

    integer_stack.push(1);
    integer_stack.push(2);
    integer_stack2.push(3);
    integer_stack2.push(4);
    std::cout << integer_stack.top();
    std::cout << "\n";
    integer_stack.pop();
    std::cout << integer_stack.top();
    std::cout << "\n";
    Stack<int> a = integer_stack + integer_stack2;
    a.pop();
    std::cout << a.top();
    return 0;
}
