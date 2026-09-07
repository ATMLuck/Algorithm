#include "iostream"
#include "vector"
#include "cmath"
#include <climits>
using LL = long long;
using namespace std;
int main()
{
    int n;
    cin >>n;
    vector<LL> arr(n),brr(n);
    for(int i = 0;i<n;i++) cin >>arr[i];
    brr[0] = arr[0];
    for(int i = 1;i<n;i++)
    {
        LL mi = LONG_LONG_MAX;
        for(int j = 0;j<i;j++) mi = abs(arr[i]-arr[j])<mi?abs(arr[i]-arr[j]):mi;
        brr[i] = mi;
    }
    LL ans = 0;
    for(LL a:brr) ans += a;
    cout << ans << endl;
}