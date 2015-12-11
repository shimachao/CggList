#include <iostream>
#include "cgglist.h"

using std::cout;
using std::endl;
using cgg::List;

int main()
{
    List<int> b;
    for (int i = 0; i < 5; i++)
    {
        b.push_back(i);
    }
    
    while (!b.empty())
    {
        cout << b.front() << endl;
        b.pop_front();
    }

    for (int i = 5; i < 10; i++)
    {
        b.push_front(i);
    }

    while (!b.empty())
    {
        cout << b.back() << endl;
        b.pop_front();
    }

    return 0;
}
