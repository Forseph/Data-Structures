#include "stack.h"
using namespace std;
stack::stack(const stack& source)
{
    //Node* tail_ptr; // Needed for argument of list_copy
    //copy_list(source.top_ptr, top_ptr, tail_ptr);
}

void stack::push(const int& entry)
// Library facilities used: node2.h
{
    push_front(entry,top_ptr);
}
