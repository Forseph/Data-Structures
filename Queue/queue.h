#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

namespace std
{
template<typename T>
class queue: public Node<T>
{
private:
    Node<T>* head_ptr;
    Node<T>* tail_ptr;
    size_t count_;
public:
    queue();
    queue(const queue<T>& line);
    ~queue(){clear_list(head_ptr);}

    void push(const T& data);
    void pop();
    bool empty(){return(count_ == 0);}

    //queue operator =(queue<T> line){return copy_queue(line);}
    size_t size(){return count_;}
    queue<T> copy_queue(queue<T> line);
    T front(){return head_ptr->data();}
    Node<T>* front_node(){return head_ptr;}

};

template <typename T>
queue<T>::queue()
{
    count_=0;
    head_ptr=nullptr;
}

template <typename T>
void queue<T>::pop()
{
    head_ptr = pop_front(head_ptr);
    count_--;
}

template <typename T>
void queue<T>::push(const T &data)
{
    if(empty())
    {
        head_ptr = push_back(data,head_ptr);
        tail_ptr = head_ptr;
    }
    if(!empty())
    {
        tail_ptr = push_back(data,head_ptr);
    }

    count_++;
}

template <typename T>
queue<T> queue<T>::copy_queue(queue<T> line)
{
    queue<T> new_queue;
    while(!line.empty())
    {
        new_queue.push(line.front());
        line.pop();
    }
    return new_queue;
}


template <typename T>
void print_queue(queue<T>& source)
{
    cout << "Printing queue: \n";
    Node<T>* temp = source.front_node();
    while(temp != nullptr)
    {
        cout << temp->data() << endl;
        temp = temp->next();
    }

}

}
#endif // QUEUE_H
