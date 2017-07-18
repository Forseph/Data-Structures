#ifndef STACK_H
#define STACK_H
#include "node.h"

namespace std
{

template <typename T>
class stack: public Node<T>
{
private:
    Node<T>* top_ptr;
public:
    typedef size_t size_type;
    stack(){top_ptr = nullptr;}
    //stack(const stack<T> &source);
    ~stack(){clear_list(top_ptr);}
    void push(const T& entry){ top_ptr = push_front(entry,top_ptr);}
    void pop() { top_ptr = pop_front(top_ptr);}
    stack<T>& operator =(const stack<T>& source);

    size_type size( ) const{return (length(top_ptr));}
    bool empty( ) const { return (top_ptr == nullptr); }
    Node<T>* top() const {return top_ptr;}
    stack<T> copy_stack(const stack<T>& source);


};

template <typename T>
stack<T>& stack<T>:: operator =(const stack<T>& source)
{
    if(this == &source) return *this;
    Node<T>* temp = source.top();
    while(temp !=nullptr)
    {
        this->push(temp->data());
        temp = temp->next();
    }
    return *this;
}

template <typename T>
void print_stack(const stack<T>& source)
{
    cout << "Printing stack: \n";
    Node<T>* temp = source.top();
    while(temp != nullptr)
    {
        cout << temp->data() << endl;
        temp = temp->next();
    }

}


template <typename T>
stack<T> copy_stack(const stack<T>& source)
{
    stack<T> new_stack;
    Node<T>* temp = source.top();
    while(temp != nullptr)
    {
        new_stack.push(temp->data());
        temp = temp->next();
    }
    return new_stack;
}


}




#endif // STACK_H
