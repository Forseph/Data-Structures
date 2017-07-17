#ifndef STACK_H
#define STACK_H

#include "node.h"

class stack: public std::Node
{
private:
    std::Node* top_ptr;
public:
    typedef std::size_t size_type;
    stack(){top_ptr = nullptr;}
    stack(const stack& source);
    ~stack(){clear_list(top_ptr);}

    void push(const int& entry);
    void pop();
    void operator =(const stack& source);

    size_type size( ) const{return (length(top_ptr));}
    bool empty( ) const { return (top_ptr == nullptr); }
    int top()const {return top_ptr->data();}

};

#endif // STACK_H
