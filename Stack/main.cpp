#include "node.h"
#include "stack"

using namespace std;

int main()
{
    stack<int> list;
    for(int i=10;i>=0;i--)
    {
        list.push(i);
    }

    while(!list.empty())
    {
        cout << list.top() << endl;
        list.pop();
    }

    return 0;


}
