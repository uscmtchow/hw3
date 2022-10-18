#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
    std::vector<T*> vec;
    int top;
};

template <typename T>
Stack<T>::Stack() : stackSize(0) {}

template <typename T>
bool Stack<T>::empty() const {
    if (vec.size() == 0) return true;
    return false;
}

template <typename T>
size_t Stack<T>::size() const { return vec.size(); }

template <typename T>
void Stack<T>::push(const T& item) { vec.push_back(item); }

template <typename T> 
void Stack<T>::pop() {
    if (Stack<T>::empty()) throws std::underflow_error;
    vec.pop_back();
}

template <typename T>
const T& Stack<T>::top() const {
    if (Stack<T>::empty()) throws std::underflow_error;
    return vec.back();
}


#endif