#ifndef NODE_H
#define NODE_H
#include <iostream>

namespace std{

class Node
{
private:
    int data_;
    Node* next_;

public:
    Node(){}
    Node(int data, Node* next): data_(data), next_(next){}
    int data() const {return data_;}
    void  data(int data){ data_ = data;}
    Node* next(){return next_;}
    void next(Node* next){ next_ = next;}
};

void print_list(Node* head);
size_t length(Node* head);
size_t length_r(Node* head);
Node* push_front(int data, Node* head);
Node* pop_front(Node* head);
Node* clear_list(Node* head);
Node* copy_list(Node* head);

}

#endif // NODE_H
