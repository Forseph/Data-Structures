#include "queue.h"


int main()  // Showing functionality of the queue class
{
    std::queue<int> line;

    for(int i=0;i<10;i++)
    {
        line.push(i);
    }
    print_queue(line);


    auto sum=0;
    auto size = line.size();

    while(!line.empty() && sum < size)
    {
        sum += line.front();
        line.pop();
    }

    std::cout << "\nSUM: " << sum << std::endl;
    std::cout << std::endl;
    print_queue(line);

    return 0;
}

