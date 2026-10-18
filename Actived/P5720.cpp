#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    while(n)
    {
        ans++;
        n=n>>1;
    }
    cout << ans << endl;
    return 0;
}