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

    for (auto p = b.begin(); p != b.end(); ++p)
    {
        cout << *p << endl;
    }
    
    List<const char*>s;
    const char *s1 = "hello", *s2 = "world";
    s.push_back(s1);
    s.push_back(s2);

    for (auto p = s.begin(); p != s.end(); p++)
    {
        cout << *p;
    }
    
    return 0;
}
