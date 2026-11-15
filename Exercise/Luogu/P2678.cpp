#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(vector<int> &arr, int n, int m, int k)
{
    int num = 0,vir = 0;
    for(int i = 1;i<=n+1;i++)
    {
        if(arr[i]-arr[vir]<k) num++;
        else vir = i;
    }
    if(num>m) return false;
    else return true;

}
int main()
{
    int l,n,m;
    cin >> l >> n >> m;
    vector<int> arr(n+2,0);
    for(int i = 1;i<=n;i++) cin >> arr[i];
    arr[n+1] = l;
    int L = 0,R = l;
    int ans = -1;
    while(R>=L)
    {
        int mid = (L+R)/2;
        if(check(arr,n,m,mid))
        {
            ans = mid;
            L = mid+1;
        }
        else
        {
            R=mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}