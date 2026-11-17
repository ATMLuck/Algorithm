#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
int main()
{
    LL n,x;
    scanf("%lld %lld",&n,&x);
    vector<LL> arr(n);
    for(LL i = 0;i<n;i++) scanf("%lld",&arr[i]);
    LL ans = 0;
    for(LL i = 1;i<n;i++) 
    {
        LL tmp = x-arr[i-1]-arr[i];
        if(tmp<0) 
        {
            arr[i] += tmp;
            ans -= tmp;
        }
        if(arr[i]<0)
        {
            arr[i-1]-=0-arr[i];
            arr[i] = 0;
        }
    }
    printf("%lld",ans);
    return 0;
}