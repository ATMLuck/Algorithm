#include <iostream>
using namespace std;
unsigned long long floor(int n)
{
    if(n<=1) return 1;
    return n*floor(n-1);
}
int main()
{
    int n;
    cin >> n;
    cout << floor(n) << endl;
}