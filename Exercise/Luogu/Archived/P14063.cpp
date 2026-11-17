#include "bits/stdc++.h"
using namespace std;
int main()
{
    long long n,b;
    cin >> n >> b;
    vector<long long> arr(n);
    for(long long i = 0;i<n;i++) cin >> arr[i];
    long long L = 0,R = 0,ans = 0,sum = 0;
    while(R<n)
    {
        if(sum<=b)
        {
            sum+=arr[R];
            R++;
        }
        else
        {
            sum-=arr[L];
            L++;
        }
        if(sum<=b) ans = max(R-L,ans);
    }
    cout << ans << endl;
    return 0;
}