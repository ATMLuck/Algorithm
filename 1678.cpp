#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
int half_find(const vector<int> &arr,int vir)
{
    int ans = 1<<30;
    int L=0;
    int R=(int)arr.size()-1;
    while(L<=R)
    {
        int mid = (L+R)/2;
        int temp = arr[mid]-vir;
        if(abs(temp)) ans = min(ans,abs(temp));
        if(temp>0) R=mid-1;
        else if(temp<0) L=mid+1;
        else
        {
            ans = 0;
            break;
        }
    }
    return ans;
}
int main()
{

    int n,m;
    cin >> n >> m;
    vector<int> arr(n),brr(m);
    for(int &a:arr) cin >> a;
    for(int &a:brr) cin >> a;
    sort(arr.begin(),arr.end());
    long long ans = 0L;
    for(int i:brr) ans+=half_find(arr, i);
    cout << ans << endl;
    return 0;
}