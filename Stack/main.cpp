#include "stack.h"


using namespace std;

int main()
{

    stack<int> list;

    for(int i=0;i<10;i++) list.push(i);

    print_stack(list);


    size_t i =0;
    size_t j = list.size();
    while(i<j)
    {
        cout << list.top()->data() << " <- data" << endl;

        list.pop();
        i++;
    }
    return 0;
}
