#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n+1,0);
    for(int i = 1;i<=n;i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    int L=0,R=n,k=1;
    int ans=0;
    while(L!=R)
    {
        ans+=(arr[R]-arr[L])*(arr[R]-arr[L]);
        if(k) R--;
        else L++;
        k^=1;
    }
    cout << ans << endl;
    return 0;
}
/*
3
6 3 5
49
*/