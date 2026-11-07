#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int work(vector<int> &arr, int &L, int &R)
{
    int ma = arr[L], pa = arr[L], p;
    for(int i = L+1;i<=R;i++)
    {
        pa+=arr[i];
        if(pa==0) {p = i;break;}
        ma = min(ma,pa);
    }
    arr[L]-=ma;
    arr[p]+=ma;
    while(arr[L]==0&&L!=R) L++;
    while(arr[R]==0&&L!=R) R--;
    return ma;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n+1,0);
    for(int i = 0;i<n;i++) cin >> arr[i];
    for(int i = n;i>0;i--) arr[i]-=arr[i-1];
    int L = [&]()->int{for(int i = 0;i<=n;i++) if(arr[i]!=0) return i;return -1;}();
    int R=[&]()->int{for(int i = n;i>=0;i--) if(arr[i]!=0) return i;return -1;}();
    int ans = 0;
    while(L!=R) ans+=work(arr,L,R);
    cout << ans << endl;
    return 0;
}