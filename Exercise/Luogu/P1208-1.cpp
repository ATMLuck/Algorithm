#include <iostream>
using namespace std;
using ULL=unsigned long long;
int main()
{
    ULL n,m;
    cin >> n >> m;
    ULL arr[1001] = {0};
    for(ULL i = 0;i<m;i++)
    {
        ULL a,b;
        cin >> a >> b;
        arr[a]+=b;
    }
    ULL ans = 0;
    for(ULL i = 0;i<1001;i++)
    {
        if(!arr[i]||n<=0) continue;
        if(n>=arr[i])
        {
            n-=arr[i];
            ans+=arr[i]*i;
        }
        else
        {
            ans+=n*i;
            n=0;
        }
    }
    cout << ans << endl;
    return 0;
}