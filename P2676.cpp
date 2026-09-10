#include "iostream"
#include "vector"
#include "algorithm"
#include "functional"
#include <functional>
using LL = long long;
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    vector<LL> arr(n);
    for(int i = 0;i<n;i++) cin >> arr[i];
    sort(arr.begin(),arr.end(),greater<LL>());
    for(int i = 0;i<n;i++)
    {
        if(i!=0) arr[i] = arr[i] + arr[i-1];
        if(arr[i]>=m)
        {
            cout << i+1 << endl;
            break;
        }
    }
    return 0;
}