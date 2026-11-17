#include <iostream>
#include <vector>
#include <algorithm>
using LL=long long;
using namespace std;
int Left_half(vector<LL> &arr,int L,int R,int num,int c)
{
    int mid = (L+R)/2;
    while(L<=R)
    {
        mid = (L+R)/2;
        if(arr[mid]-num>=c)
        {
            R=mid-1;
        }
        else
        {
            L=mid+1;
        }
    }
    return L;
}
int Right_half(vector<LL> &arr,int L,int R,int num,int c)
{
    int mid = (L+R)/2;
    while(L<=R)
    {
        mid = (L+R)/2;
        if(arr[mid]-num<=c)
        {
            L=mid+1;
        }
        else
        {
            R=mid-1;
        }
    }
    return R;
}
int half(vector<LL> &arr,int L,int R,int num,int c)
{
    return Right_half(arr,L,R,num,c)-Left_half(arr,L,R,num,c)+1;
}

int main()
{
    int n;
    LL c;
    cin >> n >> c;
    vector<LL> arr(n);
    LL ans = 0;
    for(int i = 0;i<n;i++) cin >> arr[i];
    sort(arr.begin(),arr.end());
    for(int i = 0;i<n;i++) ans+=half(arr,i+1,n-1,arr[i],c);
    cout << ans << endl;
    return 0;
}