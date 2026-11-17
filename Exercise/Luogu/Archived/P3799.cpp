#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    long long ans = 0;
    cin >> n;
    int arr[5005] = {0};
    for(int i=0; i<n; i++)
    {
        int data;
        cin >> data;
        arr[data]++;
    }
    for(int i=5004; i>0; i--)
    {
        if(arr[i]>1)
        {
            int base = arr[i]*(arr[i]-1)/2;
            int l = 1,r = i-1;
            while(l<=r)
            {
                if(arr[l]&&arr[r])
                {
                    if(l!=r) ans+=base*arr[l]%MOD*arr[r]%MOD;
                    else ans+=base*(arr[l]*(arr[l]-1)/2)%MOD;
                    ans%=MOD;
                }
                l++;
                r--;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}