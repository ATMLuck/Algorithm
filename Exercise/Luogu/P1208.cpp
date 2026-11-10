#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ULL=unsigned long long;
struct T
{
    int value;
    int sum;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<T> arr(m);
    for(int i = 0;i<m;i++)
        cin >> arr[i].value >> arr[i].sum;
    sort(arr.begin(),arr.end(),[](T a, T b)->bool{return a.value<b.value;});
    ULL ans = 0;
    for(auto vir:arr)
    {
        if(n>=vir.sum)
        {
            n-=vir.sum;
            ans+=vir.sum*vir.value;
        }
        else
        {
            ans+=n*vir.value;
            n=0;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}