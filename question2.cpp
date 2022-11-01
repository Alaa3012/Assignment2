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
