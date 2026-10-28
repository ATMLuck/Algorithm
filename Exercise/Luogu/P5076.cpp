#include <set>
#include <iostream>
using namespace std;
int main()
{
    int q;
    cin >> q;
    multiset<int> arr;
    arr.insert(-2147483647);
    arr.insert(2147483647);
    while(q--)
    {
        int op,x;
        cin >> op >> x;
        switch(op)
        {
        case 1:
        {
            auto p = arr.lower_bound(x);
            int order = 0;
            for(auto b = arr.begin();b!=p;b++) order++;
            cout << order << '\n';
            break;
        }
        case 2:
        {
            auto b = arr.begin();
            while(x--) b++;
            cout << *b << '\n';
            break;
        }
        case 3:
        {
            auto p = arr.lower_bound(x);
            cout << *--p << '\n';
            break;
        }
        case 4:
        {
            auto p = arr.upper_bound(x);
            cout << *p << '\n';
            break;
        }
        case 5:
        {
            arr.insert(x);
            break;
        }
        }
    }
    return 0;
}