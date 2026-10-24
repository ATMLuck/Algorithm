#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    int sum = 0,ans = INT_MAX;
    int l = 0,r = 0;
    for(int i = 0;i<m;i++)
    {
        sum+=arr[r];
        r++;
    }
    ans = min(ans,sum);
    while(r<n)
    {
        sum+=arr[r];
        r++;
        sum-=arr[l];
        l++;
        ans = min(ans,sum);
    }
    cout << ans << endl;
    return 0;
}