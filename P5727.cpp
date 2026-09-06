#include "iostream"
#include "stack"
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<int> arr;
    arr.push(n);
    while(n!=1)
    {
        if(n&1) n = n*3+1;
        else n/=2;
        arr.push(n);
    }
    while(!arr.empty())
    {
        cout << arr.top() << ' ';
        arr.pop();
    }
    cout << '\n';
    return 0;
}