#include "node.h"

namespace std
{
void print_list(Node* head)
{
    size_t index=0;
    for(auto finger = head; finger !=nullptr; finger = finger->next())
    {
        cout << "Node " << index << "'s data: " << finger->data() << endl;
        index++;
    }
}

size_t length(Node* head)
{
    size_t count=0;
    for(auto finger = head; finger != nullptr; finger = finger->next()) count++;
    return count;
}

size_t length_r(Node* head)
{
    if(head == nullptr) return 0;
    return length_r(head->next())+1;
}

Node* push_front(int data, Node* head)
{
    Node* newnode = new Node(data, nullptr);
    newnode->next(head);
    return  newnode;
}

Node* pop_front(Node* head)
{
    if(head == nullptr) return nullptr;
    Node* temp = head->next();
    delete head;
    return temp;
}

Node* clear_list(Node* head)
{
   while(head != nullptr)
   {
       head = pop_front(head);
   }
   return head;
}

Node* copy_list(Node* head)
{
    auto newhead = new Node(head->data(),head->next());
    auto finger = head->next();
    while(finger != nullptr)
    {
        newhead = push_front(head->data(),head);
        finger= finger->next();
    }
    return newhead;

}

}

