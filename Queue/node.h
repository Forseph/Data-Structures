#ifndef NODE_H
#define NODE_H
#include <iostream>
namespace std{


template <typename T>
class Node
{
private:
    T data_;
    Node<T>* next_;

public:
    Node(){}
    Node(T data, Node<T>* next): data_(data), next_(next){}

    T data() const {return data_;}
    void  data(T data){ data_ = data;}
    Node* next(){return next_;}
    void next(Node<T>* next){next_ = next;}
};

template <typename T>
Node<T>* push_back(T data, Node<T>* head)
{
    Node<T>* newnode = new Node<T> (data,nullptr);
    Node<T>* tail = head;
    Node<T>* current = head;
    if(head == nullptr)
    {
        return newnode;
    }
    while(tail != nullptr)
    {
        current = tail;
        tail = tail->next();
    }

    current->next(newnode);
    return head;

}


template <typename T>
Node<T>* push_front(T data, Node<T>* head)
{
    Node<T>* newnode = new Node<T>(data, nullptr);
    newnode->next(head);
    return newnode;
}


template <typename T>
const Node<T>* at(Node<T>* head, std::size_t index)
{
   for (std::size_t i = 0; head != nullptr && i < index; ++i)
   {
      head = head->next();
   }
   return head;
}



template <typename T>
void print_list(Node<T>* head)
{
    size_t index=0;
    for(auto finger = head; finger!=nullptr; finger = finger->next())
    {
        cout << "Node " << index << "'s data: " << finger->data() << endl;
        index++;
    }
    cout << endl;
}


template <typename T>
size_t length(Node<T>* head)
{
    size_t count=0;
    for(auto finger = head; finger != nullptr; finger = finger->next()) count++;
    return count;
}


template <typename T>
size_t length_r(Node<T>* head)
{
    if(head == nullptr) return 0;
    return length_r(head->next())+1;
}


template <typename T>
Node<T>* pop_front(Node<T>* head)
{
    if(head == nullptr) return nullptr;
    Node<T>* temp = head->next();
    delete head;
    return temp;
}


template <typename T>
Node<T>* clear_list(Node<T>* head)
{
   while(head != nullptr)
   {
       head = pop_front(head);
   }
   return head;
}


template <typename T>
Node<T>* copy_list(Node<T>* head)
{
    auto newhead = new Node<T>(head->data(),head->next());
    auto finger = head->next();
    while(finger != nullptr)
    {
        newhead = push_front(head->data(),head);
        finger= finger->next();
    }
    return newhead;

}

}

#endif // NODE_H
