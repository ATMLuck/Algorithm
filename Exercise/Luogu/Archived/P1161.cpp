#include <iostream>
using namespace std;
int main()
{
    int n,b;
    double a;
    cin >> n >> a >> b;
    int ans = (int)(a*b);
    while(--b) ans^= (int)(a*b);
    while(--n)
    {
        cin >> a >> b;
        ans^= (int)(a*b);
        while(--b) ans^= (int)(a*b);
    }
    cout << ans << endl;
    return 0;
}