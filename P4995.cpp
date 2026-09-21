#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using LL=long long;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n+1,0);
    for(int i = 1;i<=n;i++) cin >> arr[i];
    sort(arr.begin()+1,arr.end());
    int L=1,R=n,k=1,vir=0;
    LL ans=0;
    while(L!=R)
    {
        if(k) 
        {
            ans+=(arr[vir]-arr[R])*(arr[vir]-arr[R]);
            vir = R;
            R--;
        }
        else 
        {
            ans+=(arr[vir]-arr[L])*(arr[vir]-arr[L]);
            vir=L;
            L++;
        }
        k^=1;
    }
    ans+=(arr[vir]-arr[R])*(arr[vir]-arr[R]);
    cout << ans << endl;
    return 0;
}
