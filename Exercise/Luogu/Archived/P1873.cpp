#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using LL=long long;
int main()
{
    LL N,M;
    cin >> N >> M;
    vector<LL> arr(N);
    for(LL i = 0;i<N;i++) cin >> arr[i];
    sort(arr.begin(),arr.end());

    LL ans_R = arr[N-1],ans_L = 0;
    LL ans_mid = (ans_R+ans_L)/2;
    LL ans = 0;
    
    while(ans_R>=ans_L)
    {
        ans_mid = (ans_R+ans_L)/2;
        LL long_M = 0;
        for(LL vir : arr)
        {
            if(vir>ans_mid) long_M += vir-ans_mid;
        }
        if(long_M>=M) 
        {
            ans = ans_mid;
            ans_L = ans_mid+1;
        }
        else
        {
            ans_R = ans_mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}
